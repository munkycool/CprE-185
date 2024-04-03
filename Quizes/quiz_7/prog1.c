#include<stdio.h>

int main() {
    int a = 15;
    int* ptr_a;
    a /= 3;
    ptr_a = &a;
    a++;
    a = *ptr_a;
    if(*ptr_a == a) {
        printf("prt_a = %d\n" , *ptr_a);
        printf("a = %d\n" , a);
        printf("Therefore, prt_a = a = %d\n" , *ptr_a);
    }
return 0;
}