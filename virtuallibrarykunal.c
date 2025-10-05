#include <stdio.h>
#include <string.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 5

// Book structure
typedef struct {
    char title[50];
    int isBorrowed;
} Book;

// Function prototypes
void displayBooks(Book books[], int count);
void borrowBook(Book books[], int count);
void returnBook(Book books[], int count);
void addBook(Book books[], int *count);
void removeBook(Book books[], int *count);

int main() {
    // Initialize library books
    Book books[MAX_BOOKS] = {
        {"The Great Gatsby", 0},
        {"To Kill a Mockingbird", 0},
        {"1984", 0},
        {"Pride and Prejudice", 0},
        {"Moby Dick", 0}
    };
    int bookCount = 5; // Initial count of books

    int choice;
    while (1) {
        printf("\n--- Virtual Library System ---\n");
        printf("1. Display Books\n");
        printf("2. Borrow a Book\n");
        printf("3. Return a Book\n");
        printf("4. Add a Book\n");
        printf("5. Remove a Book\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(books, bookCount);
                break;
            case 2:
                borrowBook(books, bookCount);
                break;
            case 3:
                returnBook(books, bookCount);
                break;
            case 4:
                addBook(books, &bookCount);
                break;
            case 5:
                removeBook(books, &bookCount);
                break;
            case 6:
                printf("Exiting the Virtual Library. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Display the list of books and their status
void displayBooks(Book books[], int count) {
    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s [%s]\n", i + 1, books[i].title, books[i].isBorrowed ? "Borrowed" : "Available");
    }
}

// Borrow a book if it's available
void borrowBook(Book books[], int count) {
    int bookIndex;
    displayBooks(books, count);
    printf("Enter the number of the book you want to borrow: ");
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > count) {
        printf("Invalid book number.\n");
        return;
    }

    if (books[bookIndex - 1].isBorrowed) {
        printf("Sorry, '%s' is already borrowed.\n", books[bookIndex - 1].title);
    } else {
        books[bookIndex - 1].isBorrowed = 1;
        printf("You have successfully borrowed '%s'.\n", books[bookIndex - 1].title);
    }
}

// Return a book if it is borrowed
void returnBook(Book books[], int count) {
    int bookIndex;
    displayBooks(books, count);
    printf("Enter the number of the book you want to return: ");
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > count) {
        printf("Invalid book number.\n");
        return;
    }

    if (!books[bookIndex - 1].isBorrowed) {
        printf("'%s' was not borrowed.\n", books[bookIndex - 1].title);
    } else {
        books[bookIndex - 1].isBorrowed = 0;
        printf("You have successfully returned '%s'.\n", books[bookIndex - 1].title);
    }
}

// Add a new book with user input for title and status
void addBook(Book books[], int *count) {
    // if (*count >= MAX_BOOKS) {
    //     printf("Library is full. Cannot add more books.\n");
    //     return;
    // }

    printf("Enter the title of the new book: ");
    getchar(); // to consume the leftover newline character from previous input
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; // Remove newline character

    printf("Is the book borrowed? Enter 1 for Yes, 0 for No: ");
    int status;
    scanf("%d", &status);

    if (status == 1) {
        books[*count].isBorrowed = 1;
        printf("Book added as borrowed.\n");
    } else {
        books[*count].isBorrowed = 0;
        printf("Book added as available.\n");
    }

    (*count)++;
    printf("Book added successfully!\n");
}

// Remove a book by its index
void removeBook(Book books[], int *count) {
    if (*count == 0) {
        printf("No books to remove.\n");
        return;
    }

    int bookIndex;
    displayBooks(books, *count);
    printf("Enter the number of the book you want to remove: ");
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > *count) {
        printf("Invalid book number.\n");
        return;
    }

    // Shift books to "remove" the selected book
    for (int i = bookIndex - 1; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }

    (*count)--;
    printf("Book removed successfully!\n");
}
