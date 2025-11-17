/*------------------------------------------------------
* Filename: calc_price.c
* Description: gets infomation about the package from the user, and prints its stats  (like size, weight and price)
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>

#define FROM_MM_TO_CM 0.1 /*the value we need to mult by for covert value in mm to cm*/
#define FROM_GRAM_TO_KG 0.001 /*the value we need to mult by for covert value in gram to kilogram*/
#define PRICE_PER_KG 11
#define PRICE_PRR_SQUARED_CM 0.03
#define FACTOR_OF_SIZE_DIVIDED_BY_WEIGHT 0.01 /*the factor we need to add to price by mult by the size devided by the weight*/
#define POSTAGE 5.5

/*functions declaration*/
void print_delivery_stats(float length,float width,float weight);
float get_price_of_package(float size, float weight);

/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - scan infomation about the package from the user, and prints its stats  (like size, weight and price)
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning (indicate success or fail of the program)
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    float length, width, weight;

    printf("Please enter the length of the package (in mm): ");
    scanf("%f", &length);

    printf("Please enter the width of the package (in mm): ");
    scanf("%f", &width);

    printf("Please enter the weight of the package (in grams): ");
    scanf("%f",&weight);

    print_delivery_stats(length, width, weight);

    return 0;
}

/*------------------------------------------------------
* Function Name - print_delivery_stats 
*
* Function Purpose - print the delivery stats of the package: size, weight and price (in the required units of measure)
*
* Parameters –  length: float - the length of the package in mm
*               width: float - the width of the package in mm
*               weight: float - the weight of the package in grams
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void print_delivery_stats(float length,float width,float weight){
    float size_in_square_cm = (length * FROM_MM_TO_CM) * (width * FROM_MM_TO_CM); 
    float weight_in_kg = weight * FROM_GRAM_TO_KG;

    printf("The size of the package (in sm) is %.2f \n", size_in_square_cm);
    printf("The weight of the package (in kg) is %.3f \n", weight_in_kg);
    printf("The price of the package is %.2f \n", get_price_of_package(size_in_square_cm, weight_in_kg));
}

/*------------------------------------------------------
* Function Name - get_price_of_package 
*
* Function Purpose - return the price of the delivery of the package
*
* Parameters –  size: float - the size of the package in squared sm
*               weight: float - the weight of the package in kg
*
* Return numbers - float: the final price
*
* Author - Omer Refael
-------------------------------------------------------*/
float get_price_of_package(float size, float weight){
    return  POSTAGE + weight*PRICE_PER_KG + size*PRICE_PRR_SQUARED_CM + FACTOR_OF_SIZE_DIVIDED_BY_WEIGHT*(size/weight);
}