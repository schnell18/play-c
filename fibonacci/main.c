#include <stdio.h>
#include <stdlib.h>
#include "fib.h"

int main()
{
    int n = 10;
    printf("fib(%d) = %lu\n", n, fib(n));
    return 0;
}
