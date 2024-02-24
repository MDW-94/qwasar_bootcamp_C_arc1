#include <stdio.h>
#include <stdlib.h>

// allocste a string/array of characters

char* my_strdup(char* param_1){
    int i, counter = 0;

    for(i = 0; param_1[i] != '\0'; i++){
        counter++;
    }

    char *arr;

    arr = (char*)malloc(counter*sizeof(char));

    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for(int j = 0; j < counter;j++){
        arr[j] = param_1[j];
    }

    return param_1;
}

int test(){

    char input_1[] = "abc";
    char input_2[] = "RaInB0";
    char input_3[] = "";

    printf("Test 1 -> %s\n", input_1);
    printf("Test 2 -> %s\n", input_2);
    printf("Test 3 -> %s\n", input_3);

    return 0;
}

int main(){
    test();
    return 0;
}