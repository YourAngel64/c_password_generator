#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//generate random number between 0 and arg "limit"
int my_random(int limit){
    int n = rand() % (limit + 1);
    return n;
}

//generate password and return pointer with password
char *password_generate(){
    //arr to make password
    char numbers[] = {'1','2','3','4','5','6','7','8','9','0'};
    char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char specialc[] = {'!','@','?', '$', '#', '-', '&', '_'};

    //var with random nums:
    int option, numbers_opt, letters_opt, is_uppercase, specialc_opt;

    //normal algorithm starts
    int i, n;
    char *ptr;
    ptr = NULL;
    
    printf("Please input how long you want your password to be (recommendable is 5 at least): ");
    scanf("%d", &n);

    //password var declared after n inoput is saved
    char password[n];
    srand(time(NULL)); 
    

    for(i = 0; i < n; i++){
        option = my_random(2);

        switch(option){
            case 0:
                numbers_opt = my_random(9);
                
                password[i] = numbers[numbers_opt];

                break;

            case 1:
                is_uppercase = my_random(1);
                letters_opt = my_random(25);

                if(is_uppercase == 0){
                    password[i] = toupper(letters[letters_opt]);
                }
                else{
                    password[i] = letters[letters_opt];
                }
                break;

            case 2:
                specialc_opt = my_random(7);

                password[i] = specialc[specialc_opt];
                
                break;
        }

    }

    ptr = (char *)malloc(n*sizeof(char));

    for(i = 0; i < n; i++){
        *(ptr + i) = password[i];
    }

    return ptr;
        
}

//make file with password
void password_file(char *ptr){
    int i, n = strlen(ptr);
    FILE *fptr;

    fptr = fopen("password.txt", "a");

    for(i = 0; i < n; i++){
        fprintf(fptr, "%c", *(ptr + i));
    }
    fprintf(fptr, "\n"); //for this case using fprintf is better option
    //fprintf and fscanf write and scan (respectively) letter by letter

    fclose(fptr);
}


#endif