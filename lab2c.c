// Developed by Peter Ma
// Date: Jan 17, 2022
// Description: This is a program that calculate arrival time 

#include <stdio.h>

int main(){
    int numinhour;
    int numinmins;
    int hourtomins;
    int minstohour;
    int minsadd;
    int addhour;
    int addmins;
    int Arrivalhour;
    int Arrivalnextdayhour;
    double triptime;
    
    
    printf("Enter current time: ");
    scanf("%d  %d",&numinhour,&numinmins);
    
    printf("Enter trip time: \n");
    scanf("%lf", &triptime);

    hourtomins = triptime*60;
    minstohour = hourtomins/60;
    minsadd = hourtomins%60;
    addhour = (minsadd+numinmins)/60;
    addmins = (minsadd+numinmins)%60;
    Arrivalhour = numinhour+minstohour+addhour;
    Arrivalnextdayhour = Arrivalhour-24;

    if (numinhour<9 && numinmins<9)
    {
        printf("Current time is 0%d:0%d\n",numinhour,numinmins);
    }
    else if (numinhour>9 && numinmins<9)
    {
         printf("Current time is %d:0%d\n",numinhour,numinmins);
    }
   else if (numinhour>9 && numinmins>9)
   {
       printf("Current time is %d:%d\n",numinhour,numinmins);
   }
   else if (numinhour<9 && numinmins>9)
   {
       printf("Current time is 0%d:%d\n",numinhour,numinmins);
   }

    if (Arrivalhour<24 && addmins<=9)
    {
        printf("Arrival Time is same day %d:0%d",Arrivalhour,addmins);
    }
    else if (Arrivalhour<24 && addmins>9)
    {
        printf("Arrival Time is same day %d:%d",Arrivalhour,addmins);
    }
    else if (Arrivalhour>24 && addmins<=9)
    {
        if (Arrivalnextdayhour>9)
        {
             printf("Arrival Time is next day %d:0%d",Arrivalnextdayhour,addmins);
        }
    }   
    else if (Arrivalhour>24 && addmins>9)
    {
     if (Arrivalnextdayhour<9)
        {
             printf("Arrival Time is next day 0%d:%d",Arrivalnextdayhour,addmins);
        }
    }


    return 0;
}
