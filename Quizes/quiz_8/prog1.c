#include <stdio.h>
#include <stdlib.h>

typedef struct time {
    int hr;
    int min;
    int sec;
} time;

/*declare functions*/
void convTime(time *mileTime, int seconds);
void printTime(int hr, int min, int sec);


int main() {
    time *mileTime;
    /*allocate memory*/
    mileTime = (time *)malloc(sizeof(time));
    int seconds;
    printf("Total seconds: ");
    scanf("%d", &seconds);
    convTime(mileTime, seconds);
    printTime(mileTime->hr, mileTime->min, mileTime->sec);
    free(mileTime);
    return 0;
}

void convTime(time *mileTime, int seconds) {
    /*function definition*/
    mileTime->hr = seconds / 3600;
    mileTime->min = (seconds % 3600) / 60;
    mileTime->sec = (seconds % 3600) % 60;
}

void printTime(int hr, int min, int sec) {
    /*function definition*/
    printf("Time: %d hr %d min %d sec\n", hr, min, sec);
}