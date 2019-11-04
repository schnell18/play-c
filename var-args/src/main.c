#include <stdio.h>
#include <string.h>
#include <stdarg.h>

double avg(int num,...)
{
    va_list valist;
    double sum = 0.0;

    va_start(valist, num);
    for (int i = 0; i < num; i ++)
    {
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum / num;
}

int main()
{

    printf("Avg(2, 3, 4, 5) = %f\n", avg(4, 2, 3, 4, 5));
    printf("Avg(12, 3, 14, 5) = %f\n", avg(4, 12, 3, 14, 5));

    return 0;
}
