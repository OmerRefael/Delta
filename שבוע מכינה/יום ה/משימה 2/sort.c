/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: The program  scanf from the user one input line in a safe way
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic_scanf.h"

#define SIZE 5

/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - sort 
*
* Function Purpose - sort the arr values
*
* Parameters – arr: *void[] - the array
*              size: size_t - the size of the array
*              comp: int (*) (const void*, const void*) - the function according to her, we compare members of the array
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void sort(void* arr[], size_t size, int (*comp) (const void*,const void*));

/*------------------------------------------------------
* Function Name - swap 
*
* Function Purpose - swap values between to members
*
* Parameters – a: void** - the ptr of the first member
*              b: void** - the ptr of the second member
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void swap(void **a, void **b);

/*------------------------------------------------------
* Function Name - cmp_by_alphabetical_order 
*
* Function Purpose - cmom[are by alphabetical_order
*
* Parameters – str1:const void** - the ptr of the first member
*              str2:const void** - the ptr of the second member
*
* Return numbers - int: number > 0 means str1 "bigger" then str2. otherwise it is small or less
*
* Author - Omer Refael
-------------------------------------------------------*/
int cmp_by_alphabetical_order(const void *str1, const void *str2);

/*------------------------------------------------------
* Function Name - cmp_by_length 
*
* Function Purpose - cmompare by length
*
* Parameters – str1:const void** - the ptr of the first member
*              str2:const void** - the ptr of the second member
*
* Return numbers - int: number > 0 means str1 "bigger" then str2. otherwise it is small or less
*
* Author - Omer Refael
-------------------------------------------------------*/
int cmp_by_length(const void *str1, const void *str2);

/*------------------------------------------------------
* Function Name - print_arr 
*
* Function Purpose - print the arr values
*
* Parameters – arr: *char[] - the strings array
*              size: size_t - the size of the array
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_arr(char *arr[], size_t size);


/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - scanf from the user one input line in a safe way
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    char *string1;
    char *string2;
    char *string3;
    char *string4;
    char *string5;

    char *arr[SIZE];

    printf_s("Enter 1 string: ");
    string1 = dyn_scanf();

    printf_s("Enter 2 string: ");
    string2 = dyn_scanf();

    printf_s("Enter 3 string: ");
    string3 = dyn_scanf();

    printf_s("Enter 4 string: ");
    string4 = dyn_scanf();

    printf_s("Enter 5 string: ");
    string5 = dyn_scanf();

    arr[0]=string1; arr[1]=string2; arr[2]=string3; arr[3]=string4; arr[4]=string5;

    sort((void **)arr, SIZE, cmp_by_length);
    print_arr(arr, SIZE);

    sort((void **)arr, SIZE, cmp_by_alphabetical_order);
    print_arr(arr, SIZE);

    free(string1);
    free(string2);
    free(string3);
    free(string4);
    free(string5);
    return 0;
}


void sort(void* arr[], size_t size, int (*comp) (const void*,const void*)){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((*comp)(arr[j], arr[j + 1]) > 0) { /*arr[j] > arr[j+1]*/
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(void **a, void **b){
    void *temp = *a;
    *a = *b;
    *b = temp;
}

int cmp_by_alphabetical_order(const void *str1, const void *str2){
    const char *string1 = (const char *)str1;
    const char *string2 = (const char *)str2;

    size_t length = strlen(string1) < strlen(string2)? strlen(string1): strlen(string2);  
    for (int i = 0; i < length; i++){
        if (string1[i] != string2[i]){
            return string1[i] - string2[i];
        }
    }
    return strlen(string1) < strlen(string2)? -1 : 1;
}

int cmp_by_length(const void *str1, const void *str2){
    return strlen((const char *)str1) - strlen((const char *)str2);
}


void print_arr(char *arr[], size_t size){
    for (int i = 0; i < size; i++){
        printf_s("%s", arr[i]);
        if (i < size -1) {
            printf_s(",");
        }
    }
    printf_s("\n");
}