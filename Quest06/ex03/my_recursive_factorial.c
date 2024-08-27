#include <stdio.h>

int my_recursive_factorial(int x){
    if(x == 0) return 1;

    printf("\n  temp value = %i", x);

    if(x == 1){
        return 1;
    } else {
        return x * my_recursive_factorial(x-1);
    }
}

int main(){
    printf("\n\nTest 4! => %i\n", my_recursive_factorial(4));
    printf("\n\nTest 4! => %i\n", my_recursive_factorial(0));
    printf("\n\nTest 4! => %i\n", my_recursive_factorial(2));
    printf("\n\nTest 4! => %i\n", my_recursive_factorial(3));

    return 0;
}

//  Recursive Programming:
// Base Case
// Recursive Case
// 

// int my_recursive_factorial(int x){
//     int result = x, i = x-1;
//     i--;
//     if(i == 0){
//         return result;
//     } else {
//         result *= i;
//         my_recursive_factorial(result);
//     }
//     return result;
// }

// Only the deepest recursive call ('x = 1') returns 0 

//  However, each preceeding call ('x = 2', 'x = 3', and 'x = 4') 
// doesn't utilize the return value from their respective recursive calls
// Instead, they simply return their own current 'temp' values ('1', '2', and '3' respectively)

// As a result, when the recursive function is called it ultimately returns '3', not '0'. 
//  The '0' returned by the recursive function is effectively discarded because it's not used or propagated back up the call stack.

//  In order to fix this, you must modify the funciton to return the result of the recursive call

