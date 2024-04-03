/*
Author: Artemis Tack
Class: CPR E 185
Section: 2
Date: 2024/02/05
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

int main() {
    
    // Declares the variable
    long int phone_number;

    // Gets the phone number from the inputer
    printf("Enter a phone number: ");
    scanf("%ld", &phone_number);

    // Prints their phone number, wonderfully arranged for those who can't easily parse 9 digits
    printf("The area code is: %ld\n", phone_number / 10000000);
    printf("The exchange code is: %ld\n", (phone_number / 10000) % 1000);
    printf("The user number is: %ld\n", phone_number % 10000);

}