/*------------------------------------------------------
* Filename: calc_age.c
* Description: gets from the user the current data,its birthay and calculate the difrrence
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>

#define DAYS_IN_YEAR 365
#define DAYS_IN_MONTH 30
#define MONTHS_IN_YEAR 12

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - gets from the user the current data,its birthay and calculate the difrrence
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning (indicate success or fail of the program)
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    int curr_year, birth_year;
    int curr_month, birth_month;
    int curr_day, birth_day;

    int diff_by_day;
    float diff_by_month;
    float diff_by_year;

    printf("Enter current date: \n");
    scanf("%d/%d/%d", &curr_day, &curr_month, &curr_year);

    printf("Enter Gary's birthday: \n");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);

    diff_by_day = (curr_day + curr_month*DAYS_IN_MONTH + curr_year*DAYS_IN_YEAR) - (birth_day + birth_month*DAYS_IN_MONTH + birth_year*DAYS_IN_YEAR);
    diff_by_month = ((float)curr_day/DAYS_IN_MONTH + curr_month + curr_year*MONTHS_IN_YEAR) - ((float)birth_day/DAYS_IN_MONTH + birth_month + birth_year*MONTHS_IN_YEAR);
    diff_by_year = ((float)curr_day/DAYS_IN_YEAR + (float)curr_month/MONTHS_IN_YEAR + curr_year) - ((float)birth_day/DAYS_IN_YEAR + (float)birth_month/MONTHS_IN_YEAR + birth_year);

    printf("Gary's age in dayes: %d\n", diff_by_day);
    printf("Gary's age in months: %f\n", diff_by_month);
    printf("Gary's age in years: %f\n", diff_by_year);

    return 0;
}

 