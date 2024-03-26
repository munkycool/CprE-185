#include <stdio.h>
#include <string.h>

void scanInfo (char a[][20], int n);
void printInfo (char a[][20], int n);

int main() {
    int n = 40;
    char name[n][20];

    printf("Updating array elements...\n");
    scanInfo(name, n);

    printf("Printing array elements...\n");
    printInfo(name, n);
}

void scanInfo (char a[][20], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter student %d's name: ", i);
        scanf("%s", a[i]);
    }
}

void printInfo (char a[][20], int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d: %s\n", i, a[i]);
    }
}