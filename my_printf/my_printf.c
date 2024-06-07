#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_strlen(char* str){
    int i = 0;char* temp_ptr = str;while(*temp_ptr++ != '\0'){i++;}return i;
}

char* my_strcpy(char* param_1, char* param_2){

    // for(int i = 0; i < param_3; i++) {
    //     param_1[i] = param_2[i];
    // };

    while((*param_1++ = *param_2++));

    return param_1;
}

int my_printf(char* restrict input_str, ...){
    // Needs to be initialized to no. of chars in char array - my_strlen?
    va_list args;
    va_start(args, input_str);
    // last named parameter is input_str before ellipsis

    //  create a copy of the original string?


    // enough space for end terminator:
    int count;
    if((count = my_strlen(input_str)) > 0){ //if there are any characters in the string
        // we now have a number for chars without special characters - we need to know
        // memory required for special characters:
        char temp_str[count];
        my_strcpy(temp_str, input_str);
        char* scan_ptr = temp_str;

        while(*scan_ptr != '\0'){
            // "hello, %-" -stop here and:
            if(*scan_ptr == '%'){
                *scan_ptr = '@'; 
                // remove the special char - can only be done on a copied string!
                // ISSUE - THIS WILL PREVENT THE STR FROM EBING COMPLETED LATER


                char* look_ptr = scan_ptr++;
                //look at the next character along

                // the % character is followed by zero or more of the following flags:
                // - actions taken for different special chars:

                if(*look_ptr == '%'){
                    count += 1; // make space for the counter
                }

                if(*look_ptr == 'i'){
                    // take the integer given and convert to character?                   
                    char ch = va_arg(args, int);
                    count += sizeof(ch);
                    *scan_ptr = ch; // can you change the original str??
                }


            }
            scan_ptr++;
        }

        // After handling the special chars
        char* output_str = malloc((count + 1)*sizeof(char));
        if(output_str == NULL){return 0;};

        for(int i = 0;i<count;i++){
            if(temp_str[i]){ //if there is a value at temp_str[i]
                output_str[i] = temp_str[i];
            }
    
        // traverse va_list, fetch ints, convert to char data types:
        // char ch = va_arg(args, int);

        // store in final output string:
        // output_str[i] = ch;
        }
        output_str[count] = '\0';
        va_end(args);


        // Pt.2 Output the contents of the output str to the stdout:
        if(my_strlen(output_str) > 0){
            while(*output_str != '\0'){
            write(1, output_str, 1);
            output_str++; 
            // has to be here as nested incrementation increments first, then runs code block
            //write(1, output_str, my_strlen(output_str)); THIS WAY MIGHT NOT WORK DUE TO NOT CONSIDERING SPECIAL CHARACTERS?
            }
        } else {
            printf("\n my_printf -> output_str empty\n");
        }

    } else {
        printf("\n malloc failed");
        return 0;
        // if(output_str == NULL){return 0;};
    } 


    // return output_str? Printf just outputs to the terminal, return is either success, failure or EOF??

    //free memory after completion
    // free(output_str);
    return 0;

}

int main(){
    my_printf("Hello, %% World!\n");
    return 0;
}

// ---------

// malloc perservering after va_ends:
// the memory allocated using malloc will persist past the va_end call. The va_end macro is used to clean up the memory used by the va_list macros, but it does not affect any memory allocated with malloc


// The last name parameter: va_start:
// The named parameter in va_start is simply the last parameter before the ellipsis (...)

