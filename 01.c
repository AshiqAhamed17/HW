#include <stdio.h>
#include <string.h>

 struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
     struct Employee employees[3];

     for (int i = 0; i < 3; i++) {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("ID: ");
        scanf("%d", &employees[i].id);
         printf("Salary: ");
        scanf("%f", &employees[i].salary);
         printf("\n");
    }
      int highestSalaryIndex = 0;
    for(int i=0;i<3;i++)
      {
        if(employees[i].salary>employees[highestSalaryIndex].salary)
        {
          highestSalaryIndex=i;
        }
          
      }
  printf("employee with highest salary is dispayed:\n");

  printf("Name: %s\n",employees[highestSalaryIndex].name);
  printf("ID: %d\n",employees[highestSalaryIndex].id);
  printf("Salary: %.2f\n",employees[highestSalaryIndex].salary);
}
