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


    // Pt. 2 - Create the Arrays
    // for loop bound to x axis for child array length - populate arrays w correct cahracters
    // for loop bound to y axis value for amount of child arrays to be printed on new lines - populate parent array



    // Pt.3 - Print the Arrays
    // for loop, print the sequence of these arrays from the struct - fin

}


int main(int ac, char **av){

    return 0;
}

// $>./a.out 4 4
// o---o
// |   |
// |   |
// o---o
