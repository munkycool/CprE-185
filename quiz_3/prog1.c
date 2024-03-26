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
#include <string.h>

int main() {
    char userName[30];
    char password[30];

    printf("Enter your username: ");
    scanf("%s", userName);

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(userName, "se185@iastate.edu") == 0 && strcmp(password, "ds4rd") == 0){
        printf("Success!\n");
    } else {
        printf("Username or password is incorrect.\n");
    }

    return 0;
}
