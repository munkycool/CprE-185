/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h> // added the stdlib.h library
#include <time.h>

/*-----------------------------------------------------------------------------
Yay I fixed it! :)
-                                Prototypes                                   -
------------------------------------------------------------------------------*/
char ask_to_play(int times_played);

int select_random_number();

void run_game(int computer_number); // initialized the function "run_game"

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-3.c -o lab04-3
// Run with ./lab04-3
/* This program will play a simple Guessing Game with the computer. */

/*----------------------------------------------------------------------------
Yay I fixed this too! :) (btw I fixed the commenting out of it)
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    char prompt = '-';
    int played = 0, computer_guess = 0;

    prompt = ask_to_play(played);
    played = 1;

    while (prompt == 'y')     /* This line does not contain an error */
    {
        computer_guess = select_random_number();
        run_game(computer_guess);
        prompt = ask_to_play(played); //fixed the spelling of the variable "played"
    }

    printf("\n\nThanks for playing!\n");

    return 0;
}

/**
 * Asks the player if they want to play the Guessing Game.
 *
 * @param played_before - Whether the player has played a round of the game before or not.
 * @return - Whether the player wants to play again or not.
 */
char ask_to_play(int played_before)
{
    char yes_or_no;

    if (!played_before)    /* This line does not contain an error */
    {
        printf("Do you want to play a game? "
               "Enter 'y' to play, anything else not to play. :(\n  -> ");
        scanf(" %c", &yes_or_no); // added a & to the scanf function
    } else
    {
        scanf(" %c", &yes_or_no);
    }

    printf("%s", &yes_or_no); // added a & to the printf function, and changed it to %s from %c

    return yes_or_no;
}

/**
 * Generates a random number between 1 to 100, inclusive.
 *
 * @return - A number between 1 and 100, inclusive.
 */
int select_random_number()
{
    srand(time(NULL));
    return rand() % 100;
}

/**
 * Starts the Guessing Game for you to play!
 *
 * @param computer_number - The randomly generated number to be used for the game.
 */
void run_game(int computer_number)
{
    int number = 0;
    int correct = 0; // declared the variable "correct"


    printf("\n\nYou are guessing a number. The options are 1 through 100.\n\n");
    printf("What is your guess on what number I will select?\n  -> ");
    scanf("%d", &number); // changed %c to %d

    while (!correct)    /* This line does not contain an error */
    {
        if (number < 1 || number > 100)
        {
            printf("\nYour number is not within the correct range of numbers. Guess again\n  -> ");
        } else if (number == computer_number) // changed = to ==
        {
            printf("\nThe number was %d!\n", computer_number);
            printf("\nYou guessed the number correctly!\n\n"
                   "Do you want to play again? ('y' for yes)\n  -> ");
            correct = 1;
        } else if (number < computer_number) //removed the semicolon at the end of the elif statement
        {
            printf("\nYou guessed too low. Enter another guess.\n  -> ");
        } else
        {
            printf("\n You guessed too high. Enter another guess.\n  -> ");
        }

        scanf("%d", &number);
    }
}
