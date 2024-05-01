#include <stdio.h>
#define MAX_ARRAY_SIZE 128
void fill_array(int* array, char* str){
    int index = 0;
    printf("CURRENT STRING: %s\n", str);
    while(str[index] != '\0'){
        if(str[index] != '"'){
            array[(int)str[index]] += 1;
        }
        index += 1;
    }
}
void print_array(int* array, int size_array){
    int index = 0;
    while(index < size_array){
        if(array[index] > 0){
            printf("%c:%d\n", index, array[index]);
        }
        index += 1;
    }
}
int main(int ac, char** av){
    int index = 1;
    int array[MAX_ARRAY_SIZE] = {0};
    while(index < ac){
        fill_array(&array[0], av[index]);
        index += 1;
    }
    print_array(&array[0], MAX_ARRAY_SIZE);
    return 0;
}
// I've added a comment here through nano
