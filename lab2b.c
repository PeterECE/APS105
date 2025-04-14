// Developed by Peter Ma
// Date: Jan 17, 2022
// Description: This is a program that diciphering code  

#include <stdio.h>
#include <math.h>

int main (){
    int fourcombination;
    int firstnum;
    int lastnum;
    int minnum;
    int twomid;
    int beforesec;
    int beforethrid;
    int secnum;
    int thirdnum;
    


    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &fourcombination);

    firstnum = fourcombination%10;
    lastnum = fourcombination/1000;
    minnum = fourcombination%1000;
    twomid = minnum/10;
    beforesec = twomid/10;
    beforethrid = twomid%10;
    secnum = 9-beforesec;
    thirdnum = 9-beforethrid;
    
    printf("The real combination is: %d%d%d%d",firstnum,secnum,thirdnum,lastnum);

    return 0;
}
