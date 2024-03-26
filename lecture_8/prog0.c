#include <stdio.h>
#include <string.h>

int main() {

    char password[100];

    printf("Please enter a strong password of at least 4 characters: ");
    scanf("%s", password);

    while (strlen(password) < 4) {
        printf("Password is too short looser. Please enter a password as strong as me: ");
        scanf("%s", password);

        if (strlen (password) >= 4) {
            printf("Terrible password, but thanks anyway!\n");
            break;
        }
    }
}