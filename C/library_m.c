#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure (Linked List Node)
struct Book {
    int id;
    char title[100];
    int available;
    struct Book* next;
};

// Borrower structure (Linked List Node)
struct Borrower {
    int id;
    char name[100];
    struct Borrower* next;
};

// Queue node for borrower requests
struct Request {
    int book_id;
    int borrower_id;
    struct Request* next;
};

// Linked List for books and borrowers
struct Book* bookHead = NULL;
struct Borrower* borrowerHead = NULL;
struct Request* requestFront = NULL;
struct Request* requestRear = NULL;

// Function to add a book to the linked list
void addBook(int id, char title[], int available) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    newBook->available = available;
    newBook->next = bookHead;
    bookHead = newBook;
    printf("Book added successfully!\n");
}

// Function to add a borrower to the linked list
void addBorrower(int id, char name[]) {
    struct Borrower* newBorrower = (struct Borrower*)malloc(sizeof(struct Borrower));
    newBorrower->id = id;
    strcpy(newBorrower->name, name);
    newBorrower->next = borrowerHead;
    borrowerHead = newBorrower;
    printf("Borrower added successfully!\n");
}

// Function to remove a book from the list
void removeBook(int id) {
    struct Book *temp = bookHead, *prev;
    if (temp != NULL && temp->id == id) {
        bookHead = temp->next;
        free(temp);
        printf("Book removed successfully!\n");
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Book removed successfully!\n");
}

// Function to update a book's availability
void updateBook(int id, int available) {
    struct Book* temp = bookHead;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->available = available;
            printf("Book availability updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}

// Function to display all books
void displayBooks() {
    struct Book* temp = bookHead;
    if (temp == NULL) {
        printf("No books available!\n");
        return;
    }
    printf("Books Available:\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Available: %d\n", temp->id, temp->title, temp->available);
        temp = temp->next;
    }
}

// Function to add a request to the queue
void addRequest(int book_id, int borrower_id) {
    struct Request* newRequest = (struct Request*)malloc(sizeof(struct Request));
    newRequest->book_id = book_id;
    newRequest->borrower_id = borrower_id;
    newRequest->next = NULL;
    if (requestRear == NULL) {
        requestFront = requestRear = newRequest;
        return;
    }
    requestRear->next = newRequest;
    requestRear = newRequest;
    printf("Request added to queue successfully!\n");
}

// Function to process the next request in the queue
void processRequest() {
    if (requestFront == NULL) {
        printf("No requests in queue!\n");
        return;
    }
    struct Request* temp = requestFront;
    requestFront = requestFront->next;
    if (requestFront == NULL) {
        requestRear = NULL;
    }
    printf("Processing Request: Book ID %d, Borrower ID %d\n", temp->book_id, temp->borrower_id);
    free(temp);
}

// Function to undo the last operation (removal of the last book)
struct Book* undoLastBookRemoval(struct Book* head, struct Book* lastRemovedBook) {
    lastRemovedBook->next = head;
    return lastRemovedBook;
}

int main() {
    int choice, id, available;
    char title[100], name[100];
    
    while (1) {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Update Book\n");
        printf("4. Display Books\n");
        printf("5. Add Borrower\n");
        printf("6. Add Request\n");
        printf("7. Process Request\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book id: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter availability (1 for available, 0 for not available): ");
                scanf("%d", &available);
                addBook(id, title, available);
                break;
                
            case 2:
                printf("Enter book id to remove: ");
                scanf("%d", &id);
                removeBook(id);
                break;

            case 3:
                printf("Enter book id to update: ");
                scanf("%d", &id);
                printf("Enter new availability (1 for available, 0 for not available): ");
                scanf("%d", &available);
                updateBook(id, available);
                break;

            case 4:
                displayBooks();
                break;

            case 5:
                printf("Enter borrower id: ");
                scanf("%d", &id);
                printf("Enter borrower name: ");
                scanf(" %[^\n]%*c", name);
                addBorrower(id, name);
                break;
                
            case 6:
                printf("Enter book id for request: ");
                scanf("%d", &id);
                printf("Enter borrower id for request: ");
                int borrower_id;
                scanf("%d", &borrower_id);
                addRequest(id, borrower_id);
                break;

            case 7:
                processRequest();
                break;
                
            case 8:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
