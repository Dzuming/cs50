/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 2;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    if (n < 1 || n > 100)
    {
        printf("Choose  a positive integer less than or equal to 100\n");
        return 1;
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfnew;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfnew = bf;
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, binew;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    binew = bi;
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    
    binew.biWidth = bi.biWidth * n;
    binew.biHeight = bi.biHeight * n;
   
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding =  (4 - (binew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    binew.biSizeImage = (binew.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(binew.biHeight);
    bfnew.bfSize = bf.bfSize - bi.biSizeImage + binew.biSizeImage;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfnew,sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&binew, sizeof(BITMAPINFOHEADER), 1, outptr);
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int l = 0; l < n ; l++)
        {
        // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth ; j++)
            {
        
            // temporary storage
                RGBTRIPLE triple;

            // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
                for ( int l = 0; l < n ; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE),1, outptr);
            }
        }

        

        // then add it back (to demonstrate how)
            for (int k = 0; k < newPadding; k++)
            {
                fputc(0x00, outptr);
        }
            if (l < n - 1)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
    }
    // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
