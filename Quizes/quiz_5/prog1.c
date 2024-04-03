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

double averageGrade(double hwScore[4]) {
    double total = 0;
    int i;
    for (i = 0; i < 4; i++) {
        total += hwScore[i];
    }
    return total / 4;
}

char letterGrade(double averageGrade) {
    if (averageGrade >= 85 && averageGrade <= 100) {
        return 'A';
    } 
    else if (averageGrade >= 75 && averageGrade < 85) {
        return 'B';
    } 
    else if (averageGrade >= 60 && averageGrade < 75) {
        return 'C';
    } 
    else {
        return 'F';
    }
}

int main() {
    double hwScore[2][4];
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            printf("Enter student %d's homework grade %d: ", i + 1, j + 1);
            scanf("%lf", &hwScore[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        printf("The average grade for student %d is %.2lf", i + 1, averageGrade(hwScore[i]));
        printf(" and the letter grade is %c\n", letterGrade(averageGrade(hwScore[i])));
    }

    return 0;
}