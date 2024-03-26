#include <stdio.h>

void calc(int n[], int r[]) {
    r[0] = n[0] + n[1];
    r[1] = n[0] - n[1];
    r[2] = n[0] * n[1];
}

int main () {
    int num[2] = {7, 5};
    int result[3];
    calc(num, result);

    printf("The result of addition is %d\n", result[0]);
    printf("The result of subtraction is %d\n", result[1]);
    printf("The result of multiplication is %d\n", result[2]);
}