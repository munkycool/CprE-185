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
  int grade = 0;

  printf("Enter your grade: ");
  scanf("%d", &grade);

  if (grade > 100) {
    printf("Invalid grade\n");
  } else if (grade >= 93) {
    printf("Your grade letter is A\n");
  } else if (grade >= 90) {
    printf("Your grade letter is A-\n");
  } else if (grade >= 87) {
    printf("Your grade letter is B+\n");
  } else if (grade >= 83) {
    printf("Your grade letter is B\n");
  } else if (grade >= 80) {
    printf("Your grade letter is B-\n");
  } else if (grade >= 77) {
    printf("Your grade letter is C+\n");
  } else if (grade >= 73) {
    printf("Your grade letter is C\n");
  } else if (grade >= 70) {
    printf("Your grade letter is C-\n");
  } else if (grade >= 67) {
    printf("Your grade letter is D+\n");
  } else if (grade >= 63) {
    printf("Your grade letter is D\n");
  } else if (grade >= 60) {
    printf("Your grade letter is D-\n");
  } else if (grade >= 0) {
    printf("Your grade letter is F\n");
  } else {
    printf("Invalid grade\n");
  }
}
