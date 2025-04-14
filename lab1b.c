// Developed by Peter Ma
// Date: Jan 14, 2022
// Description: This is a program about car rental fees calculation 

#include <stdio.h>

int main() {
    double a;
    int b;
    int totalD;
    int freeDays;
    double totalC;
    printf("Enter the daily rate: ");
    scanf("%lf", &a);
    printf("Enter the rental period (in days): \n");
    scanf("%d", &b);
    // freeDays means how many free day we got 
    freeDays = b/4;
    // totallD means how many day we need to pay 
    totalD = freeDays*3;
    // total money we have to pay 
    totalC = (totalD*a+a*(b%4))*1.13;
    printf("Your total free day(s) in this rental is: %d\nYour total charge including taxes is: %.2lf\n",freeDays,totalC);
    return 0;
}
