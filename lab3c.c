// Developed by Peter Ma
// Date: Jan 25, 2022
// Description: This is a program about quarters,dims,nickles, and cents conversion program 

#include <stdio.h>

int main(){
    int numOfCents = 0; // numofcents is the number of cents we have in the beginning. 
    int afterNumOfCents = 0; //  afternumofcents is the number we have after conversion.
    int numOfNickels = 0; // numofnickles is the nickles we have after conversion. 
    int numOfDimes = 0; // numofdimes is the dimes we have after conversion.
    int afterNumOfDimes = 0; //  This is after dimes conversion what left for cents. 
    int numOfQuarters = 0; // numofquarteres is the quarters we have after conversion. 
    int afterNumOfQuarters = 0; // This is after quarters conversion what left for cents. 
    int whileCondition = 0;
    /* 
    conversion units calculation:
    1 quarter = 25 cents
    1 dimes = 10 cents
    1 nickel = 5 cents
    */

    while (whileCondition == 0){
         printf("Please give an amount in cents less than 100: ");
         scanf("%d", &numOfCents); 
         printf("%d cents: ", numOfCents);
         if (numOfCents <= 0 || numOfCents >99 ) {
              printf("invalid amount.");
              break;
        }
        // check condition
     numOfQuarters = numOfCents / 25; // calulation of how many quarters we have in cents.
     afterNumOfQuarters = numOfCents % 25; // calculation of how many we left cents after convert to quarters.
     numOfCents -= numOfQuarters * 25; // calculate if we need to have add another conditions. 
     int coinCount = 0;
     if (numOfQuarters > 0){
          printf("%d quarter", numOfQuarters);
          if(numOfQuarters >1)
          printf("s");
          coinCount++;
          if (numOfCents == 0)
          printf(".\n");
        }
     numOfDimes = afterNumOfQuarters / 10; // calulation of how many dims we have in cents.
     afterNumOfDimes = afterNumOfQuarters % 10;
     numOfCents -= numOfDimes * 10; // calculation of how many we left cents after convert to dimes.
     if (numOfDimes > 0){
          coinCount++;
          if (numOfCents == 0){
          if (coinCount == 2)
          printf(" and ");
          printf("%d dime", numOfDimes);
          if (numOfDimes > 1)
            printf("s");
            printf(".\n");  
          } else {
               if (coinCount > 1)
               printf(", ");
               printf("%d dime", numOfDimes);
               if (numOfDimes > 1)
               printf("s");
          }    
     }
     numOfNickels = afterNumOfDimes / 5; // calulation of how many nickels we have in cents.
     numOfCents -= numOfNickels * 5;
     if (numOfNickels > 0){
          coinCount ++;
          if (numOfCents == 0){
               if (coinCount > 2)
               printf(", and ");
               if (coinCount == 2)
               printf(" and ");
               printf("%d nickel", numOfNickels);
               if (numOfNickels > 1)
               printf("s");
               printf(".\n");
          } else {
              if (coinCount > 1)
              printf(", ");
              printf("%d nickel", numOfNickels);
              if (numOfNickels > 1)
              printf("s");
          }
     }
     afterNumOfCents = afterNumOfDimes % 5; // calculation of how many we left cents after convert to nickles.
     numOfCents -= afterNumOfCents * 1;
     if (afterNumOfCents > 0){
          coinCount ++;
          if (numOfCents == 0){
              if (coinCount == 2)
            printf(" and ");
            if (coinCount > 2)
               printf(", and ");
            printf("%d cent", afterNumOfCents);
            if (afterNumOfCents > 1)
            printf("s.\n");
            else{
                 printf(".\n");
            } 
          } 
     }
    } 
     return 0;
    }
