#include<stdio.h>

//function declatiarion 

double sqr(double n);

int main(void) {
    double userNum;

    printf("Enter a number: ");
    scanf("%lf", &userNum);

    double result = sqr(userNum); //function call
    printf("resutl: %lf\n", result);

    return 0;
}

//function definition
double sqr(double n) {
    double r = n * n;
    // double p = r + 10;
    return r;

}
