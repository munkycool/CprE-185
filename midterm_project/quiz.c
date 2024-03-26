/*
 *                   :                        ___
 *                   :                       -   ---___- ,,
 *        ,,         :         ,,               (' ||    ||
 *        ::         :         ::              ((  ||    ||/\\  _-_
 * ,,     ::         :         ::     ,,      ((   ||    || || || \\
 * ::     ::         :         ::     ::       (( //     || || ||/
 *  '::.   '::.      :      .::'   .::'          -____-  \\ |/ \\,/
 *     '::.  '::.  _/~\_  .::'  .::'       -_-/            |\
 *       '::.  :::/     \:::  .::'        (_ /          '   \\
 *         ':::::(       ):::::'         (_ --_  -_-_  \\  / \\  _-_  ,._-_
 *                \ ___ /                  --_ ) || \\ || || || || \\  ||
 *          .:::::/`   `\:::::.           _/  )) || || || || || ||/    ||
 *        .::'   .:\o o/:.   '::.        (_-_-   ||-'  \\  \\/  \\,/   \\,
 *      .::'   .::  :":  ::.   '::.              |/
 *    .::'    ::'   ' '   '::    '::.      -_-/  '                 ,,
 *   ::      ::             ::      ::    (_ /                 _   ||
 *   ^^      ::             ::      ^^   (_ --_  -_-_   _-_   ( \, ||/\  _-_,
 *           ::             ::             --_ ) || \\ || \\  /-|| ||_( ||_.
 *           ^^             ^^            _/  )) || || ||/   (( || || |  ~ ||
 *                                       (_-_-   ||-'  \\,/   \/\\ \\,\ ,-_-
 *                                              
 * sauce: https://asciiart.cc/view/12307
 */

/*
Author: Artemis Ulysses Tack
Class: CPR E 185
Section: 2
Date: 2024-03-05
License: GPLv3

Copyright (C) 2024 Artemis Ulysses Tack

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
This program is a quiz game. The user enters a 'magic number' to start the game. 
The game then generates a quiz based on this number. The user's responses to the quiz 
questions are stored in character arrays. The user's grade and points are tracked 
throughout the game. The program uses the standard libraries stdio, stdlib, strings, 
unistd, time, and ctype.
*/

// Custom function declarations 
int makeQuestionLowercase(char question[]);
int loadingScreen();

