/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: The program  scanf from the user one input line in a safe way
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20 
#define FAILURE_STATUS 1
#define MAX_SIZE_IN_ONE_LINE 2000 /*if the malicus user wants to collapse the program, we will prvent this, by define the max*/

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
* Function Name - initalize_buffer 
*
* Function Purpose - initalize buffer with null terminators
*
* Parameters – buffer: char [] - the buffer we want to intialize
*              start_index: int - the start index from where to start initalize
*              size: size_t  - the size of the buffer
*
* Return numbers - char* - the final string that the user entered
*
* Author - Omer Refael
-------------------------------------------------------*/
void initalize_buffer(char buffer[], int start_index, size_t size);

/*------------------------------------------------------
* Function Name - check_if_malicious_user 
*
* Function Purpose - check if the user is malicious
*
* Parameters – size: size_t  - the size of the buffer
*
* Return numbers - char* - the final string that the user entered
*
* Author - Omer Refael
-------------------------------------------------------*/
void check_if_malicious_user(size_t size);



void check_allocation(void *ptr){
    if (ptr == NULL) exit(EXIT_FAILURE);
}

char* dyn_scanf(){
    char buffer[BUFFER_SIZE];
    char *string;
    size_t size = 0;
    int flag_is_new_line = 0;

    initalize_buffer(buffer, 0, BUFFER_SIZE);
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        if (strcspn(buffer, "\n") < strlen(buffer)){ /*means it has the new line char*/
            flag_is_new_line = 1;
            buffer[strcspn(buffer, "\n")] = '\0'; /*remove the new line char*/
        }
        size += strlen(buffer);
        
        string = calloc(size + 1, sizeof(char)); /*+1 for the null terminator*/
        check_allocation(string);

        /*copy the new info - allways with null termintor*/
        strcpy_s(string, BUFFER_SIZE, buffer);
    }

    while (!flag_is_new_line && fgets(buffer, BUFFER_SIZE, stdin) != NULL){ /*fgets read at most n -1 chars - it always add null terminator in the end*/
        size_t prev_size = size;

        if (strcspn(buffer, "\n") < strlen(buffer)){ /*means it has the new line char*/
            initalize_buffer(buffer, strcspn(buffer, "\n"), BUFFER_SIZE); /*also remove the new line char*/
            flag_is_new_line = 1;
        }
        
        size += strlen(buffer);

        /*realloc*/
        string = (char *) realloc(string, size * sizeof(char) + 1); /* +1 for the null terminator*/
        check_allocation(string);

        /*copy the new info - allways with null termintor*/
        strcpy_s(string+prev_size, BUFFER_SIZE, buffer);

        /*intalize buffer*/
        initalize_buffer(buffer,0, BUFFER_SIZE);

        check_if_malicious_user(size);
    }
    
    return string;
}

void initalize_buffer(char buffer[], int start_index ,size_t size){
    for(int i = start_index; i < size; i++){
        buffer[i] = '\0';
    }
}


void check_if_malicious_user(size_t size){
    if (size > MAX_SIZE_IN_ONE_LINE){
        printf_s("You are malicious user (too long line)");
        exit(EXIT_FAILURE);
    }
}
