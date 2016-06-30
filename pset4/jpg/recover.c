/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(void)
{
    typedef uint8_t  BYTE ;
    BYTE jpgStart1[4]={0xff, 0xd8, 0xff, 0xe0};
    BYTE jpgStart2[4]={0xff, 0xd8, 0xff, 0xe1};
    int found = 0;
    int open = 0;
    FILE* outptr;
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fclose(inptr);
        printf("Could not open %s.\n", "card.raw");
        return 1;
    }
    
    BYTE buffer[512];
    fread(buffer, sizeof(buffer), 1, inptr);
    while (fread(buffer, sizeof(buffer), 1, inptr) > 0)
    {
 

        if (buffer[0] == jpgStart1[0] && buffer[1] == jpgStart1[1] && buffer[2] == jpgStart1[2] && (buffer[3] == jpgStart1[3] || buffer[3] == jpgStart2[3] ))
        {
            char newjpg[8];
            sprintf(newjpg, "%03d.jpg", found);
            if (open == 0)
            {
 
                outptr = fopen(newjpg,"w");
                fwrite(buffer, sizeof(buffer), 1, outptr);
                open = 1;
 }
            if (open == 1)
            {
                fclose(outptr);
                outptr = fopen(newjpg,"w");
                fwrite(buffer, sizeof(buffer), 1, outptr);
                found++;
        }
                }
else 
        {
            if (open == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, outptr);
}
}

}
    if (outptr)
    {
        fclose(outptr);
 }
    fclose(inptr);
    return 0;
}
