/*------------------------------------------------------
* Filename: median.c
* Description: The program get unlimeted numbers, and create array of these numbers, and prints its median
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define FAILURE_STATUS 1
#define START_INDEX 0

/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - check_allocation 
*
* Function Purpose - check if the allocation success, and if not exit
*
* Parameters – ptr: void* - the ptr of the allocation
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
void check_allocation(void *ptr);

/*------------------------------------------------------
* Function Name - create_arr_by_user 
*
* Function Purpose - creates the array of the user
*
* Parameters –  size: size_t * - the size paramter of the array we will update
*
* Return numbers - coid
*
* Author - Omer Refael
-------------------------------------------------------*/
int* create_arr_by_user(size_t *size);

/*------------------------------------------------------
* Function Name - sort_arr 
*
* Function Purpose - creates the array of the user
*
* Parameters –  arr:int * - the array we want to sort
*               size: size_t  - the sizeof the array 
*
* Return numbers - coid
*
* Author - Omer Refael
-------------------------------------------------------*/
void sort_arr(int *arr, size_t size);

/*------------------------------------------------------
* Function Name - comp 
*
* Function Purpose - compare between two numbers
* Parameters –  a:const void*  -the first number
*               b: const void* - the second number
*
* Return numbers - int
*
* Author - Omer Refael
-------------------------------------------------------*/
int comp(const void* a, const void* b);

/*------------------------------------------------------
* Function Name - get_median_of_sorted_arr 
*
* Function Purpose - get the median of the sorter array 
*
* Parameters –  arr:int * - the sorted array
*               size: size_t  - the size of the array 
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
int get_median_of_sorted_arr(int *arr, size_t size);

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - get unlimeted numbers from the user, and create array of these numbers, and prints its median
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int *arr;
    size_t size = 0;

    printf("Please enter numbers:(whitespaces wont stop the program)\n");
    arr = create_arr_by_user(&size);

    sort_arr(arr, size);
    printf("the median of the arr is %d\n", get_median_of_sorted_arr(arr, size));

    free(arr);
    return 0;
}

void check_allocation(void *ptr){
    if (ptr == NULL) exit(EXIT_FAILURE);
}

int* create_arr_by_user(size_t *size){
    int *arr;
    int index = START_INDEX;
    int number;
    *size = BUFFER_SIZE;

    arr = (int *)calloc(*size, sizeof(int));
    check_allocation(arr);

    while (scanf("%d", &number) == 1){
        arr[index] = number;
        index++;

        if (index == *size - 1){
            *size += BUFFER_SIZE;
            arr = (int *)realloc(arr, *(size)*sizeof(int));
            check_allocation(arr);
        }
    }

    /*no input*/
    if (index == START_INDEX) {printf("no input!\n"); free(arr); exit(FAILURE_STATUS);}

    /*delete extra space*/
    *size = index;
    arr = (int *)realloc(arr, (*size)*sizeof(int));
    check_allocation(arr);

    return arr;
}

void sort_arr(int *arr,  size_t size){
    qsort(arr, size, sizeof(int), comp);
}

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int get_median_of_sorted_arr(int *arr,  size_t size){
    return arr[(int)(size / 2)];
}