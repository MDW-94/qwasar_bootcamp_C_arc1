#include <stdio.h>

int my_iterative_pow(int x, int y){
    int result = x;
    if(y == 0) return result = 0;

    for(int i = 0;i<y - 1;i++){
        result *= x;
    }

    return result;
}

int main() {
    printf("2 * 2 = %i\n", my_iterative_pow(2,2));
    printf("2 * 3 = %i\n", my_iterative_pow(2,3));
    printf("2 * 4 = %i\n", my_iterative_pow(2,4));
    printf("4 * 4 = %i\n", my_iterative_pow(4,4));
    printf("8 * 8 = %i\n", my_iterative_pow(8,8));
    return 0;
}