#include <stdio.h>

int main(void)
{
    char var1;
    char var2;

    printf("Enter the first value and second value\n");
    scanf("%c,%c", &var1 , &var2);

    printf("Now, we are printing\n");
    printf("a duplicate version\n");
    printf("of both inputs: %c %c %c %c", var1, var1, var2, var2);

    return 0;
}
