// Developed by Peter Ma// Date: Feb 7, 2022
// Description: This is a program about to find an Erodos-Woods Numbers

#include <stdio.h>

// The equation of the gcd function
int gcd(int a, int b)
{
     if (a == 0)
          return b;
     return gcd(b % a, a);
}
int main()
{
     int numOfStartK = 0; // number of start k
     int numOfStopK = 0;  // number of stop k
     int numOfStartA = 0; // number of start a
     int numOfStopA = 0;  // number of stop a

     do
     {
          printf("Enter the number to start searching for k (> 2, inclusive): ");
          scanf("%d", &numOfStartK);

     } while (numOfStartK <= 2);

     do
     {
          printf("Enter the number to stop searching for k (inclusive): ");
          scanf("%d", &numOfStopK);
     } while (numOfStopK <= numOfStartK);

     do
     {
          printf("Enter the number to start searching for a (> 0, inclusive): ");
          scanf("%d", &numOfStartA);
     } while (numOfStartA <= 0);

     do
     {
          printf("Enter the number to stop searching for a (inclusive): ");
          scanf("%d", &numOfStopA);
     } while (numOfStopA <= numOfStartA);

     while (numOfStartK <= numOfStopK)
     {
          printf("Trying k = %d...\n", numOfStartK);
          int a = numOfStartA;
          while (a <= numOfStopA)
          {
               int i;
               int function = 1;
               for (i = 1; i < numOfStartK; i++) // range of the i value 
               {
                    if (gcd(a, a + i) <= 1 && gcd(a + numOfStartK, a + i) <= 1)
                    {
                         function = 0;
                    }
               }
               if (function == 1)
               {
                    printf("Erdos-Woods number: %d\na = %d", numOfStartK, a);
                    return 0;
               }
               a++;
          }
          numOfStartK++;
     }
     printf("Erdos-Woods number not found.");
     return 0;
}
