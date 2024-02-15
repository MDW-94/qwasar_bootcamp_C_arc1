#include <stdio.h>
#include <string.h>

// Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. The terminating null character is considered to be part of the string. Returns a pointer pointing to the last matching character, or null if no match was found.

char* my_Strrchr(char* param_1, char param_2){
    
}

int test(){

    char input_1a[] = 'abcabc';
    char input_1b = 'b';
    // expected "bc"

    char input_2a[] = '121212';
    char input_2b = '2';
    // expected "2"

    char input_3a[] = 'abc';
    char input_3b = 'd';
    // expected nil(NULL)

    print("my_Strrchr -> %s\n", my_Strrchr(input_1a, input_1b));
    print("strrchr -> %s\n", strrchr(input_1a, input_1b));

    print("my_Strrchr -> %s\n", my_Strrchr(input_2a, input_2b));
    print("strrchr -> %s\n", strrchr(input_2a, input_2b));

    print("my_Strrchr -> %s\n", my_Strrchr(input_3a, input_3b));
    print("strrchr -> %s\n", strrchr(input_3a, input_3b));

    return 0;
}

int main(){
    test();
    return 0;
}