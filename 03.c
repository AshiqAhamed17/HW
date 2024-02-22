#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store employee details
struct Employee {
    char name[100];
    int id;
    float salary;
};

// Function to find the index of the employee with the highest salary
int findHighestSalaryEmployee(struct Employee employees[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (employees[i].salary > employees[maxIndex].salary) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the employee with the lowest salary
int findLowestSalaryEmployee(struct Employee employees[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (employees[i].salary < employees[minIndex].salary) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int numEmployees;

    // Get the number of employees from the user
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    getchar(); // Consume newline

    // Dynamically allocate memory for employees
    struct Employee *employees = malloc(numEmployees * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input details for employees
    for (int i = 0; i < numEmployees; ++i) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        getchar(); // Consume newline
    }

    // Find the employee with the highest salary
    int highestSalaryIndex = findHighestSalaryEmployee(employees, numEmployees);

    // Find the employee with the lowest salary
    int lowestSalaryIndex = findLowestSalaryEmployee(employees, numEmployees);

    // Display the employee with the highest salary
    printf("\nEmployee with Highest Salary:\n");
    printf("Name: %s\n", employees[highestSalaryIndex].name);
    printf("ID: %d\n", employees[highestSalaryIndex].id);
    printf("Salary: %.2f\n", employees[highestSalaryIndex].salary);

    // Display the employee with the lowest salary
    printf("\nEmployee with Lowest Salary:\n");
    printf("Name: %s\n", employees[lowestSalaryIndex].name);
    printf("ID: %d\n", employees[lowestSalaryIndex].id);
    printf("Salary: %.2f\n", employees[lowestSalaryIndex].salary);

    // Free dynamically allocated memory
    free(employees);

    return 0;
}
