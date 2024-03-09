#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* my_strdup(char* param_1){
    int i, counter = 0;

    for(i = 0; param_1[i] != '\0'; i++){
        counter++;
    }

    char *arr;

    arr = (char*)malloc((counter+1)*sizeof(char));

    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for(int j = 0; j < counter;j++){
        arr[j] = param_1[j];
    }

    arr[counter] = '\0';

    return arr;
}

integer_array* my_count_on_it(string_array* param_1){
    // you have to use malloc to create the allocated space in the memory in order to assign the arrays

    integer_array* result = (integer_array*)malloc(sizeof(integer_array)); //allocate memory for integer struct
    result->size = param_1->size;
    result->array = (int*)malloc(result->size*sizeof(int));

    for(int i = 0; i < param_1->size;i++){
        char* str = my_strdup(param_1->array[i]); //allocate memory for the array in string array


        int j = 0;
        while(*str != '\0'){
            // iterates through each character in the string at index i
            j++;
            str++;
        }
        result->array[i] = j;
    }
    return result;
}

int main() {
    string_array* input_1 = (string_array*)malloc(sizeof(string_array));
    input_1->size = 4;
    input_1->array = (char**)malloc(input_1->size * sizeof(char*));

    // You cannot use string literals here, you must use strdup
    input_1->array[0] = strdup("This");
    input_1->array[1] = strdup("is");
    input_1->array[2] = strdup("the");
    input_1->array[3] = strdup("way");

    integer_array* result = my_count_on_it(input_1);

    printf("Original strings:\n");
    for(int i = 0; i < input_1->size;i++){
        printf("%s\n", input_1->array[i]);
    }

    printf("\nLength of the strings:\n");
    for(int i = 0; i < result->size;i++){
        printf("%d\n", result->array[i]);
    }

    // free the memory allocated for the string array and the string_array struct
    for (int i = 0; i < input_1->size; i++) {
        free(input_1->array[i]);
    }
    free(input_1->array);
    free(input_1);

    // free the allocated memory for the integer array and the integer_array struct
    free(result->array);
    free(result);

    return 0;
}

// int main() {
//     string_array *input_1;
//     input_1->size = 4;
//     input_1->array = (char**)malloc(input_1->size * sizeof(char*));

//     // You cannot use string literals here, you must use strdup
//     input_1-> array[0] = strdup("This");
//     input_1-> array[1] = strdup("is");
//     input_1-> array[2] = strdup("the");
//     input_1-> array[3] = strdup("way");

//     integer_array* result = my_count_on_it(input_1);

//     // free the memory allocated for the string array and the string_array struct
//     for(int i = 0; i < input_1->size;i++){
//         free(input_1->array[i]);
//     }
//     free(input_1->array); // malloc and free require <stdblib.h>
//     free(input_1);

//     // free the allocated memory for the integer array and the integer_array struct
//     free(result->array);
//     free(result);

//     return 0;
// }

// Note: you have to allocate for the struct AND then allocate for the array inside

// Input: ["This", "is", "the", "way"]
// Output: [4, 2, 3, 3]

// Input: ["aBc", "AbcE Fgeg1"]
// Output: [3, 10]

// Input: ["aBc"]
// Output: [3]

//  Find a way of debugging this program gdb might be the best option 