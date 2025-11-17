/*------------------------------------------------------
* Filename: print_chars.c
* Description: get number from the user, and print "square" that built by a char (that was selected according to the number value)
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define DEVIDED_FLAG 0 /*indicate that the number that was devided by other number, is indeed devided by without rest*/
#define SUCCESS_STATUS 0
#define FAILD_STATUS 1

#define check_number(x) if (x <= 0) {printf("Bad Input!\n"); exit(FAILD_STATUS);}

/* function declaration */
char get_printed_char_according_to_number(int number);
void print_chars(char printed_char, int number);

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - get number from the user, and print "square" (the size is by the number) that built by a char.
* The char was selected according to the number value
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning (indicate success or fail of the program)
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int number;
    char printed_char;

    printf("enter number:\n");
    scanf("%d", &number);

    check_number(number); /*if number is not valid, the program will exit*/

    printed_char = get_printed_char_according_to_number(number);
    print_chars(printed_char, number);

    return SUCCESS_STATUS;
}

/*------------------------------------------------------
* Function Name - get_printed_char_according_to_number 
*
* Function Purpose - according to the given number, return the accordingly char
*
* Parameters –  number: int - the number that the user chose
*
* Return numbers - char - the adjust char
*
* Author - Omer Refael
-------------------------------------------------------*/
char get_printed_char_according_to_number(int number){
    if (number%2 == DEVIDED_FLAG){
        return '*';
    }
    else if (number%3 == DEVIDED_FLAG){
        return '^';
    }
    else if (number%5 == DEVIDED_FLAG){
        return '%';
    }
    else{
        return '@';
    }
}

/*------------------------------------------------------
* Function Name - print_chars 
*
* Function Purpose - print the char as square where the size of the square is the number value
*
* Parameters –  printed_char: char - the char that will be printed
*               number: int - the number that the user chose
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_chars(char printed_char, int number){
    int row;
    int coulmn;
    for (row = 0; row < number; row++){
        for (coulmn = 0; coulmn < number; coulmn++){
            putchar(printed_char);
        }
        putchar('\n');
    }
}