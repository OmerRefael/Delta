/*------------------------------------------------------
* Filename: decryption.c
* Description: The program gets array of 26 numbers from the user and then decrypt the message according to the array
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decryption_process.h"

#define SIZE 26 /*the size of the arr*/
#define MAX_LENGTH_OF_INPUT 100 /*i assume that the max length of input is 100 chars*/


/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - scans from the user array of 15 numbers
*
* Parameters –  no parameters
*
* Return numbers - int * - the array that user selected
*
* Author - Omer Refael
-------------------------------------------------------*/
int* get_arr_from_user();

/*------------------------------------------------------
* Function Name - get_message 
*
* Function Purpose - decrypt the array and return the decrypted array
*
* Parameters –  arr: int * - the decrypted array of the numbers
*               size: size_t: the size of the array
*
* Return numbers - char * - the decrypted message
*
* Author - Omer Refael
-------------------------------------------------------*/
char* get_message(int *arr, size_t size);

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - scans from the user array of 15 numbers, and decryt the message
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {

    /* for test - the output need to be AAAAAA - {1120,1190,1680,70,560,630}; */

    int* arr;
    char* decrypted_msg;

    arr = get_arr_from_user(SIZE);
    decrypt_arr(arr, SIZE);

    decrypted_msg = get_message(arr, SIZE);
    printf("The message is: %s\n", decrypted_msg);

    free(arr);
    free(decrypted_msg);

    return 0;
}


int* get_arr_from_user(size_t size){
    int *arr;
    char buffer[MAX_LENGTH_OF_INPUT];
    char *token;
    int counter = 0;
    
    arr = (int *)calloc(size, sizeof(int)); 
    check_allocation(arr);

    printf("Please enter the array\n");
    fgets(buffer, MAX_LENGTH_OF_INPUT, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    token = strtok(buffer, " ,[]");
    while (token != NULL && counter <= size -1){
        arr[counter] = atoi(token);
        counter++;
        token = strtok(NULL, " ,[]");
    }

    return arr;
}



char* get_message(int *arr, size_t size){
    char* msg;
    
    msg = (char *)calloc(size + 1, sizeof(char)); /* +1 for the null terminator*/
    check_allocation(msg);

    for(int i = 0; i < size; i++){
        msg[i] = (char)arr[i];
    } 

    *(msg + size) = '\0';
    return msg;
}