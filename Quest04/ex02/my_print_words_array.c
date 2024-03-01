#include <stdio.h>
#include <stdlib.h>

// Without using printf, create a function that displays the content of an array of strings - each word will be followed by a newline, including the last one

// Hint: re-use my_putstr function

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_Array {
    int size; // member (int variable)
    char** array; // member (char** variable)
} string_array;
#endif

// Struct definition:
// Declares a 'typedef' named 'string_array'
// 'string_array' contains two parameters: an integer 'size' and a double pointer a character 'array'

void my_print_words_array(string_array* param_1){

    int i = 0, j = 0;
    while(i != param_1->size){


        if(param_1->array[j] != 00){ //&& param_1->array[j][i] != 00 ??

            // --------------------
            if(param_1->array[j][i] == 00) {

                // ---------------
                putchar('\n');
                if(param_1->array[j + 1] != 00 && param_1->array[j + 1][0] != '\0'){
                    putchar(param_1->array[j + 1][0]); // fetch first char of next array && seg fault needs to stop at the end
                }
                // ---------------


                i = 0;
                j++;
            } else {
                putchar(param_1->array[j][i]);
            }
            // ------------------

        }

        // ----------------------
        i++;
    }
}

int test(){
    string_array input_1a;
    input_1a.size = 8;
    input_1a.array = (char**)malloc(input_1a.size * sizeof(char*));
    input_1a.array[0] = "abc";
    input_1a.array[1] = "def";
    input_1a.array[2] = "gh";

   my_print_words_array(&input_1a);
   free(input_1a.array);

       string_array input_2a;
    input_2a.size = 3;
    input_2a.array = (char**)malloc(input_2a.size * sizeof(char*));
    input_2a.array[0] = "123";

   my_print_words_array(&input_2a);
   free(input_2a.array);

     string_array input_3a;
    input_3a.size = 7;
    input_3a.array = (char**)malloc(input_3a.size * sizeof(char*));
    input_3a.array[0] = "";
    input_3a.array[1] = "";
    input_3a.array[2] = "hello";

   my_print_words_array(&input_3a);
   free(input_3a.array);


    return 0;
}

int main(){
    test();
    return 0;
}

// Test Function ('test'):
// Declares a variable 'input_1b' of type 'string_Array' - creates a 'structure vairable'
// Initializes the 'size' parameter of 'input_1b' to 8
// Dynamically allocates memory for the 'array' parameter using 'malloc', with size based on the value of 'input_1b.size'
// Assigns string literals to the elements of the synamically allocated array for testing purposes

// Memory Management:
// test() calls 'free' to release the dynamically allocated memory after its use

// Note: The double pointer ('char**') is used for the 'arra'y parameter because it represents an array of strings. Each element of the array ('char*') is a pointer to a character string 


// Qs:
// What exactly is 'putchar' doing?
// 'putchar' is used to write a character of unsigned char type to stdout. This method accepts a mandatory method of which is the character to be written to stdout
// This functino returns the character written on the stdout as an unsigned char

// How do we iterate through a struct if it is an array of arrays?

// https://cplusplus.com/doc/tutorial/pointers/

// https://stackoverflow.com/questions/606879/how-do-i-access-an-individual-character-from-an-array-of-strings-in-c



        // int x;
        // x = &param_1->array[i];

        // char x = *param_1->array[i]; doesn't appear to work
        
        // if(param_1->array[j] != NULL){ // if there is a string at this index position
            // int ptr_array = *param_1->array[j];

        //     putchar(param_1->array[j][i]);
        // } else {
        //     putchar('\n');
        //     putchar(122);
        //     j = 0;
        // }

        // if(param_1->array[j][i] != NULL){

        // }
        // j++;
        // i++;
        // if(i == param_1->size){
        //     putchar('\n');
        // }