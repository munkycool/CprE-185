/*
Author: Artemis Tack
Class: CPR E 185
Section: 2
Date: 2024-02-13
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
int main ()
{
int v = 4;
int w = 1;
int x = 18;
int y = 22;
int z = 11;

if(!((z % x == w || y - z == z) && (y - x == v && ! (y % x== v))))
{
printf("W");
}
else if (y - z == 11){
printf ("L");
}
else {
printf("K");
}
}