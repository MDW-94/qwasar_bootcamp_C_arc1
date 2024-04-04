#include <stdio.h>
#include <stdlib.h>

#ifndef CHAR_SQUARE_ARRAY
#define CHAR_SQUARE_ARRAY
typedef struct char_square_array {
    int size;
    char** array_strings;
} square_array;
#endif


char** my_square(int ac, char**av){
    // INPUT: int x axis, char** y axis || an integer + a pointer to a pointer
    // - ?? how many array are printed on a newline? 
    // - array size is determined by the x axis integer
    // - first and last array in the parent array will be identical
    // - arrays in between first and last will be identical
    // OUTPUT: a printed colelctino of arrays, their size defined by the x parameter

    // Pt.1 - declare correct space for the arrays
    // - malloc for the structure, including its size - dependent on the two arguments
    // - malloc for each child array, dependent on the x axis argument
    // - malloc for the parent array - dependent on the y axis argument

    square_array* final_str = (square_array*)malloc(sizeof(square_array));
    final_str->size = **av; // size defining no. strings within struct

    final_str->array_strings = (char**)malloc(final_str->size*sizeof(char*));

    for(int i = 0; i < final_str->size;i++){
        for(int j = 0; j < ac; j++){
            final_str->array_strings[i] = (char*)malloc(ac + 1*sizeof(char));
            // Populate the arrays with the values here?

            if(i == 0 || i == final_str->size){ // handle first and last array of struct
                if(j == 0 || j == ac){
                    final_str->array_strings[i][j] = 'o';
                    if(j == ac){
                          final_str->array_strings[i][j] = '\n';
                    }
                } else {
                    final_str->array_strings[i][j] = '-';
                }
            } else { // handle the middle arrays
                if(j == 0 || j == ac){
                    final_str->array_strings[i][j] = '|';
                    if(j == ac){
                          final_str->array_strings[i][j] = '\n';
                    }
                } else {
                    final_str->array_strings[i][j] = ' ';
                }
            }
        }
        printf("%s", final_str->array_strings[i]);
    }


    // Pt. 2 - Create the Arrays
    // for loop bound to x axis for child array length - populate arrays w correct cahracters
    // for loop bound to y axis value for amount of child arrays to be printed on new lines - populate parent array

        //   if(i == 0 || i == final_str->size){ // handle first and last array of struct
        //         if(j == 0 || j == ac){
        //             final_str->array_strings[j] = 'o';
        //         } else {
        //             final_str->array_strings[j] = '-';
        //         }
        //     } else { // handle the middle arrays
        //         if(j == 0 || j == ac){
        //             final_str->array_strings[j] = '|';
        //         } else {
        //             final_str->array_strings[j] = ' ';
        //         }
        //     }



    // Pt.3 - Print the Arrays
    // for loop, print the sequence of these arrays from the struct - fin

    return NULL;

}


int main(int ac, char **av){ 

    printf("Program Name: %s\n", av[0]);

    int x, y;

    if(ac < 3){
        // x = 1;
        // y = atoi(av[1]);
        return 00;
    } else {
        x = atoi(av[1]);
        y = atoi(av[2]);
    }

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x;j++){
            if(i == 0 || i == y - 1){
                if(j == 0 || j == x - 1){
                        printf("o");
                    } else {
                        printf("-");
                    }
            } else {
                if(j == 0 || j == x - 1){
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
     printf("\n");   
    }
    return 0;
}

// The C library function int atoi(const char *str) converts the string argument str to an integer (type int).

// why is input a pointer to a pointer??
    // my_square(4, 4);

    // ac = no. args + name
    // av = array of arrays + name of program

    // Argument Input: 4, 4
    // Result: 4 by 4 square

    // 4 arrays at a length of 4 

    // If 4, 1
    // four arrays at a length of 1

// $>./a.out 4 4
// o---o
// |   |
// |   |
// o---o

// https://en.cppreference.com/w/c/language/main_function#:~:text=The%20names%20argc%20and%20argv,**%20av)%20is%20equally%20valid.

// https://learn.microsoft.com/en-us/cpp/cpp/main-function-command-line-args?view=msvc-170


// https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm