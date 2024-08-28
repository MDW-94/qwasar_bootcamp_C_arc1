#include <stdio.h>

int my_fibonacci(int nth_element){
    if(nth_element < 0) return -1;
    int x;
    if(nth_element != 0){
        printf("\n Iteration: %i", nth_element);
        printf("\n X Value: %i", x);
        return x + my_fibonacci(nth_element - 1);
    } else {
        return x;
    }
}

int main(){
    printf("\n\nTest 1 -> %i\n", my_fibonacci(3));
    return 0;
}

// each number is equal to the sum of the preceding two numbers

// Example: 
//  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233