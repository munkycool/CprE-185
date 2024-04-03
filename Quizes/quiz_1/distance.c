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

// Libraries are important, fuck the Iowa State legislature 
#include <stdio.h>
#include <math.h>

int main() {

    // The wonderfully marvelous varibale declarations
    double mike_x, mike_y;
    double mary_x, mary_y;
    double garry_x, garry_y;
    double logan_x, logan_y;
    double school_x, school_y;
    double mikeDistance, maryDistance, garryDistance, loganDistance;


    // The school distances that I totally didn't forget the first time
    school_x = 15.55;
    school_y = 55.15;

    // equations for a green cyclops monster
    mike_x = 22.05;
    mike_y = 85.10;
    mikeDistance = sqrt(pow(mike_x - school_x, 2) + pow(mike_y - school_y, 2));

    // I hope Mary finds her lamb
    mary_x = 43.25;
    mary_y = 9.80;
    maryDistance = sqrt(pow(mary_x - school_x, 2) + pow(mary_y - school_y, 2));

    // No notes, only GARRY
    garry_x = 2.55;
    garry_y = 72.86;
    garryDistance = sqrt(pow(garry_x - school_x, 2) + pow(garry_y - school_y, 2));

    // God, I hope it's not the Paul
    logan_x = 15.15;
    logan_y = 40.40;
    loganDistance = sqrt(pow(logan_x - school_x, 2) + pow(logan_y - school_y, 2));

    // Printing the results of all the distances. I hope it's not miles...
    printf("The E distance for Mike is: %f\n", mikeDistance);
    printf("The E distance for Mary is: %f\n", maryDistance);
    printf("The E distance for Garry is: %f\n", garryDistance);
    printf("The E distance for Logan is: %f\n", loganDistance);

    return 0;
}