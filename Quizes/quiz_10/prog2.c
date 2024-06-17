// Artemis Tack and Ian Anton 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numArray[8];

    FILE *fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "12 7 3 0 28 74 37 299");
    fclose(fp);

    FILE *fp2 = fopen("numbers.txt", "r");
    if (fp2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < 8; i++) {
        fscanf(fp2, "%d", &numArray[i]);
    }
    fclose(fp2);

    for (int i = 0; i < 8; i++) {
        printf("%d ", numArray[i]);
    }
    printf("\n");

    return 0;

}