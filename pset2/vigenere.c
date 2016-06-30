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
    if ((argc < 2) || (argc > 2)  )
    {
        printf ("ERROR\n");
        return 1;
}
    char* code ;
    code = argv[1];
    int codeLen  =strlen (code);
   
    for (int i =0;i < codeLen;  i++)
    {
        if ( isalpha( code[i]) == false)
        {
            printf ("ERROR\n");
            return 1;
   }
      
      
    }
    string name;
    name = GetString();
    int nameLen = strlen(name);
    
    
    int codeUpper = 0;
    int codeLower = 0;
    
    
   
 
 
   
    // declare string to coding
   
    int encrypt[strlen (name)];
    
    for (int i =0, j = 0; i < nameLen; i++)
    
    
    {
    
    // check whether declared string has letters or not
        if (isalpha(name[i]))
        {
    // check whether declared string has upperletters or not
            if (isupper(name[i]))
            {
                codeUpper = toupper(code[j]);
                if (isupper(codeUpper))
                {
                    int start = (codeUpper - 'A');
                    encrypt[i] = (name[i] - 'A' + start) % 26 + 'A';
                    j++;
                }
                }
               
     // check whether declared string has lowerletters or not
   else if (islower(name[i]))
            {
                codeLower = tolower(code[j]);
                if (islower(codeLower))
                {
                    int start = (codeLower - 'a');
                    encrypt[i] = (name[i] - 'a' + start) % 26 + 'a';
                    j++;
                }
              
      }
   }
   // check whether our phrase has characters other than letters

     else 
    
            encrypt[i] = name[i] ;
        if (j % codeLen == 0)
        {
            j = 0;
 }
            
    // print coded string
        printf("%c", encrypt[i]);
 
 
 }
    printf("\n");
}
 

