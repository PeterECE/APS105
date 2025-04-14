#include <stdio.h>
#include <stdbool.h>

bool checkRow(int sudoko[][4], int Size, int rowNumber, int num){
     for(int i = 0; i < Size; i ++){
               if(Sudoko[rownumber][i] != num)
               return false;
          }
     }
}

bool checkCol(int sudoko[][4], int Size, int colNumber, int num){
     for(int j = 0; j < Size; j ++){
               if(sudoko[j][colNumber] != num)
               return false;
          }
     }  
}

void fillSudoko(const int Size, int sudoko[Size][Size]){
// print the 4x4 squre 
int checkRow, checkCol;
for(int row = 0; row < Size; row ++){
     for(int col = 0; col < Size; col ++){
          if(sudoko[row][col] == 0)

               if(checkRow (sudoko, row, col, num) && checkCol (sudoko, row, col, num));
                    sudoko[row][col] = num;
     }
 }
}   