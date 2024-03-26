#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); // sets the seed value to the current time 

    printf("random number 1 is %d\n", rand()%10);
    printf("random number 2 is %d\n", rand()%100);
    printf("random number 3 is %d\n", rand()%1000);
    printf("random number 4 is %d\n", rand()%10000);
    
}