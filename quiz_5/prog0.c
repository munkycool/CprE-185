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

int main() {
    double hwScore[5];
    double examScore[3];
    double hwTotal, examTotal, finalScore;
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Enter homework grade %d: ", i + 1);
        scanf("%lf", &hwScore[i]);
    }

    for (i = 0; i < 3; i++) {
        printf("Enter exam grade %d: ", i + 1);
        scanf("%lf", &examScore[i]);
    }

    hwTotal = hwScore[0] + hwScore[1] + hwScore[2] + hwScore[3] + hwScore[4];
    examTotal = examScore[0] + examScore[1] + examScore[2];
    finalScore = (hwTotal / 5) * 0.4 + (examTotal / 3) * 0.6;

    printf("Final score: %.2lf\n", finalScore);
}