// Developed by Peter Ma
// Date: Jan 14, 2022
// Description: This is a program that convert from inch to yard,feet, and inches 

#include <stdio.h>

int main() {
    double a;
    double Nummtoinch;
    int Numyards;
    int Numfeet;
    int Numinches;
    int integer;
    double Numinchrem;
    printf("Please provide a distance in metres: ");
    scanf("%lf", &a);
    // Nummtoinch is unit calculation 
    Nummtoinch =(a*100)/2.54;
    integer = Nummtoinch;
    // Numyards unit covert from inches to yards 
    Numyards =Nummtoinch/36;
    Numfeet =(Nummtoinch/36 - Numyards)*3;
    Numinches = ((Nummtoinch/36 - Numyards)*3) - Numfeet;
    Numinchrem = Nummtoinch - integer;
    printf("%d yards, %d feet, %d inches, and %.2lf inches remainder",Numyards,Numfeet,Numinches,Numinchrem);
    return 0;
}


