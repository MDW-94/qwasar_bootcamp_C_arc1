#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a function that combines an array of strings from separator characters

// Eg. ["Hello", "World", "!"] && ' ' => "Hello World !"

// You will recieve two parameters, an array of strings and a separator character
// The function should return a string where all the strings from the array are joined with the separator

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_ATRING_ARRAY
typedef struct s_string_Array {
    int size;
    char** array;
} string_array;
#endif

// Do I need to allocate memory for this?

char* my_join(string_array* array, char* sep_char){

}

int main(){

    string_array* test_1 = (string_array*)malloc(sizeof(string_array));
    test_1->size = 4;
    test_1->array = (char**)malloc(test_1->size*sizeof(char*));

    test_1->array[0] = strdup("Hello");
    test_1->array[1] = strdup("World");
    test_1->array[2] = strdup("!");

    char* result = my_join(test_1, ' ');

    printf("Result for Test 1 -> %d\n", result);

    free(test_1);
    free(result);
    

    return 0;
}