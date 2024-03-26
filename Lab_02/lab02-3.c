/*----------------------------------------------------------------------------
- SE 185: Lab 02 - Solving Simple Problems in C -
- Name: Artemis Tack
- Section: 2
- NetID: uly@iastate.edu
- Date: Wed Jan 31 2024
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
- Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
- Implementation
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result); // changed the %lf to %d

    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n", integer_result); // added the integer_result tag to the printf statement

    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result); //added the %lf tag to the printf statement

    return 0;
}
