/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions
- -	Name: Artemis Tack
-
- 	Section: 2
- -	NetID:    uly@iastate.edu
- -	Date: 2024-02-10
-
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes
-
-----------------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int minutes(int t);
int seconds(int t);
int milliseconds(int t);

/*----------------------------------------------------------------------------
-	                                Notes -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation
-
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
  /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
  int t;
  double ax, ay, az;

  while (1) {
    scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

    /* CODE SECTION 0 */
    printf("Echoing output: %8.3d, %7.4lf, %7.4lf, %7.4lf\n", t, ax, ay, az);

    /* 	CODE SECTION 1 */
    printf("At %d ms, the acceleration's magnitude was: %lf\n", t,
           magnitude(ax, ay, az));

    /* 	CODE SECTION 2 */

    printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
           minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
  }

  return 0;
}

/* Put your functions here */

/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z) {
  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int minutes(int t) { return (t * 1.7E-7); }

int seconds(int t) { return (t * 0.001); }

int milliseconds(int t) { return (t); }
