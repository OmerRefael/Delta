/*------------------------------------------------------
* Filename: array_sort.c
* Description: The program gets array of 15 numbers from the user and then determines with the types of the array
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4 /*the size of the array*/

#define FAILURE_STATUS 1
#define check_allocation(ptr) if (!ptr) exit(FAILURE_STATUS);


/*------- function declaration-------*/
void initalize_arrays(int *integers_arr, int *pointers_arr[]);
void print_arrays_details(int *integers_arr, int *pointers_arr[]);
void sort_pointers_arrays(int *integers_arr, int *pointers_arr[]);
int comp(const void *a, const void *b);
int get_index_of_ptr_by_value_he_points(int *pointers_arr[], int value);
void swap(int *pointers_arr[], int first_index, int second_index);


/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - gets array of 15 numbers from the user and then determines with the types of the array
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int integers_arr[SIZE];
    int* pointers_arr[SIZE];

    initalize_arrays(integers_arr, pointers_arr);
    print_arrays_details(integers_arr, pointers_arr);
    
    sort_pointers_arrays(integers_arr, pointers_arr);

    printf("\n\nAfter sorting:");
    print_arrays_details(integers_arr, pointers_arr);

    return 0;
}

void initalize_arrays(int *integers_arr, int *pointers_arr[]){
    int number;

    printf("please enter 10 integers\n");
    
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &number);
        integers_arr[i] = number;
        pointers_arr[i] = &integers_arr[i];

    }
}

void print_arrays_details(int *integers_arr, int *pointers_arr[]){
    for (int i = 0; i < SIZE; i++){
        printf("In 0x%p the value is: %d\n",pointers_arr[i], integers_arr[i]);
    }
}

void sort_pointers_arrays(int *integers_arr, int *pointers_arr[]){
    int *sorted_integers_array;

    sorted_integers_array = (int *)calloc(SIZE, sizeof(int)); 
    check_allocation(sorted_integers_array);
    memcpy(sorted_integers_array, integers_arr, sizeof(integers_arr));
    printf("%d  ", sorted_integers_array[1]);
    qsort(sorted_integers_array, SIZE, sizeof(int), comp);

    printf("%d", sorted_integers_array[1]);

    for (int i = 0; i < SIZE; i++) {
        int current_size_value = sorted_integers_array[i];
        int current_size_ptr_index = get_index_of_ptr_by_value_he_points(pointers_arr, current_size_value);
        swap(pointers_arr, i ,current_size_ptr_index);
    } 

    printf("here");
}

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int get_index_of_ptr_by_value_he_points(int *pointers_arr[], int value){
    for(int i = 0; i < SIZE; i++){
        if (*(pointers_arr[i]) == value){
            return i;
        }
    }
}

void swap(int *pointers_arr[], int first_index, int second_index){
    int * temp;
    temp = pointers_arr[first_index];
    pointers_arr[first_index] = pointers_arr[second_index];
    pointers_arr[second_index] = temp;
}