// included libraries (also #supportLibraries and obligitory #fuckTheIowaGOP)
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// main function
int main() {

    // variable declarations 
    int magicNumber;
    int quizNumber;
    int grade = 0;
    double points = 0;
    char question1[10];
    char question2;
    char question3[10];
    char retake[5];
    double overallGrade;
    int attempts = 0;

    quizStart:

    // introduction 
    printf("---------------------------------\n");
    printf("Welcome to the mystical quiz of CPR E 185\n");
    magic_number:
    printf("Choose your magic number between 1 and 9 to begin\n");
    scanf("%d", &magicNumber);

    // checking if the magic number is between 1 and 9
    if (magicNumber < 1 || magicNumber > 9) {
        printf("Ope, looks like your magic number doens't quite look right. Try again!\n");
        goto magic_number;
    }
    printf("---------------------------------\n");

    // generating the quiz number that the user will take 
    srand (magicNumber);
    quizNumber = rand() % 3 + 1;

    // outputing the quiz number to the user
    printf("---------------------------------\n");
    printf("Your quiz number is: %d\n", quizNumber);
    printf("Enjoy :)\n");
    printf("---------------------------------\n");

    // The content of each quiz 
    while (quizNumber == 1) {

        // question 1
        quizOneQuestionOne:

        printf("---------------------------------\n");
        printf("Please type 'true' or 'false' for the following question (not case sensitive)\n");
        printf("Question 1: true or false, in the context of Linux, when pronouncing 'gnu' or 'gnome' the g is silent\n");
        scanf("%s", question1);

        // memory saftey because I'm a programming goddess
        if (strlen(question1) > 10) {
            exit(0);
        }

        // making the question lowercase
        makeQuestionLowercase(question1);

        // checking to see if the answer is correct
        if (strcmp(question1, "false") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizOneQuestionOne;
            }
            points -= 15;
            goto quizOneQuestionOne;
        }

        // question 2
        quizOneQuestionTwo:

        printf("---------------------------------\n");
        printf("Please type the corresponding letter for the following question (not case sensitive)\n");
        printf("Question 2: Convert the decimal number 3477 to binary\n");
        printf("A) 110110010101\n");
        printf("B) 110110010110\n");
        printf("C) 110110010111\n");
        printf("D) 110110011000\n");
        scanf("%s", &question2);

        // checking to see if the answer is correct
        if (question2 == 'A' || question2 == 'a') {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizOneQuestionTwo;
            }
            points -= 15;
            goto quizOneQuestionTwo;
        }

        // question 3
        quizOneQuestionThree:

        printf("---------------------------------\n");
        printf("Please fill in the blank\n");
        printf("Question 3: To declare a string C, you would use what what syntax?: _______ stringName[10]\n");
        scanf("%s", question3);

        // Memory safety once again :)
        if (strlen(question3) > 10) {
            exit(0);
        }

        // checking to see if the answer is correct
        if (strcmp(question3, "char") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizOneQuestionThree;
            }
            points -= 15;
            goto quizOneQuestionThree;
        }
        overallGrade = points / 45;
        break;
    }

    while (quizNumber == 2) {

        // question 1
        quizTwoQuestionOne:

        printf("---------------------------------\n");
        printf("Please type 'true' or 'false' for the following question (not case sensitive)\n");
        printf("Question 1: true or false, this code is a correct way to declare an array and assing it with 4 values in C:\n");
        printf("int array[3] = {444, 69, 420, 666};\n");
        scanf("%s", question1);

        // memory saftey because I'm just that girl
        if (strlen(question1) > 10) {
            exit(0);
        }

        // making the question lowercase
        makeQuestionLowercase(question1);

        // checking to see if the answer is correct
        if (strcmp(question1, "false") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizTwoQuestionOne;
            }
            points -= 15;
            goto quizTwoQuestionOne;
        }

        // question 2
        quizTwoQuestionTwo:

        printf("---------------------------------\n");
        printf("Please type the corresponding letter for the following question (not case sensitive)\n");
        printf("Question 2: What is the best way to declare and initialize Avrogadro’s number (6.022 x 10^23) in scientific notation in C?\n");
        printf("A) 6.022 * 10^23\n");
        printf("B) 6.022 x 10^23\n");
        printf("C) 6.022e23\n");
        printf("D) 6.022 * 10e23\n");
        scanf("%s", &question2);

        // checking to see if the answer is correct
        if (question2 == 'C' || question2 == 'c') {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizTwoQuestionTwo;
            }
            points -= 15;
            goto quizTwoQuestionTwo;
        }

        // question 3
        quizTwoQuestionThree:

        printf("---------------------------------\n");
        printf("Please fill in the blank\n");
        printf("Question 3: To copy a string in C, you would use what function?: _______(spongebob, patrick);\n");
        scanf("%s", question3);

        // Memory safety once again :)
        if (strlen(question3) > 10) {
            exit(0);
        }

        // checking to see if the answer is correct
        if (strcmp(question3, "strcpy") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizTwoQuestionThree;
            }
            points -= 15;
            goto quizTwoQuestionThree;
        }

        overallGrade = points / 45;
        break;
    }

    while (quizNumber == 3) {
        
        // question 1
        quizThreeQuestionOne:

        printf("---------------------------------\n");
        printf("Please type 'true' or 'false' for the following question (not case sensitive)\n");
        printf("Question 1: true or false, in C, a char variable is stored in the memory as a binary number\n");
        scanf("%s", question1);

        // memory saftey cuz I'm dat bitch
        if (strlen(question1) > 10) {
            exit(0);
        }

        // making quesiton 1 lowercase
        makeQuestionLowercase(question1);

        // checking to see if the answer is correct
        if (strcmp(question1, "true") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizThreeQuestionOne;
            }
            points -= 15;
            goto quizThreeQuestionOne;
        }

        // question 2
        quizThreeQuestionTwo:

        printf("---------------------------------\n");
        printf("Please enter the corresponding letter (not case sensitive)\n");
        printf("Question 2: Which of the following is a vaild variable declaration in C\n");
        printf("A) int 1stVar;\n");
        printf("B) integer firstVar;\n");
        printf("C) int firstBar\n");
        printf("D) ~coolVars~\n");
        scanf("%s", &question2);

        if (question2 == 'C' || question2 == 'c') {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizThreeQuestionTwo;
            }
            points -= 15;
            goto quizThreeQuestionTwo;
        }

        // question 3
        quizThreeQuestionThree:

        printf("---------------------------------\n");
        printf("Please fill in the blank (not case sensitive)\n");
        printf("Question 3: The int main fucntion always returns a _______ value?\n");
        scanf("%s", question3);

        // Memory safety because I'm a bad ass cybersecurity beotch
        if (strlen(question3) > 10) {
            exit(0);
        }

        // making question 3 lowercase
        makeQuestionLowercase(question3);

        // Checking if the answer is right
        if (strcmp(question3, "integer") == 0) {
            points += 15;
        }
        else {
            printf("Sorry, try again\n");
            if (points < 0) {
                goto quizThreeQuestionThree;
            }
            points -= 15;
            goto quizThreeQuestionThree;
        }

        overallGrade = points / 45;
        break;

    }

    // increasing the quiz attempts by 1 each time the quiz is run
    attempts++;

    // The final part that puts everything together and prints the results 
    printf("---------------------------------\n");
    printf("Thanks for taking this quiz. Please wait a moment while we calculate your results\n");

    // An overly complicated loading screen
    loadingScreen();

    printf("\nYour final resutls just arrived! You got %.2lf percent!\n", overallGrade * 100 / attempts);

    // Asking if the user will retake the quiz
    printf("Are you unhappy with your grade?!?!?!? If the answer is yes type 'yes' to retake this quiz. Otherwise type 'no' to exit\n");
    printf("(Scores are averaged across all attempts)\n");

    // memory saftey because I have a very big brain
    scanf("%s", retake);
    if (strlen(retake) > 5) {
        exit(0);
    }
    printf("---------------------------------\n");

    // Checking if the user wants to retake the quiz
    if (strcmp(retake, "yes") == 0 || strcmp(retake, "Yes") == 0 || strcmp(retake, "YES") == 0) {
        goto quizStart;
    }
    else {
        printf("Bye!\n");
        exit(0);
    }
}

// custom functions

// function to make a question lowercase
int makeQuestionLowercase(char question[]) {
    for (int i = 0; i < strlen(question); i++) {
        question[i] = tolower(question[i]);
    }
    return 0;
}

// function to make a simple loading screen that reminds me of the Arch Linux pacman install loading bar
int loadingScreen() {

    // Some weird time lord shit
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 250000000L;

    // ASCII Art frames graciously made by chatGPT because I'm really bad at art :(
    char* frames[21] = {
        "\nC...................",
        " c..................",
        "  C.................",
        "   c................",
        "    C...............",
        "     c..............",
        "      C.............",
        "       c............",
        "        C...........",
        "         c..........",
        "          C.........",
        "           c........",
        "            C.......",
        "             c......",
        "              C.....",
        "               c....",
        "                C...",
        "                 c..",
        "                  C.",
        "                   c",
        "                    \n",
    };

    // Loop to animate frames
    for (int i = 0; i < 21; ++i) {
        printf("\r%s", frames[i]);
        fflush(stdout);
        nanosleep(&sleepTime, NULL);
    }
    printf("\n");
    return 0;
}