#include <stdio.h>
#include <stdlib.h>

// Create a function my_count_on_it that recievs a string array as a parameter and returns an array with the length of each string

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array {
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1){
    // you have to use malloc to create the allocated space in the memory in order to assign the arrays

    integer_array* result; //allocate memory for integer struct
    result->size = param_1->size;

    for(int i = 0; i < param_1->size;i++){
        char *str = param_1->array[i]; //allocate memory for the array in string array
        int j = 0;
        while(*str != 00){
            // iterates through each character in the string at index i
            j++;
        }
        result->array[i] = j;
    }
    return result;
}

int main() {
    string_array *input_1;
    input_1->size = 4;
    input_1->array = (char**)malloc(input_1->size * sizeof(char*));
    input_1-> array[0] = "This";
    input_1-> array[1] = "is";
    input_1-> array[2] = "the";
    input_1-> array[3] = "way";

    my_count_on_it(input_1);
    free(input_1->array); // malloc and free require <stdblib.h>

    return 0;
}

// Note: you have to allocate for the struct AND then allocate for the array inside

// Input: ["This", "is", "the", "way"]
// Output: [4, 2, 3, 3]

// Input: ["aBc", "AbcE Fgeg1"]
// Output: [3, 10]

// Input: ["aBc"]
// Output: [3]

//  Find a way of debugging this program gdb might be the best option 