#include <stdio.h>
#include <stdlib.h>

struct name{
    char name[20];
};

int main () {
    printf("Enter your name: ");
    struct name p;
    scanf("%s", p.name);

    printf("Hello, %s!\n", p.name);
    
}