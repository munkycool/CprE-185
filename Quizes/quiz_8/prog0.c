#include <stdio.h>
#include <math.h>

typedef struct {
    double real_number;
    double imaginary_number;
} Complex;

int main() {
    Complex num1, num2, sum, difference, product;

    printf("Enter the real and imaginary values of number 1: ");
    scanf("%lf %lf", &num1.real_number, &num1.imaginary_number);

    printf("Enter the real and imaginary values of number 2: ");
    scanf("%lf %lf", &num2.real_number, &num2.imaginary_number);

    sum.real_number = num1.real_number + num2.real_number;
    sum.imaginary_number = num1.imaginary_number + num2.imaginary_number;
    product.real_number = num1.real_number * num2.real_number - num1.imaginary_number * num2.imaginary_number;
    product.imaginary_number = num1.real_number * num2.imaginary_number + num1.imaginary_number * num2.real_number;
    difference.real_number = num1.real_number - num2.real_number;
    difference.imaginary_number = num1.imaginary_number - num2.imaginary_number;


    printf("Sum: %.2lf + %.2lfi\n", sum.real_number, sum.imaginary_number);
    printf("Product: %.2lf + %.2lfi\n", product.real_number, product.imaginary_number);
    printf("Difference: %.2lf + %.2lfi\n", difference.real_number, difference.imaginary_number);
    
}