/*------------------------------------------------------
* Filename: array_series.c
* Description: The program gets array of 15 numbers from the user and then determines with the types of the array
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 15 /*the size of the array*/
#define FALSE 0
#define TRUE 1
#define UNDEFINED_VALUE -1


/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - get_number_from_user 
*
* Function Purpose - set parameter's value according to the user
*
* Parameters –  integer: number - the varible we want to set its value according to the user
*
* Return numbers -  void
*
* Author - Omer Refael
-------------------------------------------------------*/
void set_number_by_user(int* number);
/*------------------------------------------------------
* Function Name - set_flags 
*
* Function Purpose - sets the flags that indicate the status of the arr
*
* Parameters –  integer: prev_number - the prev number in the arr
*               integer: curr_number - the curr number in the arr
*               integer: increasing_arr_flag - the flag that indicate if the arr is increasing arr
*               integer: decreasing_arr_flag - the flag that indicate if the arr is decreasing arr
*               integer: constant_arr_flag - the flag that indicate if the arr is constant arr
*               integer: messed_up_arr_flag - the flag that indicate if the arr is messed up arr
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void set_flags(int prev_number, int curr_number, int *increasing_arr_flag, int *decreasing_arr_flag, int *constant_arr_flag, int *messed_up_arr_flag);
/*------------------------------------------------------
* Function Name - is_messed_up_arr 
*
* Function Purpose - checks if the arr is messed up
*
* Parameters –  integer: increasing_arr_flag - the flag that indicate if the arr is increasing arr
*               integer: decreasing_arr_flag - the flag that indicate if the arr is decreasing arr
*               integer: constant_arr_flag - the flag that indicate if the arr is constant arr
*
* Return numbers - integer: 1 if the arr is messed up, otherwise 0
*
* Author - Omer Refael
-------------------------------------------------------*/
int is_messed_up_arr(int increasing_arr_flag, int decreasing_arr_flag, int constant_arr_flag);
/*------------------------------------------------------
* Function Name - print_arr_status 
*
* Function Purpose - print the status of the arr
*
* Parameters –  integer: increasing_arr_flag - the flag that indicate if the arr is increasing arr
*               integer: decreasing_arr_flag - the flag that indicate if the arr is decreasing arr
*               integer: constant_arr_flag - the flag that indicate if the arr is constant arr
*               integer: messed_up_arr_flag - the flag that indicate if the arr is messed up arr
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_arr_status(int increasing_arr_flag, int decreasing_arr_flag, int constant_arr_flag, int messed_up_arr_flag);


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
    int increasing_arr_flag = FALSE, decreasing_arr_flag = FALSE, constant_arr_flag = FALSE, messed_up_arr_flag = FALSE;
    int curr_number = UNDEFINED_VALUE;
    int prev_number = UNDEFINED_VALUE;
    
    printf("please enter 15 numbers:\n");
    set_number_by_user(&curr_number);

    for(int amount_of_scanned_numbers = 1; amount_of_scanned_numbers < SIZE; amount_of_scanned_numbers++){
        prev_number = curr_number;
        set_number_by_user(&curr_number);

        set_flags(prev_number, curr_number, &increasing_arr_flag, &decreasing_arr_flag, &constant_arr_flag, &messed_up_arr_flag);
    }

    if (is_messed_up_arr(increasing_arr_flag, decreasing_arr_flag, constant_arr_flag)){
        messed_up_arr_flag = TRUE;
    }

    print_arr_status(increasing_arr_flag, decreasing_arr_flag, constant_arr_flag, messed_up_arr_flag);

    return 0;
}

void set_number_by_user(int* number){
    if (scanf("%d", number) != 1){ /*integer was not scanned*/
        printf("invalid input!");
        exit(1);
    }
}

void set_flags(int prev_number, int curr_number, int *increasing_arr_flag, int *decreasing_arr_flag, int *constant_arr_flag, int *messed_up_arr_flag){
    if (prev_number < curr_number){
        *increasing_arr_flag = TRUE;
    }
    else if (prev_number > curr_number){
        *decreasing_arr_flag = TRUE;
    }
    else{
        *constant_arr_flag = TRUE;
    }
}

int is_messed_up_arr(int increasing_arr_flag, int decreasing_arr_flag, int constant_arr_flag){
    return (increasing_arr_flag && decreasing_arr_flag) || (increasing_arr_flag && constant_arr_flag) || (decreasing_arr_flag && constant_arr_flag);
}

void print_arr_status(int increasing_arr_flag, int decreasing_arr_flag, int constant_arr_flag, int messed_up_arr_flag){
    if (messed_up_arr_flag){
        printf("The array is messed up\n");
    }
    else if (increasing_arr_flag){
        printf("The array is increasing\n");
    }
    else if (decreasing_arr_flag){
        printf("The array is decreasing\n");
    }
    else{
        printf("The array is constant\n");
    }
}
