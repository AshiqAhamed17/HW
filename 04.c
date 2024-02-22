#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store car details
struct Car {
    int carID;
    char model[100];
    char engineType[50];
    float rentalRatePerDay;
};

int main() {
    struct Car cars[3];
    float totalRentalCost = 0.0;

    // Input details for three cars
    for (int i = 0; i < 3; ++i) {
        printf("Enter details for Car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].carID);
        getchar(); // Consume newline
        printf("Model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0'; // Remove trailing newline
        printf("Engine Type: ");
        fgets(cars[i].engineType, sizeof(cars[i].engineType), stdin);
        cars[i].engineType[strcspn(cars[i].engineType, "\n")] = '\0'; // Remove trailing newline
        printf("Rental Rate per Day: ");
        scanf("%f", &cars[i].rentalRatePerDay);
        getchar(); // Consume newline
    }

    // Calculate total rental cost
    for (int i = 0; i < 3; ++i) {
        totalRentalCost += cars[i].rentalRatePerDay;
    }

    // Display details of the cars
    printf("\nDetails of the cars:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Car %d:\n", i + 1);
        printf("Car ID: %d\n", cars[i].carID);
        printf("Model: %s\n", cars[i].model);
        printf("Engine Type: %s\n", cars[i].engineType);
        printf("Rental Rate per Day: %.2f\n", cars[i].rentalRatePerDay);
        printf("\n");
    }

    // Display total rental cost
    printf("Total Rental Cost for all cars: %.2f\n", totalRentalCost);

    return 0;
}
