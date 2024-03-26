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
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave_length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int coolio(int argc, char *argv[])
{
    double speed_of_light; // changed all occurnces of "speed_of_light!" to "speed_of_light" because c variables can't have an exclamation point
    double wave_length; // changed all occurnces of "wave-length" to "wave_length" because c variables can't have a hyphen
    double length_in_meters; // changed all occurnces of "~length_in_meters" to "length_in_meters" because c variables can't start with a tilda
    // double const plank; // changed the order to "double const" instead of "plank const"
    double energy; // Changed all occurences of "0energy" to "energy" because c variables can't start with a number

    double const plank = 6.62606957 * pow(10, -34); // Planck's constant // changed the order from "plank const" to "const plank". Also added it as a double type 
    speed_of_light = 2.99792458 * pow(10, 8); // Constant for the speed of light
    wave_length = 0;
    length_in_meters = 0;
    energy = 0;

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave_length.\n");
    printf("Please input a wave_length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave_length.\n");

    scanf("%lf", &wave_length);

    if (wave_length > 0.0)
    {
        length_in_meters = wave_length / pow(10, 9); // Converting nano-meters to meters // Made this one line
        energy = (plank * speed_of_light) / length_in_meters; // Calculating the energy of 1 photon // deleted the occurnce of "const" from the plank variable
        printf("A photon with a wave_length of %08.3lf nano-meters, carries \napproximately %030.25lf joules of energy.", wave_length, energy); // added a parenthesis to the printf function, and deleted a ". Also made it one line.
    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}
