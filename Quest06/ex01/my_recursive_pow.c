#include <stdio.h>

// Recursive Programming: a function calls itself upon runtime

int my_recursive_pow(int x, int power){
    if(power == 0) return 0; else {
        power--; // counter of recursions
        int result = x*my_recursive_pow(x,power);
        if(power == 0) return x;
        printf("\n Result : %i", result);
        return result;
    }
}


int main(){
    printf("\n2^2 = %i\n", my_recursive_pow(2,2));
    printf("\n2^3 = %i\n", my_recursive_pow(2,3));
    printf("\n2^4 = %i\n", my_recursive_pow(2,4));
    printf("\n2^0 = %i\n", my_recursive_pow(2,0));
    return 0;
}

// Standard version
// int my_recursive_pow(int x, int power){
//     if(power == 0) return 1;  // Base case: x^0 = 1
//     else {
//         int result = x * my_recursive_pow(x, power - 1);  // Recursive case
//         printf("\n Result : %i", result);
//         return result;
//     }
// }