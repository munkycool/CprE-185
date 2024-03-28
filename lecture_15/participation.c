#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int bookID;
    double price;
} bookData;

bookData scanBook() {
    bookData book;
    printf("Enter the book title: \n");
    scanf(" %s", book.title);
    printf("Enter the book author: \n");
    scanf(" %s", book.author);
    printf("Enter the book ID: \n");
    scanf(" %d", &book.bookID);
    printf("Enter the book price: \n");
    scanf(" %lf", &book.price);
    return book;
}

void printBook (bookData book) {
    printf("\n Book title: %s", book.title);
    printf("\n Book author: %s", book.author);
    printf("\n Book ID: %d", book.bookID);
    printf("\n Book price: %lf\n", book.price);
}

int main() {

    bookData book;

    printf("\n ----- Enter book info ----- \n");
    book = scanBook();

    printf("\n ----- Book info ----- \n");
    printBook(book);

}