#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char pass1[20];
    char pass2[20];

    printf("Enter a password at least 4 digits long: ");
    scanf("%s", pass1);

    if (strlen(pass1) >= 4) {
        printf("Enter the password again: ");
        scanf("%s", pass2);
        if (strcmp(pass1, pass2) == 0) {
            printf("Passwords match\n");
            exit(0);
        }
        else {
            printf("Passwords do not match\n");
            exit(0);
        }
    }
    else {
        printf("Password is too short\n");
        exit(0);
    }
}