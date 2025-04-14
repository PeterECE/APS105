#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printFoundLocation(int rowDir, int colDir) {

if (rowDir == 0 && colDir == -1){
     printf(" west direction.");
}
else if (rowDir == 0 && colDir == 1){
     printf(" east direction.");
}
else if (rowDir == -1){
     printf(" north direction.")
}
else if (rowDir == 1){
     printf(" south direction.")
}
}

bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir) {
int i = 1;
int rowindex = row + i * rowDir;
int colindex = col + i * colDir;
while (i < wordSize && rowindex >= 0 && rowindex < Size && colindex >= 0 && colindex < Size){
     if(word[i] == grid[rowindex][colindex]){
          i ++;
          rowindex = row + i * rowDir;
          colindex = col + i * colDir;
     }
     else{
          return false;
     }
}
     if(i == wordSize){
          return true;
     }
     return false;
}

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]) {
 int i, j;

  for (i = 0; i < Size; i++)
    {
      for (j = 0; j < Size; j++)
	{
	  if (word[0] == grid[i][j])
	    {
	     if (search1D (word, wordSize, Size, grid, i, j, 1, 0))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (1, 0);
		  return;
		}
	     else if (search1D (word, wordSize, Size, grid, i, j, 1, 1))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (1, 1);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, 0, 1))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (0, 1);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, -1, 1))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (-1, 1);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, -1, 0))
		{ 
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (-1, 0);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, -1, -1))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (-1, -1);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, 0, -1))
		{
		  printf ("333Word found at row %d and column %d in the", i, j);
		  printFoundLocation (0, -1);
		  return;
		}
          else if (search1D (word, wordSize, Size, grid, i, j, 1, -1))
		{
		  printf ("Word found at row %d and column %d in the", i, j);
		  printFoundLocation (1, -1);
		  return;
		}
          else{
               printf("Word not found.");
               return;
          }
	    }
	}
    }
}