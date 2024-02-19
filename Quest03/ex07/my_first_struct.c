#include <stdio.h>

//  in this exercise you will recieve a struct integer_array - you have to print its size and its content following this format: size\narray[0]\narray[1]...

// iterate through the variable size to iterate through the struct

// if the size is 0, just print 0\n - you can use printf to print

typedef struct s_integer_array{
    int size;
    int* array;
} integer_array; // integer_array is a shorthand for struct s_integer_array

void my_first_struct(integer_array* param_1){ //defining that we want an argument by the type of 'integer_array' the shorthand for struct s_integer_array

    // must printf size\n and content[n]\n
    printf("%i\n", param_1->size); // has to use '->' to access property

    for(int i = 0; i < param_1->size;i++){
        printf("%i\n", param_1->array[i]);
    }

}

int test(){

    int array_1[] = {0, 1, 2, 3};
    int array_2[] = {10, 20, 30, 40};
    int array_3[] = {0};

    integer_array test_1;
    integer_array* ptr_test_1 = &test_1;
    ptr_test_1->size = 4;
    ptr_test_1->array = array_1;

    integer_array test_2;
    integer_array* ptr_test_2 = &test_2;
    ptr_test_2->size = 4;
    ptr_test_2->array = array_2;

    integer_array test_3;
    integer_array* ptr_test_3 = &test_3;
    ptr_test_3->size = 1;
    ptr_test_3->array = array_3;



    my_first_struct(ptr_test_1);
    my_first_struct(ptr_test_2);
    my_first_struct(ptr_test_3);

    return 0;
}

int main() {
    test();

    return 0;
}



// This code is defining a structure named 's_integer_array' using the 'typedef' keyword - the structure has two members:

// 'size': an integer variable representing the size or length of the integer array

// 'array': a pointer to an integer, which will be used to point to the dynamically allocated integer array

// After defining the structure, the code creates a new type alias 'integer_array' using 'typedef' - this alias allows you to use 'integer_array' as a shorthand for 'struct s_integer_array' -it makes the code more readable and convenvient

// you can create instances of this structure using 'integer_array', like this

//  integer_array myArray;

// you can access members of this structure by using the dot operator

// myArray.size = 10;





// struct s_coordinate {
//     int x;
//     int y;
// };

// int main(){
//     struct s_coordinate coord;
    
//     coord.x = 0;
//     coord.y = 0;
    
//     // test();
//     return 0;
// }

// --------------------------------

// structs have special behaviour as to whether the variable you're referencing is a pointer or not

// If it's a pointer on a struct, in order to reach the variable you will use ->

// example:

// struct s_coordinate{
//     int x;
//     int y;
// };

// int main(){
//     struct s_coordinate coord;
//     struct s_coordinate* ptr_on_coord = &coord;

//     ptr_on_coord->x = 0;
//     ptr_on_coord->y = 0;
//     return 0;
// }