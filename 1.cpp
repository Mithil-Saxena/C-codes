#include <stdio.h>
#include <string.h>
struct Personal {
    char name[50];
    char date_of_joining[20];
    float salary;
};

int main() {
    struct Personal person;
    
    printf("Enter person's name: ");
    gets(person.name);
    
    printf("Enter date of joining (DD/MM/YYYY): ");
    gets(person.date_of_joining);
    
    printf("Enter salary: ");
    scanf("%f", &person.salary);

    printf("\n\nPerson's Details:\n");
    printf("Name: %s\n", person.name);
    printf("Date of Joining: %s\n", person.date_of_joining);
    printf("Salary: %.2f\n", person.salary);
}