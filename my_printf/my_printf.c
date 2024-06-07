#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_strlen(char* str){
    int i = 0;  while(*str++ != '\0'){i++;} return i;
}

int my_printf(const char* restrict format, ...){
    int count = 0; // Needs to be initialized to no. of chars in char array - my_strlen?
    va_list args;
    va_start(args, count);

    // enough space for end terminator:
    char* output_str = malloc((count + 1)*sizeof(char)); 
    if(output_str == NULL){return NULL;};

    for(int i = 0;i<count;i++){
        // traverse va_list, fetch ints, convert to char data types:
        char ch = va_arg(args, int);
        // store in final output string:
        output_str[i] = ch;
    }
    output_str[count] = '\0';
    va_end(args);

    while(*output_str++ != '\0'){
        write(1, output_str, 1);
        //write(1, output_str, my_strlen(output_str)); THIS WAY MIGHT NOT WORK DUE TO NOT CONSIDERING SPECIAL CHARACTERS?
    }



    // return output_str? Printf just outputs to the terminal, return is either success, failure or EOF??

    return 0;

}

int main(){
    my_printf("Hello World!\n");
    return 0;
}