#include <stdio.h>
#include <string.h>
#include "myheader.h"

int main()
{

    printf("File: %s\n", __FILE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("Line: %d\n", __LINE__);
    printf("ANSI: %d\n", __STDC__);

    PRINT_MACRO
    MSG_FOR(Carole, Debra);

    int token34 = 40;
    TOK_PASTE(34)

    printf("Here is the msg: %s\n", MESSAGE);
    printf("square(%d)=%d\n", 10, SQUARE(10));
    printf("max(%d,%d)=%d\n", 11, 10, MAX(11, 10));

    return 0;
}
