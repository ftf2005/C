#include <stdio.h>
union Book {
    char title[50];
    char author[50];
    int size;  
};

int main() {
    union Book book;
    printf("Enter book title: ");
    scanf("%s", book.title);  
    printf("Enter book author: ");
    scanf("%s", book.author);  
    
    printf("Enter book size (in bytes): ");
    scanf("%d", &book.size);  

    printf("\nBook Details:\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Size: %d bytes\n", book.size);

    return 0;
}
