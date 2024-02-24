#include <stdio.h>
#include <stdlib.h> // malloc belongs to this header file
// create a function my_range, returns a malloc'd array ofi ntegerrs

//  This integer array should contain values between min and max

// Min included - max excluded

//  eg: In: 1 && 4, Out: [1, 2, 3]

int* my_range(int input_a, int input_b){
    int r_array_size = input_b - input_a;

    int *arr;

    arr = (int*)malloc(r_array_size*sizeof(int));

    

    if(arr == NULL){
        fprintf( stderr, "Memory allocation failed\n");
        exit(1);
    }

    for(int i = 0; i < r_array_size;i++){
        arr[i] = input_a + i;
    }

    return arr;
}

int test() {

    int input_1a = 1;
    int input_1b = 4;

    int input_2a = 7;
    int input_2b = 10;

    int input_3a = 10;
    int input_3b = 11;

    int* result_1 = my_range(input_1a, input_1b);
    int* result_2 = my_range(input_2a, input_2b);
    int* result_3 = my_range(input_3a, input_3b);

    printf("Test 1: input_1a && input_1b ->");
    for(int i = 0; i < input_1b - input_1a;i++){
        printf(" %d", result_1[i]);
    }
    printf("\n");

        printf("Test 2: input_2a && input_2b ->");
    for(int i = 0; i < input_2b - input_2a;i++){
        printf(" %d", result_2[i]);
    }
    printf("\n");

        printf("Test 3: input_3a && input_3b ->");
    for(int i = 0; i < input_3b - input_3a;i++){
        printf(" %d", result_3[i]);
    }
    printf("\n");

    return 0;
}

int main(){
    test();
    return 0;
}

// Dynamic Memory Allocation: The mechanism by which storage/memory/cells can be allocated to variables during the run time is called Dynamic Memory Allocation (not to be confused with DMA).