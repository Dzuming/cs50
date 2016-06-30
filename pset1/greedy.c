/**
greedy.c

Dawid Poliszak
dawidpoliszak@gmail.com
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float change=0;
    int ncoins = 0;
    do
    {
    // declare a rest
        printf( "How much change is owned: " );
        change = GetFloat();
    
    

        // convert change from float to int
        int rest = round(change * 100);
        // checking how many quaters we need
        if (rest > 25)
        {
            do
            {
                ncoins = rest / 25;
                rest = rest % 25;
}
while (rest >= 25);
}
        // checking how much dimes we need
        if (rest >= 10)
        {
            do
            { 
                ncoins = ncoins + (rest / 10);
                rest = rest % 10;
}
while(rest >= 25 && rest <= 10);
}
          // checking how much nickles we need
        if (rest >= 5)
        {
            do
            {
                ncoins = ncoins + (rest / 5);
                rest = rest % 5;
}
 while(rest >= 10 && rest <= 5); 
 }  
        // checking how much pennies we need
        if (rest >= 1)
        {
            do
            {
                ncoins = ncoins + (rest / 1);
 }
 while (rest >= 5 && rest <= 1);
 }
         // checking how much coins need
 
        (printf("%d\n", ncoins)); 
}
while (change < 0);
    return 0; 
}
