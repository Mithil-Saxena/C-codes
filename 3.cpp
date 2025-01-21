#include <stdio.h>
#include <string.h>

struct Employee {
    int emp_no;
    char name[50];
    float basic_salary;
    float hra;
    float net_salary;
};

int main() {
    int N;
    float avg_salary = 0;
    
    printf("Enter the number of employees: ");
    scanf("%d", &N);
    
    struct Employee emp[N];
    
    // Input employee details
    for(int i = 0; i < N; i++) {
        printf("\nEnter details for Employee %d:\n", i+1);
        printf("Employee No: ");
        scanf("%d", &emp[i].emp_no);
        printf("Name: ");
        scanf(" %[^\n]s", emp[i].name);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA: ");
        scanf("%f", &emp[i].hra);
        
        // Calculate net salary
        emp[i].net_salary = emp[i].basic_salary + emp[i].hra;
        avg_salary += emp[i].net_salary;
    }
    
    // Calculate average salary
    avg_salary /= N;
    
    // Display all employees
    printf("\nAll Employee Details:\n");
    printf("Emp No\tName\t\tBasic\tHRA\tNet Salary\n");
    printf("------------------------------------------------\n");
    for(int i = 0; i < N; i++) {
        printf("%d\t%-15s\t%.2f\t%.2f\t%.2f\n", 
               emp[i].emp_no, 
               emp[i].name, 
               emp[i].basic_salary, 
               emp[i].hra, 
               emp[i].net_salary);
    }
    
    // Display employees with above average salary
    printf("\nEmployees with above average salary (%.2f):\n", avg_salary);
    printf("Emp No\tName\t\tBasic\tHRA\tNet Salary\n");
    printf("------------------------------------------------\n");
    for(int i = 0; i < N; i++) {
        if(emp[i].net_salary > avg_salary) {
            printf("%d\t%-15s\t%.2f\t%.2f\t%.2f\n", 
                   emp[i].emp_no, 
                   emp[i].name, 
                   emp[i].basic_salary, 
                   emp[i].hra, 
                   emp[i].net_salary);
        }
    }
    
    return 0;
}