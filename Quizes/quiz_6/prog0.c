/*
Author: Artemis Ulysses Tack
Class: CPR E 185
Section: 2
Date: 2024-03-26
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

// Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Variable declarations
    char first_name[50];
    char last_name[50];
    char* full_name = NULL;
    int name_length = 0;

    // Gather user input
    printf("Enter your first name: ");
    scanf("%s", first_name);
    printf("Enter your last name: ");
    scanf("%s", last_name);

    // Check if the first name or last name is too long
    if (strlen(first_name) > 50 || strlen(last_name) > 50) {
        printf("Error: first name or last name is too long\n");
        exit(0);
    }

    // Allocate memory for the full name
    name_length = strlen(first_name) + strlen(last_name) + 1;
    full_name = (char*)malloc(name_length * sizeof(char));

    // Check if memory allocation failed
    if (full_name == NULL) {
        printf("Error: memory allocation failed\n");
        exit(0);
    }

    // Concatenate the first name and last name
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    // Output the full name
    printf("\nYour first name is: %s\n", first_name);
    printf("\nYour last name is: %s\n", last_name);
    printf("\nYour full name is: %s\n", full_name);

    // Free the allocated memory
    free(full_name);
}