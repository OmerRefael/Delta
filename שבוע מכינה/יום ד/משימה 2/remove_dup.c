/*------------------------------------------------------
* Filename: remove_dup.c
* Description: The program get arranged array, and create an new array without duplicate values
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
#define FAILURE_STATUS 1


/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - check_allocation 
*
* Function Purpose - check if the allocation success, and if not exit
*
* Parameters – ptr: void* - the ptr of the allocation
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void check_allocation(void *ptr);

/*------------------------------------------------------
* Function Name - remove_dup 
*
* Function Purpose - create an new array without duplicate values of the origin (incnreasing) array
*
* Parameters – arr: int []] - the origin array
*              origin_size: size_t - the size of the origin arrray
*               new_arr_size: size_t * - the size we will update of the new created array
*
* Return numbers - int *-  the new created array, which without duplicates
*
* Author - Omer Refael
-------------------------------------------------------*/
int* remove_dup1(int arr[], size_t origin_size, size_t *new_arr_size);
int remove_dup2(int arr[], int *removed_dup_arr, size_t origin_size);
void remove_dup3(int arr[], int *removed_dup_arr, size_t origin_size, size_t *new_arr_size);

/*------------------------------------------------------
* Function Name - print_arr 
*
* Function Purpose - print the arr values
*
* Parameters – arr: int* - the array
*              size: size_t - the size of the array
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_arr(int *arr, size_t size);


/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - createds new array without ducplicates
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int original_arr[SIZE] = {1,1,1,3,3,4,5,5,6,7,8,10};
    int *removed_dup_arr;
    size_t removed_dup_arr_size = 0;

    printf("The origin array:\n");
    print_arr(original_arr, SIZE);

    removed_dup_arr = remove_dup1(original_arr, SIZE, &removed_dup_arr_size);

    printf("The removed duplicate array:\n");
    print_arr(removed_dup_arr, removed_dup_arr_size);

    free(removed_dup_arr);
    return 0;
}

void check_allocation(void *ptr){
    if (ptr == NULL) exit(EXIT_FAILURE);
}

/*first version, that the main based on it*/
int* remove_dup1(int arr[], size_t origin_size, size_t *new_arr_size){
    int new_arr_index = 1;
    int *removed_dup_arr;
    *new_arr_size = origin_size;

    removed_dup_arr = (int *)malloc((*new_arr_size)*sizeof(int));
    check_allocation(removed_dup_arr);

    removed_dup_arr[0] = arr[0];
    for (int origin_arr_index = 1; origin_arr_index < origin_size; origin_arr_index++){
        if (arr[origin_arr_index] != arr[origin_arr_index-1]){
            removed_dup_arr[new_arr_index] = arr[origin_arr_index];
            new_arr_index++;
        }
    }

    /*delete extra space*/
    *new_arr_size = new_arr_index;
    removed_dup_arr = (int *)realloc(removed_dup_arr, (*new_arr_size)*sizeof(int));
    check_allocation(arr);

    return removed_dup_arr;
}

/*second version*/
int remove_dup2(int arr[], int *removed_dup_arr, size_t origin_size){
    int new_arr_index = 1;
    size_t new_arr_size = origin_size;

    removed_dup_arr = (int *)malloc(new_arr_size*sizeof(int));
    check_allocation(removed_dup_arr);

    removed_dup_arr[0] = arr[0];
    for (int origin_arr_index = 1; origin_arr_index < origin_size; origin_arr_index++){
        if (arr[origin_arr_index] != arr[origin_arr_index-1]){
            removed_dup_arr[new_arr_index] = arr[origin_arr_index];
            new_arr_index++;
        }
    }

    /*delete extra space*/
    new_arr_size = new_arr_index;
    removed_dup_arr = (int *)realloc(removed_dup_arr, new_arr_size*sizeof(int));
    check_allocation(arr);

    return new_arr_size;
}

/*third version*/
void remove_dup3(int arr[], int *removed_dup_arr, size_t origin_size, size_t *new_arr_size){
    int new_arr_index = 1;
    *new_arr_size = origin_size;

    removed_dup_arr = (int *)malloc((*new_arr_size)*sizeof(int));
    check_allocation(removed_dup_arr);

    removed_dup_arr[0] = arr[0];
    for (int origin_arr_index = 1; origin_arr_index < origin_size; origin_arr_index++){
        if (arr[origin_arr_index] != arr[origin_arr_index-1]){
            removed_dup_arr[new_arr_index] = arr[origin_arr_index];
            new_arr_index++;
        }
    }

    /*delete extra space*/
    *new_arr_size = new_arr_index;
    removed_dup_arr = (int *)realloc(removed_dup_arr, (*new_arr_size)*sizeof(int));
    check_allocation(arr);
}


void print_arr(int *arr, size_t size){
    printf("[");
    for (int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if (i < size -1) {
            printf(", ");
        }
    }
    printf("]\n");
}
