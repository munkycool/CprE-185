#include <stdio.h>

int main() {
    char name[100];
    double midterm1, midterm2, final;
    double average[4];

    //create a file 
    FILE *file = fopen("students.txt", "w+r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    //write to the file
    for (int i =0; i < 4; i++) {
        printf("Enter student name: ");
        scanf("%s", name);
        fprintf(file, "%s\n", name);
        printf("Enter midterm1 grade: ");
        scanf("%lf", &midterm1);
        fprintf(file, "%lf\n", midterm1);
        printf("Enter midterm2 grade: ");
        scanf("%lf", &midterm2);
        fprintf(file, "%lf\n", midterm2);
        printf("Enter final grade: ");
        scanf("%lf", &final);
        fprintf(file, "%lf\n", final);
    }

    // Read from the file
    rewind(file);

    //calculate the average from the file
    for (int i = 0; i < 4; i++) {
        fscanf(file, "%s", name);
        fscanf(file, "%lf", &midterm1);
        fscanf(file, "%lf", &midterm2);
        fscanf(file, "%lf", &final);
        average[i] = (midterm1 + midterm2 + final) / 3;
    }

    for (int i = 0; i < 4; i++) {
        fscanf(file, "%s", name);
        fscanf(file, "%lf", &midterm1);
        fscanf(file, "%lf", &midterm2);
        fscanf(file, "%lf", &final);
        printf("\n~~~~~~~~~~~~~~\n");
        printf("Name: %s\n", name);
        printf("Midterm1: %.2lf\n", midterm1);
        printf("Midterm2: %.2lf\n", midterm2);
        printf("Final: %.2lf\n", final);
        printf("Average: %.2lf\n", average[i]);
    }

}