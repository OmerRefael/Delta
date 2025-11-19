/*------------------------------------------------------
* Filename: file_operations.c
* Description: The program implements operations on files
* Author: Omer Refael
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAIN_FILE_NAME "example.txt" /*the main name of file we will use for checking the functions' logic*/
#define FAILURE_STATUS 1
#define BUFFER_SIZE 100
#define TRUE 1
#define FALSE 0
#define EQUAL 0


/*------- function declaration-------*/

/*------------------------------------------------------
* Function Name - check_opened_file 
*
* Function Purpose - check if the file opened successfully, and if not exit
*
* Parameters – ptr: void* - the file pointer
*              name: char * - the name of the file 
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
void check_opened_file(void *ptr, char *name);

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

/*Note: i didnt docemnt the functions, because each func is exatly like said in the instructions*/

void print_file(char *file_name);

void copy_file(char *src_file_name, char *dst_file_name);

void print_file_stats(char *file_name);

void delete_line(char *file_name, int line);

int get_amount_of_times_string_in_file(char *file_name, char *string);



/*------------------------------------------------------
* Function Name - main 
*
* Function Purpose - checks the funcs' logic
*
* Parameters –  no parameters
*
* Return numbers - int number with no meaning 
*
* Author - Omer Refael
-------------------------------------------------------*/
int main() {
    FILE *file;
    int amount_of_times_string_in_file = 0;

    /*-----check question 1-----*/
    print_file(MAIN_FILE_NAME);
    /*--------------------------*/

    /*-----check question 2-----*/
    copy_file(MAIN_FILE_NAME, "copy_of_example.txt");
    /*--------------------------*/

    /*-----check question 3-----*/
    print_file_stats(MAIN_FILE_NAME);
    /*--------------------------*/

    /*-----check question 4-----*/
    delete_line("copy_of_example.txt", 2);
    /*--------------------------*/

    /*-----check question 5-----*/
    amount_of_times_string_in_file = get_amount_of_times_string_in_file(MAIN_FILE_NAME, "test");
    printf("the string \"test\" was in file %s %d times", MAIN_FILE_NAME, amount_of_times_string_in_file);
    /*--------------------------*/

    return 0;
}

void check_opened_file(void *ptr, char *name){
    if (ptr == NULL) {printf("the file %s not opened succesfully", name); exit(EXIT_FAILURE);}
}

void check_allocation(void *ptr){
    if (ptr == NULL) exit(EXIT_FAILURE);
}

/*-----------question1----------*/
void print_file(char *file_name){
    char buffer[BUFFER_SIZE];
    
    FILE* file = fopen(file_name, "r");
    check_opened_file(file, file_name);

    while (fgets(buffer, BUFFER_SIZE, file)){
        printf(buffer);
    }

    printf("\n");
    fclose(file);
}
/*------------------------------*/

/*-----------question2----------*/
void copy_file(char *src_file_name, char *dst_file_name){
    char buffer[BUFFER_SIZE];
    
    FILE* src_file = fopen(src_file_name, "r");
    check_opened_file(src_file, src_file_name);

    FILE* dst_file = fopen(dst_file_name, "w");
    check_opened_file(src_file, src_file_name);


    while (fgets(buffer, BUFFER_SIZE, src_file)){
        fprintf(dst_file ,buffer);
    }

    fclose(src_file);
    fclose(dst_file);
}
/*------------------------------*/

/*-----------question3----------*/
void print_file_stats(char *file_name){
    int lines = 1, words = 0, chars = 0;
    char c;
    int flag_is_word = FALSE;
    
    FILE* file = fopen(file_name, "r");
    check_opened_file(file, file_name);

    while ((c = fgetc(file)) != EOF){
        if (isspace(c)){
            if (c == '\n') {lines++;}
            if (flag_is_word){
                words++;
                flag_is_word = FALSE;
            }
        }
        else{
            chars++;
            flag_is_word = TRUE;
        }
    }

    if (flag_is_word) words++;

    printf("amount of lines: %d, words: %d, chars: %d\n",lines, words, chars); /*amount of chars, not include white spaces*/

    fclose(file);
}
/*------------------------------*/

/*-----------question4----------*/
void delete_line(char *file_name, int line){
    char *content;
    char c;
    int current_line = 1;
    int index = 0;
    size_t allocated = BUFFER_SIZE;
    FILE *read_the_file, *write_to_file;

    read_the_file = fopen(file_name, "r");
    check_opened_file(read_the_file, file_name);

    content = calloc(BUFFER_SIZE, sizeof(char));
    check_allocation(content);

    while ((c = fgetc(read_the_file)) != EOF){
        if (current_line != line){
            *(content + index) = c;
            index++;
        }
        if (c == '\n') current_line++;

        if (index >= allocated - 10) {
            allocated += BUFFER_SIZE;
            content = realloc(content, allocated);
            check_allocation(content);
        }
    }

    content[index] = '\0'; 

    fclose(read_the_file);

    write_to_file = fopen(file_name, "w");
    check_opened_file(write_to_file, file_name);

    fprintf(write_to_file, "%s", content);

    free(content);
    fclose(write_to_file);

}
/*------------------------------*/

/*-----------question5----------*/
int get_amount_of_times_string_in_file(char *file_name, char *string){
    char buffer[BUFFER_SIZE];
    int counter = 0;
    
    FILE *file = fopen(file_name, "r");
    check_opened_file(file, file_name);

    while (fgets(buffer, BUFFER_SIZE, file)){
        char* pos = buffer;
        while ((pos = strstr(pos, string)) != NULL ){
            counter++;
            pos += strlen(string);
        }
    }

    fclose(file);

    return counter;
}
/*------------------------------*/
