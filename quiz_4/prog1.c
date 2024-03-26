/*
Author: Artemis Ulysses Tack
Class: CPR E 185
Section: 2
Date: 2024-02-19
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
#include <stdlib.h>


int main() {
    char password[50];

    printf("Please enter a simple password: ");
    scanf("%s", password);

    for (int i = 0; i < 50; i++) {

        if (password[i] == 'i') {
            password[i] = '1';
        }
        if (password[i] == 'a') {
            password[i] = '@';
        }
        if (password[i] == 'm') {
            password[i] = 'M';
        }
        if (password[i] == 'B') {
            password[i] = '8';
        }
        if (password[i] == 's') {
            password[i] = '$';
        }
    }

    printf("Your new password is: %s\n", password);
    printf("\nPlease note that length is usually the most immportant factor in password security (barring phishing and other social engineering fun),\nso you're new password might not neccessarily be considered secure. - sencerily a cybersecurity major\n");

}