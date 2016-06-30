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
    if ((argc < 2) || (argc > 2))
    {
        printf ("ERROR\n");
        return 1;
}
    int k = atoi(argv[1]);
    // declare string to coding
    string name;
    name = GetString();
    int  n = strlen(name);
    int nameNumber[strlen (name)];
    for (int i =0 ; i < n; i++)
    
    
    {
    // check whether declared string has letters or not
        if (isalpha(name[i]))
        {
    // check whether declared string has upperletters or not
            if (isupper(name[i]))
            {
    
                nameNumber[i] = (name[i] - 'A' + k) % 26 + 'A';
                }
     // check whether declared string has lowerletters or not
   else if (islower(name[i]))
            {
                nameNumber[i] = (name[i] - 'a' + k) % 26 + 'a';
      }
   }
   // check whether our phrase has characters other than letters
     else 
    
            nameNumber[i] = name[i] ;
    // print coded string
        printf("%c", nameNumber[i]);
 }
    printf("\n");
}
 

