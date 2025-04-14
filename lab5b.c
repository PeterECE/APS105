// Developed by Peter Ma
// Date: Feb 17, 2022
// Description: This is a program to find the longest sequence of increase numbers

#include <stdio.h>

void longestSequence(int a[], int sizeA){
int i ; int length = 0; int start = 0;
//start sequence check with each number in array
for(i = 0; i < sizeA - 1 ; i ++){
     int j; int n = 0;
     // to cheack the number in the array 
     for(j = 1; j < sizeA - j; j ++){
          if(a[i + j] > a[i + j - 1]){
          n++;    
          }
          else{
          break;
          } 
     }
        if(n > length){
          start = i;
          length = n;  
        }    
        
    }
    //find the result 
    if(length > 1){
        int p;
        printf("Longest sequence is ");
        
        for(p = 0; p < length; p ++){
          printf("%d, ",a[start+p]);
        }
        printf("%d.",a[start+length]);
    }
    else{
        printf("Longest sequence is %d.",a[0]);
    }   
}
