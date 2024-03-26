/*
Author: Artemis Tack
Class: CPR E 185
Section: 2
Date: 2024-02-12
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

// Included libraries (#supportAndFundLocalLibraries)
#include <stdio.h>

// User defined function to calcuate the total driving cost 
double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
    return (drivenMiles / milesPerGallon) * dollarsPerGallon;
}

// A very cool main function
int main() {

    // Some very nice variable declarations
    double drivenMiles;
    double milesPerGallon;
    double dollarsPerGallon;

    // Getting the wonderful user's input
    printf("Enter the number of miles driven: ");
    scanf("%lf", &drivenMiles);

    printf("Enter the miles per gallon: ");
    scanf("%lf", &milesPerGallon);

    printf("Enter the cost per gallon: ");
    scanf("%lf", &dollarsPerGallon);

    // Making the user sad by printing the total driving cost 
    printf("The driving cost is %lf\n", DrivingCost(drivenMiles, milesPerGallon, dollarsPerGallon));

    return 0;

}