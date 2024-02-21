#include <stdio.h>
#include <string.h>

    //  The strstr() function locates the first occurrence of the null-terminated string needle in the
    //  null-terminated string haystack.

// RETURN VALUES
//      If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is
//      returned; otherwise a pointer to the first character of the first occurrence of needle is
//      returned.

char* my_strstr(char* param_1, char* param_2){
    int i = 0;
    
    while(param_1[i] != '\0'){
        int j = 0;
        while(param_2[j] != '\0'){
            if(param_1[i + j] != param_2[j]){
                break;
            }
            j++;
        }
        if(param_2[j] == '\0'){
            return &param_1[i];
        }
        i++;
    }
    return NULL;
}

// The reason for having two variables, i and j, is to independently track the positions in the two strings being compared. The outer loop increments i to move through the characters of the first string, and the inner loop increments j to compare characters in both strings.

int test() {

    char input_1a[] = "hello";
    char input_1b[] = "ll";
    // expected "bc"

    char input_2a[] = "aaaaa";
    char input_2b[] = "bba";
    // expected "2"

    char input_3a[] = "";
    char input_3b[] = "a";
    // expected nil(NULL)

    printf("my_strstr -> %s\n", my_strstr(input_1a, input_1b));
    printf("strstr -> %s\n", strstr(input_1a, input_1b));

    printf("my_strstr -> %s\n", my_strstr(input_2a, input_2b));
    printf("strstr -> %s\n", strstr(input_2a, input_2b));

    printf("my_strstr -> %s\n", my_strstr(input_3a, input_3b));
    printf("strstr -> %s\n", strstr(input_3a, input_3b));

    return 0;
}

int main() {
    test();
    return 0;
}