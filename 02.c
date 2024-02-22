#include <stdio.h>
#include <string.h>

// Struct to store book details
struct Book {
    char title[100];
    char author[100];
    float price;
};

// Function to find the index of the most expensive book
int findMostExpensive(struct Book books[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (books[i].price > books[maxIndex].price) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the lowest priced book
int findLowestPriced(struct Book books[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (books[i].price < books[minIndex].price) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    struct Book books[3];

    // Input details for three books
    for (int i = 0; i < 3; ++i) {
        printf("Enter details for Book %d:\n", i + 1);
        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // Remove trailing newline
        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // Remove trailing newline
        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar(); // Consume newline
    }

    // Find the most expensive and lowest priced books
    int mostExpensiveIndex = findMostExpensive(books, 3);
    int lowestPricedIndex = findLowestPriced(books, 3);

    // Display the most expensive and lowest priced books
    printf("\nMost Expensive Book:\n");
    printf("Title: %s\n", books[mostExpensiveIndex].title);
    printf("Author: %s\n", books[mostExpensiveIndex].author);
    printf("Price: %.2f\n", books[mostExpensiveIndex].price);

    printf("\nLowest Priced Book:\n");
    printf("Title: %s\n", books[lowestPricedIndex].title);
    printf("Author: %s\n", books[lowestPricedIndex].author);
    printf("Price: %.2f\n", books[lowestPricedIndex].price);

    return 0;
}
