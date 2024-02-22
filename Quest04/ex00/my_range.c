#include <stdio.h>

// create a function my_range, returns a malloc'd array ofi ntegerrs

//  This integer array should contain values between min and max

// Min included - max excluded

//  eg: In: 1 && 4, Out: [1, 2, 3]

int* my_range(int input_a, int input_b){
    int r_array_size = input_b - input_a;

    // ptr = (int*) malloc(n * sizeOf(int));


    // return (int*) malloc'd array
}

int test() {

    int input_1a = 1;
    int input_1b = 4;

    int input_2a = 7;
    int input_2b = 10;

    int input_3a = 10;
    int input_3b = 11;

    printf("Test 1: input_1a && input_1b -> %d", my_range(input_1a, input_1b));

    printf("Test 2: input_2a && input_2b -> %d", my_range(input_2a, input_2b));


    printf("Test 3: input_3a && input_3b -> %d", my_range(input_3a, input_3b));

    return 0;
}

int main(){
    test();
    return 0;
}