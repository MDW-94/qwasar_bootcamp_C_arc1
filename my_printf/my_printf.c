#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_strlen(char* str){
    int i = 0;char* temp_ptr = str;while(*temp_ptr++ != '\0'){i++;}return i;
}

int my_printf(char* restrict input_str, ...){
    // Needs to be initialized to no. of chars in char array - my_strlen?
    va_list args;
    va_start(args, input_str);

    // enough space for end terminator:
    int count = my_strlen(input_str); 
    char* output_str = malloc((count + 1)*sizeof(char)); 
    if(output_str == NULL){return 0;};

    for(int i = 0;i<count;i++){
        // traverse va_list, fetch ints, convert to char data types:
        char ch = va_arg(args, int);
        // store in final output string:
        output_str[i] = ch;
    }
    output_str[count] = '\0';
    va_end(args);

    if(my_strlen(output_str) != 0){
         while(*output_str++ != '\0'){
        write(1, output_str, 1);
        //write(1, output_str, my_strlen(output_str)); THIS WAY MIGHT NOT WORK DUE TO NOT CONSIDERING SPECIAL CHARACTERS?
        }
    } else {
        printf("\n my_printf -> output_str empty");
    }


    // return output_str? Printf just outputs to the terminal, return is either success, failure or EOF??

    //free memory after completion
    free(output_str);
    return 0;

}

int main(){
    my_printf("Hello World!\n");
    return 0;
}