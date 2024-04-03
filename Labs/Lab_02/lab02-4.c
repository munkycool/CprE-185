/*
Author: Artemis Tack
Class: CPR E 185
Section: 2
Date: 2024/01/31
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

#include <stdio.h>
#include <math.h>

int main()
{

    // Some fun math shit 
    double num1 = 6427.0;
    double num2 = 1725.0;
    double num3 = 22.0;
    double num4 = 3.0;
    
    printf("6427 + 1725 = %d\n", (int)num1 + (int)num2); //a
    printf("(6971 * 3925) - 95 = %d\n", (int)num1 * (int)3925 - 95); //b
    printf("79 + 12 / 5 = %.2lf\n", (double)79 + (double)12 / (double)5); //c
    printf("3640.0 / 107.9 = %.0lf\n", 3640.0 / 107.9); //d
    printf("(22 / 3) * 3 = %d\n", ((int)num3 / (int)num4) * (int)num4); //e
    printf("22 / (3 * 3) = %d\n", (int)num3 / ((int)num4 * (int)num4)); //f
    printf("22 / (3 * 3) = %.2lf\n", num3 / (num4 * num4)); //g
    printf("22 / 3 * 3 = %.2lf\n", num3 / num4 * num4); //h
    printf("(22.0 / 3) * 3.0 = %.2lf\n", (num3 / num4) * num4); //i
    printf("22.0 / (3 * 3.0) = %d\n", (int)num3 / ((int)num4 * (int)num4)); //j
    printf("22.0 / 3.0 * 3.0 = %.2lf\n", num3 / num4 * num4); //k

    // Calculate the area of a circle with a circumference of 23.567
    double circumference = 23.567;
    double radius = circumference / (2 * M_PI);
    double area = M_PI * pow(radius, 2);
    printf("The area of a circle with a circumference of %lf is %lf\n", circumference, area);

    // convert 14 feet to meters
    double feet = 14.0;
    double meters = feet / 3.28084;
    printf("14 feet is %lf meters\n", meters);

    // convert 76 degrees Fahrenheit to Celsius
    double fahrenheit = 76.0;
    double celsius = (fahrenheit - 32) * (5.0 / 9.0);
    printf("76 degrees Fahrenheit is %lf degrees Celsius\n", celsius);

    return 0;
}


