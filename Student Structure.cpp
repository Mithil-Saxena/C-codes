#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    int marks[3];
    int totalMarks;
};

void inputStudent(struct Student *s) {
    printf("Enter Roll No: ");
    scanf("%d", &s->rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]s", s->name);
    printf("Enter marks in three subjects: ");
    for(int i = 0; i < 3; i++) {
        scanf("%d", &s->marks[i]);
    }
    s->totalMarks = s->marks[0] + s->marks[1] + s->marks[2];
}

void sortStudents(struct Student arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j].totalMarks < arr[j+1].totalMarks) {
                struct Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for(int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i+1);
        inputStudent(&students[i]);
    }

    sortStudents(students, n);

    printf("\nStudents sorted by total marks:\n");
    printf("\nRoll No\tName\t\tTotal Marks\n");
    printf("================================\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%d\n", 
               students[i].rollNo, 
               students[i].name, 
               students[i].totalMarks);
    }

    return 0;
}
