// Developed by Peter Ma
// Date: Jan 26, 2022
// Description: This is a program about create triangle 

#include <stdio.h>

int main(){
    int rows, numberofrows, columns; // set row, column, and number of rows we need 

    printf("Enter the number of rows in the triangle: ");
    scanf("%d", &numberofrows);

    for(rows = 1; rows <= numberofrows; rows++) // This sentence means how many rows we have in the triangle. 
    {
        for(columns = (rows + 1); columns <= numberofrows; columns++) // This sentence means that the space we have for the triangle outside.  
        {
            printf(" ");
        }
        for(columns = 1; columns <= 2 * rows - 1; columns++) // This sentence explain how many columnes we have in the triangle. 
        {
            if(rows == numberofrows || columns == 1 || columns == 2 * rows - 1)
            /* This if sentence explains that when the rows=numberofrows we have print a "*" This only apply to the last row of the triangle 
            colunms set to one which means the first star of the triangle
            column == 2*rows-1 is the last column 
             */
            {
                printf("*");
            }
            else
            {
                printf(" ");
            } 
        }
        printf("\n");
    }
    return 0;
}
