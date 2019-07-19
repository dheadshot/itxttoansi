#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansifuncs.h"

char lastcolour = 0;

void writereset(FILE *afp)
{
  fprintf(afp, "%s", RESETCOLOURS);
  lastcolour = 0;
}

void writeline(char *line, FILE *afp)
{
  int i;
  char a;
  for (i=0; line[i] != 0; i++)
  {
    a = line[i];
    if ((i & 1) != 0)
    {
      fprintf(afp, "%c", a);
    }
    else
    {
      if (a == '\n')
      {
        fprintf(afp, "%c", a);
      }
      else if (lastcolour != a && a != '\r')
      {
        switch ((a & 0x07))
        {
          case 0:
            fprintf(afp, colourt(BLACKT));
          break;
          
          case 1:
            fprintf(afp, colourt(BLUET));
          break;
          
          case 2:
            fprintf(afp, colourt(GREENT));
          break;
          
          case 3:
            fprintf(afp, colourt(CYANT));
          break;
          
          case 4:
            fprintf(afp, colourt(REDT));
          break;
          
          case 5:
            fprintf(afp, colourt(FUCHSIAT));
          break;
          
          case 6:
            fprintf(afp, colourt(YELLOWT));
          break;
          
          case 7:
            fprintf(afp, colourt(WHITET));
          break;
          
          default:
            //Err...
          break;
        }
        lastcolour = a;
      }
    }
    
  }
}
