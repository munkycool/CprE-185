/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:	Artemis Tack																 -
- 	Section: 2														 -
-	NetID:	uly@iastate.edu															     -
-	Date:	2024-02-14																 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int coolio(int argc, char *argv[])
{
    int i, j;

    printf("Enter an integer: "); // added mising ending semicolon
    scanf("%d", &i);

    printf("Enter another integer: "); // added closing "
    scanf("%d", &j); // added missing ending semicolon

    if (j % i == 0)
    {
        printf("%d divides %d\n", i, j);

    } else
    { // added missing opening bracket
        printf("%d does not divide %d\n", i, j); //fixed the typo in the printf statement
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}
