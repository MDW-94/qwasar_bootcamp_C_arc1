#include <stdio.h>
#include <string.h>

// Create a function that searches for the first occurrence of the character c (an assigned char) in the string pointed to by the argument str. The terminating null character is considered to be part of the string. The function should return a pointer pointing to the last matching character, or null if no match was found.

// 

char* my_strchr(char* param_1, char param_2){

    for(int i = 0; param_1[i] != '\0'; i++){
        if(param_1[i] == param_2){
            return &param_1[i];
        }
    }

    return NULL;
}

int test(){

    char input_1a[] = "abcabc";
    char input_1b = 'b';
    // expected: "bcabc"

    char input_2a[] = "121212";
    char input_2b = '2';
    // expected: "21212"

    char input_3a[] = "abc";
    char input_3b = 'd';
    // expected = nil (NULL)

    printf("my_strchr -> %s\n", my_strchr(input_1a, input_1b));
    printf("my_strchr -> %s\n", strchr(input_1a, input_1b));

    printf("my_strchr -> %s\n", my_strchr(input_2a, input_2b));
    printf("my_strchr -> %s\n", strchr(input_2a, input_2b));

    printf("my_strchr -> %s\n", my_strchr(input_3a, input_3b));
    printf("my_strchr -> %s\n", strchr(input_3a, input_3b));

    return 0;
}


int main() {
    test();
    return 0;
}
