#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int year;
} Publisher;

typedef struct {
    int id;
    char title[30];
    float price;
    Publisher pub;   // nested structure
} Book;

// Function to print details of all books
void printAllBooks(Book *books, int n) {
    int i;
    printf("\n--- List of All Books ---\n");
    for (i = 0; i < n; i++) {
        Book *b = &books[i];   // pointer to current book
        printf("\nBook %d:\n", i + 1);
        printf("ID: %d\n", b->id);                 // arrow operator
        printf("Title: %s\n", b->title);           // arrow operator
        printf("Price: %.2f\n", b->price);         // arrow operator
        printf("Publisher: %s\n", b->pub.name);    // arrow + dot (nested struct)
        printf("Year: %d\n", b->pub.year);         // arrow + dot
    }
}

// Function to find the book with maximum price
Book* findMaxBook(Book *books, int n) {
    int i, maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (books[i].price > books[maxIndex].price) {  // dot operator
            maxIndex = i;
        }
    }
    return &books[maxIndex];
}

// Function to find the book with minimum price
Book* findMinBook(Book *books, int n) {
    int i, minIndex = 0;
    for (i = 1; i < n; i++) {
        if (books[i].price < books[minIndex].price) {  // dot operator
            minIndex = i;
        }
    }
    return &books[minIndex];
}

int main() {
    int n, i;

    printf("Enter number of books: ");
    fflush(stdout);
    scanf("%d", &n);

    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details for book %d:\n", i + 1);

        printf("ID: ");
        fflush(stdout);
        scanf("%d", &books[i].id);                  // dot operator

        printf("Title: ");
        fflush(stdout);
        scanf(" %[^\n]", books[i].title);           // dot operator

        printf("Price: ");
        fflush(stdout);
        scanf("%f", &books[i].price);                // dot operator

        printf("Publisher name: ");
        fflush(stdout);
        scanf(" %[^\n]", books[i].pub.name);         // dot operator (nested struct access)

        printf("Publication year: ");
        fflush(stdout);
        scanf("%d", &books[i].pub.year);              // dot operator (nested struct access)
    }

    // Print all book details
    printAllBooks(books, n);

    // Find and print the most expensive book
    Book *maxBookPtr = findMaxBook(books, n);
    printf("\n--- Most Expensive Book ---\n");
    printf("ID: %d\n", maxBookPtr->id);                  // arrow operator
    printf("Title: %s\n", maxBookPtr->title);            // arrow operator
    printf("Price: %.2f\n", maxBookPtr->price);          // arrow operator
    printf("Publisher: %s\n", maxBookPtr->pub.name);     // arrow + dot
    printf("Year: %d\n", maxBookPtr->pub.year);          // arrow + dot

    // Find and print the least expensive book
    Book *minBookPtr = findMinBook(books, n);
    printf("\n--- Least Expensive Book ---\n");
    printf("ID: %d\n", minBookPtr->id);                  // arrow operator
    printf("Title: %s\n", minBookPtr->title);            // arrow operator
    printf("Price: %.2f\n", minBookPtr->price);          // arrow operator
    printf("Publisher: %s\n", minBookPtr->pub.name);     // arrow + dot
    printf("Year: %d\n", minBookPtr->pub.year);          // arrow + dot

    free(books);
    return 0;
}
