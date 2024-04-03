#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1, num2;
} item;

int main () {

    item x,y, *ptr;

    //ptr = &x;
    ptr = (item *) malloc(sizeof(item));

/*
    printf("Enter number 1: ");
    scanf("%d", &(*ptr).num1);
    printf("Enter number 2: ");
    scanf("%d", &(*ptr).num2);
*/

    ptr -> num1 = 9;
    ptr -> num2 = 11;

    //(*ptr).num1 = 9;
    //(*ptr).num2 = 11;

    printf("x.num1 = %d, x.num2 = %d\n", (*ptr).num1, (*ptr).num2);

    free(ptr);

}