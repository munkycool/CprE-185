#include <stdio.h>

// recursive function to calculate the length of a string
int stringLength(char *str) {
    if (*str == '\0') {
        return 0;
    }
    else {
        return 1 + stringLength(str + 1);
    }
}

int main () {
    char str[1028];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = stringLength(str);
    printf("Length of string: %d\n", length);

    return 0;
}