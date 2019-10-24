#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("ASCII Punct Table\n");
    for (int i = 0, j = 0; i < 256; i ++)
    {
        if (ispunct(i))
        {
            if (j++ % 8 == 0)
            {
                printf("\n%02d %c %02d", (j / 8 + 1), i, j);
            }
            else {
                printf("%c %02d ", i, j);
            }
        }
    }
    printf("\n\n");
    return 0;
}
