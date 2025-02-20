#include<stdio.h>
struct Fiction_t { //383
    char title[250];
    char author[125];
    float price;
}; 
typedef struct Fiction_t Fiction;

struct NonFiction_t { //758
    char title[250];
    char subject[500];
    float price;
}; 
typedef struct NonFiction_t NonFiction;

union BookType_t {
    Fiction fiction;
    NonFiction nonFiction;
};

typedef union BookType_t BookType;

struct Book_t {
    int type;
    BookType booktype;
};

typedef struct Book_t Book;

Book books[1000];
int bookCount;

void addBooks();
void displayBooks();

int main() {
    addBooks();
    displayBooks();
    return 0;
}

void addBooks() {
    printf("Enter number of books:");
    scanf("%d", &bookCount);

    for(int I = 0; I < bookCount; I++) {
        printf("Type of book(1-Fiction, 2-Non fiction):");
        scanf("%d", &books[I].type);

        switch(books[I].type) {
            case 1 : {
                printf("Enter Fiction Book Details(Title, Author, Price):");
                scanf("%s%s%f", books[I].booktype.fiction.title,
                        books[I].booktype.fiction.author,
                        &books[I].booktype.fiction.price);
            } break;
            case 2 : {
                printf("Enter Non Fiction Book Details(Title, Subject, Price):");
                scanf("%s%s%f", books[I].booktype.nonFiction.title,
                        books[I].booktype.nonFiction.subject,
                        &books[I].booktype.nonFiction.price);
            } break;
        }
    }
}
void displayBooks() {
    for(int I = 0; I < bookCount; I++) {
        switch(books[I].type) {
            case 1 : {
                printf("Fiction Book: %s, Author: %s, Price: $%.2f\n", books[I].booktype.fiction.title,
                                                books[I].booktype.fiction.author,
                                                books[I].booktype.fiction.price);
            } break;
            case 2 : {
                printf("Non-Fiction Book: %s, Subject: %s, Price: $%.2f\n", books[I].booktype.nonFiction.title,
                    books[I].booktype.nonFiction.subject,
                    books[I].booktype.nonFiction.price);
            } break;
        }
    }
}
