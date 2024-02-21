#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
//Make code to generate random password with a specific amount of characters that the user has to input
//extra: learn how to create and save files to automatically save password as txt file in the OS
//Things to think: Thing about an algorithm that takes random chars and ints to create a password with these together
//5 random numbers: 
// (password is going to be 10 characters long)
// 1st decides if uses int or char or special char (this random number is going to be either 0, 1 or 2) 
// 2nd decides the char that is going to used from the array //char
// 3rd decides if either this char is going to be lower or uppercase //char
// 4th decides what int is going to be used from the int array //int
// 5th decides what special char is going to be used from special char array //schar
//after creating password print it and save it in a file
int main(){ 
    int i, n;
    char *ptr = password_generate();

    n = strlen(ptr);

    printf("Password is: ");
    for(i = 0; i < n; i++){
        printf("%c", *(ptr + i));
    }

    //now code to save this password in a file. (everytime a new password is created is going to be appened to this file)
    password_file(ptr);
    printf("\nPassword saved successfully in password.txt!");


    free(ptr);
    ptr = NULL; //no more dangling pointers :D
    return 0;
}