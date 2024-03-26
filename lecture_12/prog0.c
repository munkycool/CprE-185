#include <stdio.h>
#include <stdlib.h>

int main () {
    int i, num, sum;
    int *ptr;
    
    printf("Enter a number of elements: ");
    scanf("%d", &num);

    ptr = (int*)malloc(num * sizeof(int));
    //ptr = (int*)calloc(num, sizeof(int));

    for(i = 0; i < num; i++) {
        printf("Element %d is %d\n", i, ptr[i]);
    }
}