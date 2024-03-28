#include <stdio.h>
#include <string.h>

// Fucntion defiinition of user defined data type 

struct studentRecord{
    char name[20];
    int id;
    char dept[5];
    char gender[2];
    // double hw[10];
    // double exams[10];
};

// Function to scan student info

struct studentRecord scanInfo() {
    struct studentRecord student;
    printf("Enter the student's name: \n");
    scanf("%s", student.name);
    printf("Enter the student's ID: \n");
    scanf("%d", &student.id);
    printf("Enter the student's department: \n");
    scanf("%s", student.dept);
    printf("Enter the student's gender: \n");
    scanf("%s", student.gender);

    return student;
}

// Function to print student info
void printInfo(struct studentRecord student) {
    printf("\n Student name: %s", student.name);
    printf("\n Student ID: %d", student.id);
    printf("\n Student Department: %s", student.dept);
    printf("\n Student gender: %s\n", student.gender);
}

int main() {
    // Declare a variable using the user defined data type

    struct studentRecord student[2];

    for (int i = 0; i < 2; i++) {
        printf("\n ----- Enter student ~%d~ info ----- \n", i+1);
        student[i] = scanInfo();
    }
    
    //printing student info

    for (int i = 0; i < 2; i++) {
        printf("\n ----- Student ~%d~ info ----- \n", i+1);
        printInfo(student[i]);
    }

}