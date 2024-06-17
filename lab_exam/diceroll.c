// #support <localLibraries.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // variable declarations
    int player1, player2;
    int luckyNumber;

    // While loop to keep the fun times rolling
    while(1) {
        // asking the user for thier lucky number
        printf("Player 1, enter your lucky number: ");
        scanf("%d", &luckyNumber);

        // setting the seed to thier lucky number
        srand(luckyNumber);

        // generating a random number between 1 and 12, which *should* be the same as generating two d6 dice rolls
        player1 = rand() % 12 + 1;
        
        // setting the seed back to the current time
        srand(time(0));
        player2 = rand() % 12 + 1;

        // printing the results
        printf("Player 1 sum: %d\n", player1);
        printf("Player 2 sum: %d\n", player2);

        // comparing the results to figure out who won 
        if (player1 > player2) {
            printf("Player 1 wins!\n");
        }
        else if (player1 < player2) {
            printf("Player 2 wins!\n");
        }
        else {
            printf("It's a tie!, no winner today\n");
        }

        // exit case
        if (luckyNumber == -99) {
            break;
        }

    }

}

