#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"
#include "b64.h"
#include "aesConfig.h"

int ends_with(const char *str, const char *cmd)
{
    char *dash = strrchr(str, '-');
    if (dash == NULL) return 1;
    return strcmp(dash, cmd);
}

int count_paddings(const char *str)
{
    int count = 0;
    int len = strlen(str);
    if (len > 2)
    {
        if ( *(str + len -1) == '=') {
            count ++;
        }
        if ( *(str + len -2) == '=') {
            count ++;
        }
    }
    return count;
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
    char *key = argv[1];
    char *iv = "aabbccddeeffgghh";
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, key, iv);
    if (ends_with(argv[0], "-decrypt") == 0)
    {
        for (int i = 2; i < argc; i ++)
        {
            // remove the first 3 chars
            char *buf = argv[i] + 3;
            int cypher_len = strlen(buf);
            int len = 3 * cypher_len / 4 - count_paddings(buf);
            buf = b64_decode(buf, cypher_len);
            AES_CBC_decrypt_buffer(&ctx, buf, len);
            // strip PKCS7 padding
            int padding = (int) (*(buf + len - 1));
            *(buf + len - padding) = '\0';
            printf("%s\n", buf);
            free(buf);
            buf = NULL;
        }
    }
    else
    {
        for (int i = 2; i < argc; i ++)
        {
            int len = strlen(argv[i]);
            int padding = 16 - len % 16;
            if (padding == 0)
            {
                padding = 16;
            }
            // alloc the buf and do PKCS7 padding
            char *buf = (char*) calloc(1, len + padding + 1);
            strcpy(buf, argv[i]);
            for (int j = len; j < len + padding; j++)
            {
                *(buf + j) = (char) padding;
            }
            AES_CBC_encrypt_buffer(&ctx, buf, len + padding);
            char *enc = b64_encode(buf, len + padding);
            printf("sea%s\n", enc);
            free(enc);
            free(buf);
            enc = NULL;
            buf = NULL;
        }
    }
    return 0;
}
