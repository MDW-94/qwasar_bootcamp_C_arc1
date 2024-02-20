#include <stdio.h>

// Create a function that tells us if an array is sorted or not - What is 'sorted'?

// Function takes an integer array as a parameter(input) and returns a boolean(true/false)

// Function should return true if the integer array is sorted in either ASC(ascending) or description(descending) order

// Function should return false if the integer array is not sorted

// Numbers will be from -2_000_000 to 2_000_000 && the array might have duplicates

#include <stdbool.h> // includes the bool library
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array{
    int size;
    int* array;
} integer_array;
#endif

bool my_is_sort(integer_array* param_1){

    // if(all array[i]s are > eachother by 1 || < eachother by 1) return 1 else return 0

    return 0;
}

int test(){

    int array_1[] = {1, 3, 4, 5, 6};
    int array_2[] = {60, 50, 40, 30, 20};
    int array_3[] = {1, 5, 3, 9, 2, 1, 4, 8};
    int array_4[] = {2, 1, -1};

    integer_array test_1; // true
    integer_array* ptr_test_1 = &test_1;
    ptr_test_1->size = 5;
    ptr_test_1->array = array_1;

    integer_array test_2; // true
    integer_array* ptr_test_2 = &test_2;
    ptr_test_2->size = 5;
    ptr_test_2->array = array_2;

    integer_array test_3; // false
    integer_array* ptr_test_3 = &test_3;
    ptr_test_3->size = 8;
    ptr_test_3->array = array_3;

    integer_array test_4; // true
    integer_array* ptr_test_4 = &test_4;
    ptr_test_4->size = 8;
    ptr_test_4->array = array_4;

    return 0;
}

int main(){
    test();
    return 0;
}