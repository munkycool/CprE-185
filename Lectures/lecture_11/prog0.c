#include <stdio.h>
#include <stdlib.h>

int main() {
    int random;
    random = rand() % (1000+1-10) + 1000;

    printf("Random number: %d\n", random);
}