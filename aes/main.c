#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aesConfig.h"
#include "b64.h"
#include "aes.h"


int ends_with(const char *str, const char *cmd)
{
    char *dash = strrchr(str, '-');
    if (dash == NULL) return 1;
    return strcmp(dash, cmd);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(
            stderr,
            "%s Version %d.%d\n",
            argv[0],
            AES_VERSION_MAJOR,
            AES_VERSION_MINOR
        );
        fprintf(stderr, "Usage: %s key text1 text2 ...\n", argv[0]);
        return 1;
    }
    if (ends_with(argv[0], "-decrypt") == 0)
    {
        char *buf = b64_decode(argv[1], strlen(argv[1]));
        printf("decode base64(%s) = %s\n", argv[1], buf);
        free(buf);
        printf("Decrypt\n");
    }
    else
    {
        char *enc = b64_encode(argv[1], strlen(argv[1]));
        printf("base64(%s) = %s\n", argv[1], enc);
        free(enc);
        printf("Encrypt\n");
    }
    return 0;
}
