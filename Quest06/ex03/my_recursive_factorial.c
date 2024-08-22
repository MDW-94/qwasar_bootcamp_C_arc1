#include <stdio.h>

int my_recursive_factorial(int x){
    int result = x, i = x-1;
    i--;
    if(i == 0){
        return result;
    } else {
        result *= i;
        my_recursive_factorial(result);
    }
    return result;
}

int main(){
    printf("Test 4! => %i", my_recursive_factorial(4));
    return 0;
}