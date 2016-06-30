/**
initials.c

Dawid Poliszak
dawidpoliszak@gmail.com
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    string name;

    name = GetString();
    for (int i =0;name[i] != '\0';i++)
    {
        if (i == 0)
        {
            printf ("%c", toupper(name[i]));
 }
 else if (name[i] == ' ')
        {
            printf ("%c", toupper(name[i + 1]));
 
 }
 }
    printf ("\n");
}
