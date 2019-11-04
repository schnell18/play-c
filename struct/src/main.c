#include <stdio.h>
#include <string.h>

typedef struct Book {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;

void print_book(Book *book);

int main()
{

    Book book1;
    Book book2;

    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Nuha Ali");
    strcpy(book1.subject, "C Programming Tutorial");
    book1.book_id = 100;

    strcpy(book2.title, "Telecom Billing");
    strcpy(book2.author, "Zara Ali");
    strcpy(book2.subject, "Telecom Billing Tutorial");
    book2.book_id = 200;


    print_book(&book1);
    print_book(&book2);

    return 0;
}

void print_book(Book *book)
{
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book id: %d\n", book->book_id);
}
