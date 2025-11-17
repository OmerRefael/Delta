/*------------------------------------------------------
* Filename: max.c
* Description: Program to set in z varible the max between two numbers
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - et in z varible the max between two numbers, and print its value
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning (indicate success or fail of the program)
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int x = 10;
    int y = 4;

    int z = y>x? y : x;
    printf("The value of z is %d", z);

    return 0;
}