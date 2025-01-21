// #include <stdio.h>
// #include <string.h>

// struct Student {
//     int roll_no;
//     char name[50];
//     int marks[3];
//     int total_marks;
// };

// void inputDetails(struct Student *students, int n) {
//     for (int i = 0; i < n; i++) {
//         printf("Enter details for student %d:\n", i + 1);
//         printf("Roll No: ");
//         scanf("%d", &students[i].roll_no);
//         printf("Name: ");
//         scanf("%s", students[i].name);
//         students[i].total_marks = 0;
//         for (int j = 0; j < 3; j++) {
//             printf("Marks in subject %d: ", j + 1);
//             scanf("%d", &students[i].marks[j]);
//             students[i].total_marks += students[i].marks[j];
//         }
//     }
// }

// void displayDetails(struct Student *students, int n) {
//     printf("\nDetails of students in decreasing order of total marks:\n");
//     for (int i = 0; i < n; i++) {
//         printf("Roll No: %d, Name: %s, Total Marks: %d\n", students[i].roll_no, students[i].name, students[i].total_marks);
//     }
// }

// int compare(const void *a, const void *b) {
//     struct Student *studentA = (struct Student *)a;
//     struct Student *studentB = (struct Student *)b;
//     return studentB->total_marks - studentA->total_marks;
// }

// int main() {
//     int n;
//     printf("Enter the number of students: ");
//     scanf("%d", &n);

//     struct Student students[n];
//     inputDetails(students, n);

//     qsort(students, n, sizeof(struct Student), compare);

//     displayDetails(students, n);

//     return 0;
// }
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