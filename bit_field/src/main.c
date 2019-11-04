#include <stdio.h>
#include <string.h>

typedef struct SimpleStatus {
    unsigned int widthValidated;
    unsigned int heightValidated;
} SimpleStatus;

typedef struct BitStatus {
    unsigned int widthValidated:1;
    unsigned int heightValidated:1;
} BitStatus;

typedef struct Age {
    unsigned int amt:4;
} Age;

int main()
{
    SimpleStatus stat1;
    stat1.widthValidated = 1;
    stat1.heightValidated = 1;

    BitStatus stat2;
    stat2.widthValidated = 1;
    stat2.heightValidated = 0;

    printf("Storeage size for stat1: %lu\n", sizeof(stat1));
    printf(
        "stat1 {widthValidated: %d, heightValidated: %d}\n",
        stat1.widthValidated,
        stat1.heightValidated
    );

    printf("Storeage size for stat2: %lu\n", sizeof(stat2));
    printf(
        "stat2 {widthValidated: %d, heightValidated: %d}\n",
        stat2.widthValidated,
        stat2.heightValidated
    );

    Age age;

    age.amt = 4;
    printf("Storeage size for age: %lu\n", sizeof(age));
    printf("age.amt :%d\n", age.amt);

    age.amt = 7;
    printf("Storeage size for age: %lu\n", sizeof(age));
    printf("age.amt :%d\n", age.amt);

    age.amt = 8;
    printf("Storeage size for age: %lu\n", sizeof(age));
    printf("age.amt :%d\n", age.amt);

    age.amt = 100;
    printf("Storeage size for age: %lu\n", sizeof(age));
    printf("age.amt :%d\n", age.amt);

    return 0;
}
