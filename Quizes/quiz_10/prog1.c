// Artemis Tack and Ian Anton 

#include <stdio.h>
#include <stdlib.h>

// recursive function to calculate the power of a number
int calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * calculatePower(base, exponent - 1);
    }
}

int main() {
    int base, exponent;
    printf("Enter number and power: ");
    scanf("%d %d", &base, &exponent);

    int result = calculatePower(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}