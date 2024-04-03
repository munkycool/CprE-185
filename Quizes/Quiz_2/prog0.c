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

// Included libraries (#supportLibraries)
#include <stdio.h>

int main() {

    // Variable declarations 
    char firstName[20];
    char lastName[20];
    char major[30];
    char year[20];
    int gradYear;

    // Get the user input 
    printf("Enter your first name: ");
    scanf("%s", firstName);

    printf("Enter your last name: ");
    scanf("%s", lastName);

    printf("Enter your major: ");
    scanf("%s", major);

    printf("Enter your year in college: ");
    scanf("%s", year);

    printf("Enter your graduation year: ");
    scanf("%d", &gradYear);

    // Prints the users input
    printf("Name (last, first): %s, %s\n", lastName, firstName);
    printf("Major: %s\n", major);
    printf("Year: %s\n", year);
    printf("Graduation year: %d\n", gradYear);

    return 0;
    
}