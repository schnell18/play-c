#define MAX_ARRAY_LENGTH 20

#undef FILE_SIZE
#define FILE_SIZE 42

#define PRINT_MACRO \
    printf("File: %s\n", __FILE__); \
    printf("Date: %s\n", __DATE__); \
    printf("Time: %s\n", __TIME__); \
    printf("Line: %d\n", __LINE__); \
    printf("ANSI: %d\n", __STDC__);

#define MSG_FOR(a, b) \
    printf(#a " and " #b ": We love you\n");

#define TOK_PASTE(n) \
    printf("token" #n " = %d\n", token##n);


#if !defined(MESSAGE)
    #define MESSAGE "I wish you win!"
#endif

#define SQUARE(x) ((x) * (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))











