/**
mario.c

Dawid Poliszak
dawidpoliszak@gmail.com
*/
#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int height=0;
    do 
    {
    // declare height of a pyramid
        printf( "Please, enter a number: " );
        height = GetInt(); 
    }
    while (height >= 24 || height < 0); 
    for (int i = 0; i < height; i++)
    {
    // making spaces
        for (int j = 0; j < height - (i + 1); j++)
        {
            printf(" ");
     }
     // making hashes
        for (int k = 0; k < (i + 2); k++)
        {
            printf("#");
     }
     // next lane
        printf("\n");
     }
    return 0;   
}

