// Developed by Peter Ma
// Date: Jan 27, 2022
// Description: This is a program to test the Substance test 

#include <stdio.h>

int main (){
    int Threshold; // Number of the Threshold in Celsius.
    int ObservedBoilingPoint; // Number of the observed boiling point in Celsius.
    
    // This are the Substance and their normal boiling points.
    int Water = 100;
    int Mercury = 357;
    int Copper = 1187;
    int Sliver = 2193;
    int Gold = 2660;

    printf("Enter the threshold in Celsius: ");
    scanf("%d", &Threshold);
    printf("Enter the observed boiling point in Celsius: ");
    scanf("%d", &ObservedBoilingPoint);

    if (Water-Threshold<= ObservedBoilingPoint && Water+Threshold>= ObservedBoilingPoint) // This is the caluation to test the Observed boiling point of Water is in the range of the Water. 
    {
        printf("The substance you tested is: Water");
    }
    else if (Mercury-Threshold<= ObservedBoilingPoint && Mercury+Threshold>= ObservedBoilingPoint)// This is the caluation to test the Observed boiling point of Mercury is in the range of the Mercury. 
    {
        printf("The substance you tested is: Mercury");
    }
    else if (Copper-Threshold<= ObservedBoilingPoint && Copper+Threshold>= ObservedBoilingPoint)// This is the caluation to test the Observed boiling point of Copper is in the range of the Copper. 
    {
        printf("The substance you tested is: Copper");
    }
    else if (Sliver-Threshold<= ObservedBoilingPoint && Sliver+Threshold>= ObservedBoilingPoint)// This is the caluation to test the Observed boiling point of Silver is in the range of the Silver. 
    {
        printf("The substance you tested is: Silver");
    }
    else if (Gold-Threshold<= ObservedBoilingPoint && Gold+Threshold>= ObservedBoilingPoint)// This is the caluation to test the Observed boiling point of Gold is in the range of the Gold. 
    {
        printf("The substance you tested is: Gold");
    }
    else
    {
        printf("Substance unknown.");
    }

    return 0;
}
