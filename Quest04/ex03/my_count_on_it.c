#include <stdio.h>

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
    integer_array *result; //allocate memory for integer struct
    result->size = param_1->size;

    for(int i = 0; i < param_1->size;i++){
        char *str = param_1->array[i]; //allocate memory for the array in string array
        while(*str != 00){
            // iterates through each character in the string at index i
        }
    }

}

int main() {
    string_array *input_1;
    input_1->size = 4;
    input_1-> array[0] = "This";
    input_1-> array[1] = "is";
    input_1-> array[2] = "the";
    input_1-> array[3] = "way";

    my_count_on_it(input_1);
    return 0;
}

// Note: you have to allocate for the struct AND then allocate for the array inside

// Input: ["This", "is", "the", "way"]
// Output: [4, 2, 3, 3]

// Input: ["aBc", "AbcE Fgeg1"]
// Output: [3, 10]

// Input: ["aBc"]
// Output: [3]