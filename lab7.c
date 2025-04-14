//
// Author: Peter Ma
//
#include <string.h>
#include <stdio.h>

#define NO_TILE 'U'
#define WHITE 'W'
#define BLACK 'B'

void printBoard(char board[][26], int n) {
  
  // first line
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

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
    
  char midColour = (colour == WHITE) ? BLACK : WHITE;
  char endColour = colour;

  if (!positionInBounds(n, row + deltaRow, col + deltaCol) || board[row + deltaRow][col + deltaCol] == endColour || board[row + deltaRow][col + deltaCol] == NO_TILE)
    return false;
  
  while (positionInBounds(n, row + deltaRow, col + deltaCol) && board[row + deltaRow][col + deltaCol] == midColour) {
    row += deltaRow;
    col += deltaCol;
  }

  if (positionInBounds(n, row + deltaRow, col + deltaCol) && board[row + deltaRow][col + deltaCol] == endColour)
    return true;

  return false;
}

bool checkLegal(char board[][26], int n, int row, int col, char colour) {

  bool isLegal = false;

  for (int deltaRow = -1; deltaRow < 2; deltaRow++) {
    for (int deltaCol = -1; deltaCol < 2; deltaCol++) {
      if (!(deltaRow == 0 && deltaCol == 0)) {
        isLegal = isLegal || checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol);
      }
    }
  }
  return isLegal;

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

void configBoard(char board[][26], int n) {
  printf("Enter board configuration:\n");
  char boardConfig[10];
  scanf("%s", boardConfig);
  while (strcmp(boardConfig, "!!!") != 0) {
    // "Bcd"
    char colour = boardConfig[0];
    int row = boardConfig[1] - 'a';
    int col = boardConfig[2] - 'a';
    board[row][col] = colour;
    scanf("%s", boardConfig);
  }
}

void printLegalMove(char board[][26], int n, char colour) {
  printf("Available moves for %c:\n", colour);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <n; j++) {
      if (board[i][j] == NO_TILE) {
        if (checkLegal(board, n, i, j, colour))
          printf("%c%c\n", 'a' + i, 'a' + j);
      }
    }
  }  
}

void flipTiles(char board[][26], int n, int row, int col, char colour) {
  char midColour = (colour == WHITE) ? BLACK : WHITE;
  char endColour = colour;

  for (int deltaRow = -1; deltaRow < 2; deltaRow++) {
    for (int deltaCol = -1; deltaCol < 2; deltaCol++) {
      if (!(deltaRow == 0 && deltaCol == 0)) {
        if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) {
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

void makeOneMove(char board[][26], int n) {
  printf("Enter a move:\n");
  char oneMove[10];
  scanf("%s", oneMove);
  int row = oneMove[1] - 'a';
  int col = oneMove[2] - 'a';
  char colour = oneMove[0];

  if (checkLegal(board, n, row, col, colour) && positionInBounds(n, row, col) && board[row][col] == NO_TILE) {
    printf("Valid move.\n");
    flipTiles(board, n, row, col, colour);
    board[row][col] = colour;
  } else
    printf("Invalid move.\n");
}

int main(void) {
  int n;
  printf("Enter the board dimension: ");
  scanf("%d", &n);

  // initiate the board
  char board[26][26];
  initiateBoard(board, n);

  printBoard(board, n);

  configBoard(board, n);

  printBoard(board, n);
  
  printLegalMove(board, n, WHITE);
  
  printLegalMove(board, n, BLACK);

  makeOneMove(board, n);
  printBoard(board, n);

  return 0;
}