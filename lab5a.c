// Developed by Peter Ma
// Date: Feb 17, 2022
// Description: This is a program about calculate median number in two sorted 

#include <stdio.h>

double median(int a[], int b[], int sizeA, int sizeB){
//TODO: Implement this function 
int m = 0, n = 0;
int ab[sizeA + sizeB]; // put two array in one array
int i = 0;

// after in one array find least to greatest
for(i = 0; i < sizeA + sizeB; i++){
     // find the different size of array 
     if(m == sizeA){         
          ab[i] = b[n]; n ++;
          continue;
     }
     if(n == sizeB){
          ab[i] = a[m]; m ++;
          continue;
     }
     if(a[m] < b[n]){
          ab[i] = a[m]; m ++;
     }
     else{
          ab[i] = b[n]; n ++;
     }
}
// calculate the median number 
if((sizeA + sizeB) % 2 == 0){
     return (ab[(sizeA + sizeB)/2 - 1] + ab[(sizeA + sizeB)/2])/2.0;
}
else{
     return ab[(sizeA + sizeB)/2];
}
}
