/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: The program create struct of time, and calculate the result of summing two difrrent times
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH_OF_NUMBER 4 /*the highest number that can be is 59 which just 2 digits +1 for the new line and +1 for null terminator */
#define FAILURE_STATUS 1
#define MAX_HOUR 23
#define MAX_MIN 59
#define MAX_SEC 59
#define MIN_VALUE 0 /*the most min value for second minute and hour (which means the hour - 12am)*/

#define invalid_input() {printf("invalid input!"); exit(EXIT_FAILURE);}

typedef struct{
    int hour;
    int minute;
    int second;
}Time ;


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
* Function Name - get_time_from_user 
*
* Function Purpose - gets the time from the user
*
* Parameters –  no parameters
*
* Return numbers - Time*: the time ptr instance that was created
*
* Author - Omer Refael
-------------------------------------------------------*/
Time* get_time_from_user();

/*------------------------------------------------------
* Function Name - get_summed_times 
*
* Function Purpose - gets the 2 times from the user, and summing them
*
* Parameters –  Time*: time1 - the first time we want to sum
*               Time*: time2 - the second time we want to sum
*
* Return numbers - Time*: the time ptr result instance that was created
*
* Author - Omer Refael
-------------------------------------------------------*/
Time* get_summed_times(Time* time1, Time* time2);


/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - createds 2 times by user, and summing them
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    Time *first_time, *second_time;
    Time* summed_time;

    first_time = get_time_from_user();
    second_time = get_time_from_user();;

    summed_time = get_summed_times(first_time, second_time);

    /*print for debuggin*/
    printf("%02d:%02d:%02d", summed_time->hour, summed_time->minute, summed_time->second);

    free(first_time);
    free(second_time);
    free(summed_time);

    return 0;
}

void check_allocation(void *ptr){
    if (ptr == NULL) exit(EXIT_FAILURE);
}

Time* get_time_from_user(){
    char string_number[MAX_LENGTH_OF_NUMBER];
    int hour, min, sec;

    printf("enter the hour:");
    if (scanf("%d", &hour) != 1 || hour < MIN_VALUE || hour > MAX_HOUR) invalid_input()

    printf("enter the minute:");
    if (scanf("%d", &min) != 1 || min < MIN_VALUE || min > MAX_MIN) invalid_input()

    printf("enter the second:");
    if (scanf("%d", &sec) != 1 || sec < MIN_VALUE || sec > MAX_SEC) invalid_input();

    Time* time  = malloc(sizeof(Time));
    check_allocation(time);

    time->hour = hour;
    time->minute = min;
    time->second = sec;

    return time;
}

Time* get_summed_times(Time* time1, Time* time2){
    Time* res_time = malloc(sizeof(Time));
    check_allocation(res_time);

    res_time->hour = (time1->hour + time2->hour) % MAX_HOUR;
    res_time->minute = (time1->minute + time2->minute) % MAX_MIN;
    res_time->second = (time1->second + time2->second) % MAX_SEC;

    return res_time;
}
