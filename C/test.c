#include <stdio.h>
#include <stdio.h>
#include <string.h>

struct Book { 
    int id;
    char title[100];
    int available;
    struct Book* next;
};

struct Book* bookhead = NULL;

void addbook(int id, char title[], int available){
   struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
   newBook->id = id;
   strcpy(newBook->title, title);
   newBook->available = available;
   newBook->next = bookhead;
   bookhead = newBook;
   printf("Book added successfully\n"); 
}

