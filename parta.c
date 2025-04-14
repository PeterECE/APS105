//
// Author: Peter Ma
//

#include <string.h>
#include <stdio.h>
// #include <stdbool.h>

#define NO_TILE 'U'
#define WHITE 'W'
#define BLACK 'B'
#define DRAW 'D'

void printBoard(char board[][26], int n) {
  printf("  ");
  
  for (int i = 0; i < n; i++) {
    printf("%c", 'a' + i);
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("%c ", 'a' + i);
    for (int j = 0; j < n; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {
  return (row < n && col < n) ? true : false;
}

int numLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    
  char midColour = (colour == WHITE) ? BLACK : WHITE;
  char endColour = colour;
  int num = 0;

  if (!positionInBounds(n, row + deltaRow, col + deltaCol) || board[row + deltaRow][col + deltaCol] == endColour || board[row + deltaRow][col + deltaCol] == NO_TILE)
    return 0;
  
  while (positionInBounds(n, row + deltaRow, col + deltaCol) && board[row + deltaRow][col + deltaCol] == midColour) {
    row += deltaRow;
    col += deltaCol;
    num++;
  }

  if (positionInBounds(n, row + deltaRow, col + deltaCol) && board[row + deltaRow][col + deltaCol] == endColour)
    return num;

  return 0;
}

int numLegal(char board[][26], int n, int row, int col, char colour) {

  int sum = 0;

  for (int deltaRow = -1; deltaRow < 2; deltaRow++) {
    for (int deltaCol = -1; deltaCol < 2; deltaCol++) {
      if (!(deltaRow == 0 && deltaCol == 0)) {
        sum += numLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol);
      }
    }
  }
  return sum;

}

void initiateBoard(char board[][26], int n) {
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <n; j++) {
      if ((i == n / 2 - 1 && j == n / 2 - 1) || (i == n / 2 && j == n / 2))
        board[i][j] = WHITE;
      else if ((i == n / 2 - 1 && j == n / 2) || (i == n / 2 && j == n / 2 - 1))
        board[i][j] = BLACK;
      else
        board[i][j] = NO_TILE;
    }
  }
}

void flipTiles(char board[][26], int n, int row, int col, char colour) {
  char midColour = (colour == WHITE) ? BLACK : WHITE;
  char endColour = colour;
  int rowArchive = row, colArchive = col;

  for (int deltaRow = -1; deltaRow < 2; deltaRow++) {
    for (int deltaCol = -1; deltaCol < 2; deltaCol++) {
      if (!(deltaRow == 0 && deltaCol == 0)) {
        row = rowArchive;
        col = colArchive;
        if (numLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol) > 0) {
          while (board[row + deltaRow][col + deltaCol] == midColour) { 
            board[row + deltaRow][col + deltaCol] = colour;
            row += deltaRow;
            col += deltaCol;
          }
        }
      }
    }
  }
}

// Lab 8: initiate the game
void initiateGame(char board[][26], int *n, char *computer) {
  
  printf("Enter the board dimension: ");
  scanf("%d", n);

  printf("Computer plays (B/W): ");
  scanf(" %c", computer);

  initiateBoard(board, *n);

  printBoard(board, *n);
}

// Lab 8
bool isValidMoveLeft(char board[][26], int n, char turn) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <n; j++) {
      if (board[i][j] == NO_TILE) {
        if (numLegal(board, n, i, j, turn) > 0)
          return true;
      }
    }
  }
  return false;
}

bool humanMakeMove(char board[][26], int n, char turn) {
  printf("Enter move for colour %c (RowCol): ", turn);
  char oneMove[10];
  scanf("%s", oneMove);
  int row = oneMove[0] - 'a';
  int col = oneMove[1] - 'a';
  char colour = turn;

  if (numLegal(board, n, row, col, colour) > 0 && positionInBounds(n, row, col) && board[row][col] == NO_TILE) {
    flipTiles(board, n, row, col, colour);
    board[row][col] = colour;
    return true;
  } else
    return false;
}

int makeMove(char board[][26], int n, char turn, int *row, int *col) {

  *row = 0;
  *col = 0;
  int best = numLegal(board, n, *row, *col, turn);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == NO_TILE) {
        if (numLegal(board, n, i, j, turn) > best) {
            best = numLegal(board, n, i, j, turn);
            *row = i;
            *col = j;
        }
      }
    }
  }

  return 0;

}

void computerMakeMove(char board[][26], int n, char turn) {
  
  int bestRow = 0;
  int bestCol = 0;
  makeMove(board, n, turn, &bestRow, &bestCol);
  printf("Computer places %c at %c%c.\n", turn, 'a' + bestRow, 'a' + bestCol);
  flipTiles(board, n, bestRow, bestCol, turn);
  board[bestRow][bestCol] = turn;

}

char checkResult(char board[][26], int n) {

  int numBlack = 0;
  int numWhite = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == BLACK) {
        numBlack++;
      } else if (board[i][j] == WHITE) {
        numWhite++;
      }
    }
  }

  if (numBlack == numWhite)
    return DRAW;
  else if (numBlack > numWhite)
    return BLACK;
  else
    return WHITE;

}

void playGame(char board[][26], int n, char computer) {
  bool condition = true;
  char turn = BLACK;
  int numMove = 0;
  bool isHumanValid;

  /* The game ends when either:
    [+] the entire board is full
    [+] neither player has an available move
    [+] human makes an illegal move
  */
  
  while (condition) {
    
    if (computer == turn) {

      if (isValidMoveLeft(board, n, turn)) {
        computerMakeMove(board, n, turn);
        numMove++;
        printBoard(board, n);
      }
      else
        printf("%c player has no valid move.\n", turn);

    } else {
      if (isValidMoveLeft(board, n, turn)) {
        isHumanValid = humanMakeMove(board, n, turn);
        if (!isHumanValid) {
          printf("Invalid move.\n");
        } else {
          printBoard(board, n);
          numMove++;
        }
      }
      else
        printf("%c player has no valid move.\n", turn);
    }
    
    turn = (turn == BLACK) ? WHITE : BLACK;
    
    condition = isHumanValid && (numMove < n * n - 4) && (isValidMoveLeft(board, n, BLACK) || isValidMoveLeft(board, n, WHITE));
    
  }

  if (!isHumanValid) {
    printf("%c player wins.\n", computer);
    return;
  }

  char result = checkResult(board, n);
  if (result == DRAW)
    printf("Draw!");
  else
    printf("%c player wins.\n", result);

  
}

int main(void) {

  int n; 
  char computer;

  // initiate the board
  char board[26][26];

  initiateGame(board, &n, &computer);

  playGame(board, n, computer);
  

  return 0;
}
