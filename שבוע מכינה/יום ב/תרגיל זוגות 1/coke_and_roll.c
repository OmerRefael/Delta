/*------------------------------------------------------
* Filename: coke_and_roll.c
* Description: 
* Author: Rephael Riahi, Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define AGENT_AMOUNT_OF_TEN_CENTS 1
#define AGENT_AMOUNT_OF_TWO_SHEKELS 3
#define AGENT_AMOUNT_OF_FIVE_SHEKELS 3
#define AGENT_AMOUNT_OF_TEN_SHEKELS 7

typedef enum  {
    COLA = 'C',
    DIET_COLA = 'D',
    ORANGEADE = 'O',
    SCHWEPPES = 'S',
    GRAPE_JUICE = 'G',
    MINERAL_WATER = 'M',
    END = 'E'
}Drinks;

typedef struct 
{
    int amount_of_ten_cents;
    int amount_of_fifty_cents;
    int amount_of_one_shekel;
    int amount_of_two_shekels;
    int amount_of_five_shekels;
    int amount_of_ten_shekels;
}Payment;


int main() {
    char choice;

    do{
        Payment pay;

        show_menu();

        scanf(" %c",&choice);
        choice = toupper(choice);

        switch(choice){
            case COLA: 
                printf("The price of the drink is 5.20 NIS");
                pay = create_payment_from_user();
                
                break;
            case DIET_COLA:
                printf("The price of the drink is 7.20 NIS");
                break;
            case ORANGEADE:
                printf("The price of the drink is 3.40 NIS");
                break;
            case SCHWEPPES:
                printf("The price of the drink is 4.50 NIS");
                break;
            case GRAPE_JUICE:
                printf("The price of the drink is 3.50 NIS");
                break;
            case MINERAL_WATER:
                printf("The price of the drink is 2.50 NIS");
                break;
            case END :
                break;
            default:
                printf("No such drink, try again!");
        }

    }while(choice != 'E');

    return 0;
}


void show_menu(){
    printf("*************** Welcome to the drinks machine ***************\n\n\n");
    printf("Please select the drink you would like to order:\n");
    printf( "press 'C' for Coca-Cola\n"
            "press 'D' for Diet-Cola\n"
            "press 'O' for Orangeade\n"
            "press 'S' for Schweppes\n"
            "press 'G' for Grape juice\n"
            "press 'W' for Mineral water\n");
}

Payment create_payment_from_user(){
    Payment pay;

    int amount_of_ten_cents;
    int amount_of_fifty_cents;
    int amount_of_one_shekel;
    int amount_of_two_shekels;
    int amount_of_five_shekels;
    int amount_of_ten_shekels; 

    printf("Enter amount of 0.1 NIS: ");
    scanf("%d", &amount_of_ten_cents);

    printf("Enter amount of 0.5 NIS: ");
    scanf("%d", &amount_of_fifty_cents);

    printf("Enter amount of 1 NIS: ");
    scanf("%d", &amount_of_one_shekel);
           
    printf("Enter amount of 2 NIS: ");
    scanf("%d", &amount_of_two_shekels);

    printf("Enter amount of 5 NIS: ");
    scanf("%d", &amount_of_five_shekels);

    printf("Enter amount of 10 NIS: ");
    scanf("%d", &amount_of_ten_shekels);

    pay = (Payment){amount_of_ten_cents, amount_of_fifty_cents, amount_of_one_shekel, amount_of_two_shekels, amount_of_five_shekels, amount_of_ten_shekels};
    return pay;
}