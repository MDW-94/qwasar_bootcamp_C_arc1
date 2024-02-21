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
    for(int i = 1; i < param_1->size - 1;i++){
        if(!(param_1->array[i] >= param_1->array[i - 1] && param_1->array[i] <= param_1->array[i + 1] 
        || 
        param_1->array[i] <= param_1->array[i - 1] && param_1->array[i] >= param_1->array[i + 1])){
            return false;
        }
    }
    return true;
}

// bool my_is_sort(integer_array* param_1) { // Longwinded way
//     if (param_1->size < 2) {
//         // An array with 0 or 1 element is always considered sorted
//         return true;
//     }

//     // Check for ascending order
//     if (param_1->array[0] <= param_1->array[1]) {
//         for (int i = 1; i < param_1->size - 1; i++) {
//             if (param_1->array[i] > param_1->array[i + 1]) {
//                 return false;
//             }
//         }
//     }
//     // Check for descending order
//     else if (param_1->array[0] >= param_1->array[1]) {
//         for (int i = 1; i < param_1->size - 1; i++) {
//             if (param_1->array[i] < param_1->array[i + 1]) {
//                 return false;
//             }
//         }
//     }
//     // Array is not in sequential order
//     else {
//         return false;
//     }

//     return true;
// }

int test(){

    int array_1[] = {1, 1, 2};
    int array_2[] = {2, 1, -1};
    int array_3[] = {4, 7, 0, 3};
    int array_4[] = {};

    integer_array test_1; // true
    integer_array* ptr_test_1 = &test_1;
    ptr_test_1->size = 3;
    ptr_test_1->array = array_1;

    integer_array test_2; // true
    integer_array* ptr_test_2 = &test_2;
    ptr_test_2->size = 3;
    ptr_test_2->array = array_2;

    integer_array test_3; // false
    integer_array* ptr_test_3 = &test_3;
    ptr_test_3->size = 4;
    ptr_test_3->array = array_3;

    integer_array test_4; // true
    integer_array* ptr_test_4 = &test_4;
    ptr_test_4->size = 0;
    ptr_test_4->array = array_4;

    if(my_is_sort(ptr_test_1)){
        printf("Array is in sequential order\n");
    } else {
        printf("Array is not in sequential order\n");
    }
    if(my_is_sort(ptr_test_2)){
        printf("Array is in sequential order\n");
    } else {
        printf("Array is not in sequential order\n");
    }
    if(my_is_sort(ptr_test_3)){
        printf("Array is in sequential order\n");
    } else {
        printf("Array is not in sequential order\n");
    }
    if(my_is_sort(ptr_test_4)){
        printf("Array is in sequential order\n");
    } else {
        printf("Array is not in sequential order\n");
    }

    return 0;
}

int main(){
    test();
    return 0;
}

// the first element (param_1->array[0]) doesn't have a previous element, and the last element (param_1->array[param_1->size - 1]) doesn't have a next element.