/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: The program gets array of 8 numbers and another array of 8 chars, and print the value and the adress of each member
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 8 /*the size of the array*/
#define EXIT_FAILURE 1

#define check_allocation(ptr) if (!ptr) exit(EXIT_FAILURE);

typedef enum{
    UNKNOWN_TYPE,
    INT_ARR,
    CHAR_ARR
}ArrType;

/* Function declaration */
void *get_arr_from_user(size_t size, ArrType type);
void *malloc_arr(size_t size, ArrType type);
int get_integer_from_user();
char get_char_from_user();
void print_arr_details(void* arr, ArrType type);
void print_arr_details2(void* arr, ArrType type);

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - The program gets array of 8 numbers and another array of 8 chars, and print the value and the adress of each member
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int *nums_arr;
    char *chars_arr;

    printf("please enter 8 integers\n");
    nums_arr = (int *)get_arr_from_user(ARR_SIZE, INT_ARR);

    printf("please enter 8 chars\n");
    chars_arr = (char *)get_arr_from_user(ARR_SIZE, CHAR_ARR);

    printf("Integer array:\n");
    print_arr_details(nums_arr, INT_ARR);

    printf("Characters array:\n");
    print_arr_details(chars_arr, CHAR_ARR);

    free(nums_arr);
    free(chars_arr);

    return 0;
}

/*------------------------------------------------------
* Function Name - get_arr_from_user 
*
* Function Purpose - gets inputs from the user and create an array
*
* Parameters –  size: aize_t - the size of the array
*               type: ArrType - the type of the expected new array
*
* Return numbers - void *: the pointer of the new array
*
* Author - Omer Refael
-------------------------------------------------------*/
void* get_arr_from_user(size_t size, ArrType type){
    void *arr;
    arr = malloc_arr(size, type);

    for (int i = 0; i < ARR_SIZE; i++){
        if (type ==  INT_ARR) {
            ((int *)arr)[i] = get_integer_from_user();
        }
        else if (type == CHAR_ARR){
            ((char *)arr)[i] = get_char_from_user();
        }
    }

    return arr;
}

/*------------------------------------------------------
* Function Name - malloc_arr 
*
* Function Purpose - malloc the array
*
* Parameters –  size: aize_t - the size of the array
*               type: ArrType - the type of the  new array
*
* Return numbers - void *: the pointer of the new allocated array
*
* Author - Omer Refael
-------------------------------------------------------*/
void* malloc_arr(size_t size, ArrType type){
    void* allocated_arr;

    if (type ==  INT_ARR) {
        allocated_arr = malloc(size * sizeof(int));
    }
    else if (type == CHAR_ARR){ 
        allocated_arr = malloc(size * sizeof(char));
    }

    check_allocation(allocated_arr);
}

/*------------------------------------------------------
* Function Name - get_number_from_user 
*
* Function Purpose - gets number from the user
*
* Parameters –  no parameters
*
* Return numbers - integer: the number that the user entered
*
* Author - Omer Refael
-------------------------------------------------------*/
int get_integer_from_user(){
    int number;
    if (scanf("%d", &number) != 1){
        printf("Invalid Integer!");
        exit(EXIT_FAILURE);
    }

    return number;
}

/*------------------------------------------------------
* Function Name - get_char_from_user 
*
* Function Purpose - gets char from the user
*
* Parameters –  no parameters
*
* Return numbers - char: the char that the user entered
*
* Author - Omer Refael
-------------------------------------------------------*/
char get_char_from_user(){
    char c;
    if (scanf(" %c", &c) != 1){
        printf("Invalid Integer!");
        exit(EXIT_FAILURE);
    }
    
    return c;
}

/*------------------------------------------------------
* Function Name - print_arr_details 
*
* Function Purpose - prints for each member in the array its value and adress
*
* Parameters –  arr: void* - the pointer of the array (of integers or chars)
*               type: ArrType - the type of the array
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_arr_details(void *arr, ArrType type){
    for (int i = 0; i < ARR_SIZE; i++){
        if (type ==  INT_ARR){
            printf("0x%x: %d", &((int *)arr)[i], ((int *)arr)[i]);
        }
        else{
           printf("0x%x: %c", &((char *)arr)[i], ((char *)arr)[i]); 
        }
        
        if (i < ARR_SIZE - 1) printf(", ");
    }
    
    printf("\n");
}

/*print_arr_details second approch*/
void print_arr_details2(void *arr, ArrType type){
    for (int i = 0; i < ARR_SIZE; i++){
        if (type ==  INT_ARR){
            printf("0x%x: %d, ", &(*((int *)arr + i)), (*((int *)arr) + i));
        }
        else{
           printf("0x%x: %c, ", &(*((char *)arr + i)), (*((char *)arr) + i)); 
        }
        
        if (i < ARR_SIZE - 1) printf(", ");
    }
    
    printf("\n");
}
