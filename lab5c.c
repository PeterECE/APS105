// Developed by Peter Ma
// Date: Feb 17, 2022
// Description: This is a program to find the longest common sequence

#include <stdio.h>

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB){
     int i = 0; int length = 0; int start = 0; // find two array same number 
     for(i = 0; i < sizeA; i ++){
          int j = 0;
          for(j = 0; j < sizeB; j ++){
               int m = 1;
               if(firstArr[i] == secondArr[j]){
                    while(i + m < sizeA && j + m < sizeB && (firstArr[i + m] == secondArr[j + m])){
                         m ++; // to count how many same number 
                    }
               }
               if(m > length){
                    length = m - 1;
                    start = i;
               }
          }
     }
     // find result 
     printf("Longest Common Sequence is ");
     for(i = 0; i < length; i ++){
          printf("%d, ",firstArr[start+i]);
     }
     printf("%d.",firstArr[start+length]);
} 
