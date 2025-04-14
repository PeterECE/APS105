// Developed by Peter Ma
// Date: Jan 17, 2022
// Description: This is a program that calculate your monthly iinstallment 

#include <stdio.h>
#include <math.h>

int main() {
    // int P is purchase price P(in dollars)
    int P;
    // int D is down payment
    int D;
    // int n is a finance term 
    int n;
    // double r is monthly interest rate 
    double r;
    double monthlypayment; 

    printf("Enter the purchase price P: ");
    scanf("%d", &P);
    printf("Enter the amount of down payment D: ");
    scanf("%d", &D);
    printf("Enter the finance term (in months): ");
    scanf("%d", &n);
    printf("Enter the monthly interest rate (in percent): ");
    scanf("%lf", &r);
    
    monthlypayment = ((P-D)*(r/100)*pow((1+(r/100)),n))/(pow((1+(r/100)),n)-1);
    printf("The monthly payment is: %.2lf",monthlypayment);

    return 0;
}
 
