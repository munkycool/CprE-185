/*
Author: Artemis Ulysses Tack
Class: CPR E 185
Section: 2
Date: 2024-02-21
License: GPLv3

Copyright (C) 2024 Artemis Tack

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

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

int close_to_gy(double tolerance, double point_gy, double value);
int close_to_gx(double tolerance, double point_gx, double value);
double magnitude(double x, double y, double z);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
    double tolerance = 0.05;
    double point_gy = 1.0;
    double point_gx = 1.0;
    double value = 1;
    double last_printed_gy = 0;
    double last_printed_gx = 0;


    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
            &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        magnitude(ax, ay, az);


        while (magnitude(ax, ay, az) <= 0.01)
        {
            scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
                  &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

            /* printf for observing values scanned in from ds4rd.exe,
             * be sure to comment or remove in final program */

            point_gy = gy;
            point_gx = gx;

            if (close_to_gy(tolerance, point_gy, value = 0.97) && last_printed_gy != 0.97)
            {
                printf("Facing up\n");
                last_printed_gy = 0.97;
            }
            else if (close_to_gy(tolerance, point_gy, value = -1.0) && last_printed_gy != -1.0)
            {
                printf("Facing down\n");
                last_printed_gy = -1.0;
            }
            else if (close_to_gy(tolerance, point_gy, value = 0.5) && last_printed_gy != 0.5)
            {
                printf("On its horizontal side facing up\n");
                last_printed_gy = 0.5;
            }
            else if (close_to_gy(tolerance, point_gy, value = -0.5) && last_printed_gy != -0.5)
            {
                printf("On its horizontal side facing down\n");
                last_printed_gy = -0.5;
            }

            if (close_to_gx(tolerance, point_gx, value = -0.97) && last_printed_gx != -0.97)
            {
                printf("Laying on its right side\n");
                last_printed_gx = -0.97;
            }
            else if (close_to_gx(tolerance, point_gx, value = 0.97) && last_printed_gx != 0.97)
            {
                printf("Laying on its left side\n");
                last_printed_gx = 0.97;
            }

            if (triangle == 1)
            {
                exit(0);
            }

            /* It would be wise (mainly save time) if you copy your code to calculate
             * the magnitude from lab03-1.c. You will also need to copy your
             * prototypes and functions to the appropriate sections in this program. */

            // printf("The acceleration's current magnitude is: %lf\n", t, magnitude(ax, ay, az));
        }
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

int close_to_gy(double tolerance, double point_gy, double value)
{
    if (value >= point_gy - tolerance && value <= point_gy + tolerance)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int close_to_gx(double tolerance, double point_gx, double value)
{
    if (value >= point_gx - tolerance && value <= point_gx + tolerance)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double magnitude(double x, double y, double z) {
  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}