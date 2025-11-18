#ifndef DECRYPTION_PROCESS_H
#define DECRYPTION_PROCESS_H

#include <stdio.h>

#define FAILURE_STATUS 1
#define check_allocation(ptr) if (!ptr) exit(FAILURE_STATUS);

/*------------------------------------------------------
* Function Name - decrypt_arr 
*
* Function Purpose -  gets encrypted array, and decrypt the array (to the ascii code of the letters in the decryptes message)
*
* Parameters –  arr: int * - the encrypted array
*               size: size_t: the size of the array
*
* Return numbers - void
*
* Author - Omer Refael
-------------------------------------------------------*/
void decrypt_arr(int *arr, size_t size);

#endif
