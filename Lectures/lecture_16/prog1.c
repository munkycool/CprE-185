#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    double exam[3];
} studentRecord;

int scanInfo () {
    studentRecord studentList[40];
    int i = 0;

    for (i = 0; i < 40; i++) {
        printf("\nEnter student name: ");
        scanf("%s", studentList[i].name);

        if (strlen(studentList[i].name) > 40) {
            printf("Name is too long. Please enter a name with less than 40 characters.");
            break;
        }

        printf("\nEnter exam 1 score: ");
        scanf("%lf", &studentList[i].exam[0]);
        printf("\nEnter exam 2 score: ");
        scanf("%lf", &studentList[i].exam[1]);
        printf("\nEnter exam 3 score: ");
        scanf("%lf", &studentList[i].exam[2]);
    }
}

int main () {

    studentRecord studentList[40];

    scanInfo();

}