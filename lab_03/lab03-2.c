/*
Author: Artemis Tack
Class: CPR E 185
Section: 2
email: uly@iastate.edu, artemis@art3mix.com
Date: 2024/02/10
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

/*----------------------------------------------------------------------------
-								Includes
-
-----------------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
#include <unistd.h>

/*----------------------------------------------------------------------------
-	                            Prototypes -
-----------------------------------------------------------------------------*/
int number(int a, int b, int c, int d);

/*----------------------------------------------------------------------------
-	                                Notes -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation
-
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {

  int a; // square
  int b; // x
  int c; // circle
  int d; // triangle

  while (1) {

    scanf("%d, %d, %d, %d", &a, &b, &c, &d);

    printf("%d\n", number(a, b, c, d));

    fflush(stdout);
  }

  return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

int number(int a, int b, int c, int d) {
  if (a + b + c + d == 1) {
    return 1;
  } else if (a + b + c + d == 2) {
    return 2;
  } else if (a + b + c + d == 3) {
    return 3;
  } else if (a + b + c + d == 4) {
    return 4;
  }
}
