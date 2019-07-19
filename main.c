#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansifuncs.h"

#define MAXBUFFER 512

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ImgTxt to ANSI Codes converter\n2019 DHeadshot's Software Creations\n");
    printf("Usage:\n  %s <ImgTxtFile> <OutputFile>\n", argv[0]);
    printf("Where:\n  <ImgTxtFile> is an ImgTxt File to convert.\n");
    printf("  <outputFile> is the file to output to.\n");
    return 1;
  }
  FILE *ifp = fopen(argv[1], "r");
  if (!ifp)
  {
    fprintf(stderr, "Error opening \"%s\"!\n", argv[1]);
    return 2;
  }
  FILE *ofp = fopen(argv[2], "w");
  if (!ofp)
  {
    fprintf(stderr, "Error opening \"%s\"!\n", argv[1]);
    fclose(ifp);
    return 3;
  }
  
  writereset(ofp);
  
  char buffer[MAXBUFFER];
  while (!feof(ifp))
  {
    if (!fgets(buffer, MAXBUFFER, ifp)) break;
    writeline(buffer, ofp);
  }
  if (!feof(ifp))
  {
    fprintf(stderr, "Error reading from \"%s\"!\n", argv[1]);
    fclose(ifp);
    fclose(ofp);
    return 4;
  }
  
  writereset(ofp);
  
  fclose(ifp);
  fclose(ofp);
  return 0;
}
