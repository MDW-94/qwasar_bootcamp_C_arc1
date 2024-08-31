#include <stdio.h>

// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

// int fib(int n){
//     int a = 0, b = 1, c, i;
//     if(n == 0) return a;
//     for(i = 2; i <= n;i++){
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return b;
// }

int my_fibonacci(int n){
    if(n <= 1) return n;
    return my_fibonacci(n - 1) + my_fibonacci(n - 2);
}

int main(){
    printf("\n\nTest 1 -> %i\n", my_fibonacci(1));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(2));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(3));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(4));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(5));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(6));
    printf("\n\nTest 1 -> %i\n", my_fibonacci(7));

    return 0;
}

// each number is equal to the sum of the preceding two numbers

// Example: 
//  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233