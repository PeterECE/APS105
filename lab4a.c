// Developed by Peter Ma
// Date: Feb 6, 2022
// Description: This is a program about Pascal's Triangle

#include <stdio.h>

int main(){
    int rows, numberOfRows, columns, count;
    int whileCondition = 0; 
    while (whileCondition == 0){
        printf("Enter the number of rows: ");
        scanf("%d", &numberOfRows);
        if (numberOfRows < 0 || numberOfRows > 13) {
            break;
        }
    for(rows = 0; rows < numberOfRows; rows++){ // This line print the rows of the number 
       for(columns = 1; columns < numberOfRows - rows; columns ++) // This sentence means that the space we have for the triangle outside.  
           printf("   ");
        for(columns = 0; columns <= rows ; columns++){
            if (rows == 0 || columns == 0) // This line print the number in the top 
            count = 1;
            else 
                count = count*(rows - columns + 1)/columns;
                printf("%d     ", count); // This line print the number of the line  
        } 
    printf("\n");
    } 
    }
return 0;
}       
