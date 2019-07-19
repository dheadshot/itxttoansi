#ifndef __ANSIFUNCS_H__
#define __ANSIFUNCS_H__ 1


#define ESCCHARS "\033["

#define BLACKT "30"
#define WHITET "97"
#define REDT "91"
#define GREENT "92"
#define YELLOWT "93"
#define BLUET "94"
#define FUCHSIAT "95"
#define CYANT "96"

#define colourt(xt) ESCCHARS xt "m"

#define RESETCOLOURS ESCCHARS "0m"

void writereset(FILE *afp);
void writeline(char *line, FILE *afp);


#endif
