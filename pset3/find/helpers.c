/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    for (int i = 0; i < n ; i++)
    {
        int min = 0;
        int max = n - 1;
        while (min <= max) 
        {
            int midpoint =  (max + min) / 2;
 
            if (values[midpoint] > value)
            {

                max = midpoint - 1 ;

}  
else if (values[midpoint] < value)
            {

                min = midpoint + 1;
}
else 
                return true;

}
}
    return false;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i=0; i < n; i++)
    {
        for (int i=0; i < (n - 1); i++)
        {
            int min = i;
            for (int j=i + 1; j < n; j++)
            {
                if (values[min] > values[j])
                {
                    min = j;
}
}
            if (min != i )
            {
                int swap = values[i];
                values[i] = values[min];
                values[min] = swap;
}
}
}
    
}




