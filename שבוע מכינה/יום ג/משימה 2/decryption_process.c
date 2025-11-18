/*------------------------------------------------------
* Filename: decryption_process.c
* Description: The program gets array of 26 numbers and dectypt the array to the ascii code of the letters in the decryptes message
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decryption_process.h"

#define INDEX_OF_FIRST_MEMBER 0
#define DIVIDED 0

#define get_index_of_first_member_in_second_half(size)  size/2;


typedef enum{
    FALSE = 0,
    TRUE = 1
}Bool;

/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - switch_first_half_of_arr_with_second_half 
*
* Function Purpose - switch betweeen the first half and the second half of the arr
*
* Parameters –  arr: int * - the array we will change
*               size: size_t- the size of the array
*
* Return numbers - void 
*
* Author - Omer Refael
-------------------------------------------------------*/
void switch_first_half_of_arr_with_second_half(int *arr, size_t size);

/*------------------------------------------------------
* Function Name - decrease_each_member_by_the_prev_member 
*
* Function Purpose - decrease each member in the array by the previos member
*
* Parameters –  arr: int * - the array we will change
*               size: size_t- the size of the array
*
* Return numbers - void 
*
* Author - Omer Refael
-------------------------------------------------------*/
void decrease_each_member_by_the_prev_member(int *arr, size_t size);

/*------------------------------------------------------
* Function Name - shift_members_in_circle 
*
* Function Purpose - shift the members by number forward ot backwork in circle
*
* Parameters –  arr: int * - the array we will change
*               size: size_t- the size of the array
*               rotate_by: int - the step size of roataing each member
*               rotate_forward: Bool: - is to rotate forward or not(which means backword)
*
* Return numbers - void 
*
* Author - Omer Refael
-------------------------------------------------------*/
void shift_members_in_circle(int *arr, size_t size, int rotate_by, Bool rotate_forward);

/*------------------------------------------------------
* Function Name - devide_even_member 
*
* Function Purpose - devide each member that has even index in the array by  member
*
* Parameters –  arr: int * - the array we will change
*               size: size_t- the size of the array
*               number: int - the number we will use for devide by each member
*
* Return numbers - void 
*
* Author - Omer Refael
-------------------------------------------------------*/
void devide_even_member(int *arr, size_t size, int number);

/*------------------------------------------------------
* Function Name - decrease_members 
*
* Function Purpose - decrease each member in the array by  member
*
* Parameters –  arr: int * - the array we will change
*               size: size_t- the size of the array
*               number: int - the number we will use for decrease from each member
*
* Return numbers - void 
*
* Author - Omer Refael
-------------------------------------------------------*/
void decrease_members(int *arr, size_t size, int number);


void decrypt_arr(int *arr, size_t size){
    switch_first_half_of_arr_with_second_half(arr, size);
    decrease_each_member_by_the_prev_member(arr, size);
    shift_members_in_circle(arr, size, 5, TRUE);
    devide_even_member(arr, size, 7);
    shift_members_in_circle(arr, size, 4, FALSE);
    decrease_members(arr, size, 5);
}


void switch_first_half_of_arr_with_second_half(int *arr, size_t size){
    int left = INDEX_OF_FIRST_MEMBER;
    int right = get_index_of_first_member_in_second_half(size);
    int temp;

    while(right < size){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right++;
    }
}

void decrease_each_member_by_the_prev_member(int *arr, size_t size){
    for (int i = size -1 ; i > INDEX_OF_FIRST_MEMBER; i--){
        arr[i] -= arr[i-1];
    }
}

void shift_members_in_circle(int *arr, size_t size, int rotate_by, Bool rotate_forward){
    int* temp_arr;

    temp_arr = (int *)calloc(size, sizeof(int));
    check_allocation(temp_arr);

    memcpy(temp_arr, arr, size * sizeof(int));
    
    for(int i = 0; i < size; i++){
        if (rotate_forward){
            arr[i] = temp_arr[(i+rotate_by)%size];
        }
        else{
            arr[i] = temp_arr[(i+size-rotate_by)%size];
        }
    }

    free(temp_arr);
}

void devide_even_member(int *arr, size_t size, int number){
    for(int i = 0; i < size; i++){
        if (i%2 == DIVIDED){
            arr[i] /= number;
        }
    }
}

void decrease_members(int *arr, size_t size, int number){
    for(int i = 0; i < size; i++){
        arr[i] -= number;
    }
}