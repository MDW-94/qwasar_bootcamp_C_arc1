#include <stdio.h>


int my_iterative_factorial(int x){
    int result = x, temp = 0;

    // !2 => 2*1 => 2
    // !4 => 4*3*2*1 => 24
    for(int i = x-1;i>0;i--){
        result *= i;
        // printf("\nResult: %i\n", result);
    }

    return result;
}

int main(){
    printf("Test 4! => %i\n", my_iterative_factorial(4));
    printf("Test 3! => %i\n", my_iterative_factorial(3));
    return 0;
}

