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

    // included libraries

#include <stdio.h>
#include <math.h>

    // Making a fun little thing that calculated the pythagorean theorem 

int main()
{

    // Variable declarations 

    double coolA = 0.0;
    double coolB = 0.0;
    double coolC = 0.0;
    double coolC_unk = 0;
    double coolB_unk = 0;
    double coolA_unk = 0;



    // The trangle inputs 

    printf("Enter the known side lengths of the triangle, and use '0' for the unknown side. \n");

    // Input for side A

    printf("Enter the length of side A: ");
    if (coolA >= 0)
    {
    scanf("%lf", &coolA);
    }
    else if (coolA == 0)
    {
        coolA_unk = 0;
        scanf("%lf", &coolA_unk);
    }
    else 
    {
        printf("Invalid input. Please enter a number or a 0 silly");
    }

    // Input for side B

    printf("Enter the length of side B: ");
    if (coolB >= 0)
    {
    scanf("%lf", &coolB);
    }
    else if (coolB == 0)
    {
        coolB_unk = 0;
        scanf("%lf", &coolB_unk);
    }
    else 
    {
        printf("Invalid input. Please enter a number or a 0 silly.");
    }

    // Input for side C

    printf("Enter the length of side C: ");
    if (coolC >= 0)
    { 
        scanf("%lf", &coolC);
    }
    else if (coolC == 0)
    {
        coolC_unk = 0;
        scanf("%lf", &coolC_unk);
    }
    else 
    {
        printf("Invalid input. Please enter a number or a 0 silly.");
    }

    // The fun part, the calculations 
    if (coolA > 0 && coolB > 0 && coolC_unk == 0) // we know A and B, but not C
    {
    coolC = sqrt(pow(coolA, 2) + pow(coolB, 2));
    }
    else if (coolA > 0 && coolC > 0 && coolB_unk == 0) // we know A and C, but not B
    {
    coolB = sqrt(pow(coolC, 2) - pow(coolA, 2));
    }
    else if (coolB > 0 && coolC > 0 && coolA_unk == 0) // we know B and C, but not A
    {
    coolA = sqrt(pow(coolC, 2) - pow(coolB, 2));
    }
    else if (coolA > 0 && coolB > 0 && coolC > 0) // we know all three sides
    {
    printf("You entered all three side lengths. The triangle is already solved silly.\n");
    }


    // The output

    if (isnan(coolA) || isnan(coolB) || isnan(coolC))
    {
        printf("I don't know what you put in here, but it ain't a traingle silly.\n");
    }
    else {
    printf("Side A: %0.3lf\n", coolA);
    printf("Side B: %0.3lf\n", coolB);
    printf("Side C: %0.3lf\n", coolC);
    }

    return 0;

}