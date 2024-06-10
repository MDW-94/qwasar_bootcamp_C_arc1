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

//  Formatted Output Conversion
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

        //  TEMP STR MADE THAT CAN BE MODIFIED BEFORE BEING OUTPUTTED
        char temp_str[count];
        my_strcpy(temp_str, input_str);
        char* scan_ptr = temp_str;

        while(*scan_ptr != '\0'){
            // "hello, %-" -stop here and:
            if(*scan_ptr == '%'){
                // *scan_ptr = 8; // this works but removes any empty space before special char
                *scan_ptr = 26; // this works fine - usually used to mark an erronous data point
                char* look_ptr = scan_ptr += 1; // cannot be scan_ptr++ || look_ptr = scan_ptr; look_ptr++; for some reason?
                //look at the next character along

                // the % is a conversion character - followed by the following conversino specifiers: 

                if(*look_ptr == 's'){
                    // string conversion
                    char* arg_str_ptr = va_arg(args, char*);
                    int str_len = my_strlen(arg_str_ptr); // calc length of input str
                    int rem_len = my_strlen(scan_ptr+2); //take current scan_ptr pos and determine remaining length
                    // printf("\nstr_len -> %i\n", str_len);
                    // printf("\nrem_len -> %i\n", rem_len);
                    // printf("\ncount -> %i\n", count);

                    char temp_str[rem_len];
                    char* ptr_temp_str = temp_str;
                    char* ref_scan_ptr = scan_ptr + 2;

                    for(int i = ((count-1) - rem_len);i<count;i++){
                        *ptr_temp_str++ = *ref_scan_ptr++;
                    }

                    printf("\nTemp storage string -> %s\n", temp_str);


                    while(*arg_str_ptr != '\0'){
                        *look_ptr++ = *arg_str_ptr;
                        count += 1; // printf("counter++");
                        arg_str_ptr++;
                    }
                    scan_ptr += str_len;
                    // *look_ptr = 26;
                }

                if(*look_ptr == '%'){
                    count += 1; // make space for the counter
                    *look_ptr = '%';
                }

                if(*look_ptr == 'i'){
                    // printf("\n i character recognised \n");
                    // take the integer given and convert to character?                   
                    char ch = va_arg(args, int) + '0';
                    count += sizeof(ch);
                    *look_ptr = ch; // can you change the original str??
                }

                if(*look_ptr == 'd'){
                    // signed decimal notation
                }

                if(*look_ptr == 'o'){
                    // unsigned int argument - convert to octal
                }

                if(*look_ptr == 'u'){
                    // unsigned decimal
                }

                if(*look_ptr == 'x'){
                    // unsigned hexadecimal
                }

                if(*look_ptr == 'p'){
                    // pointer argument printed in hexadecimal
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
                //if array of char arrays greater than 0 then copy in contents
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
    my_printf("Test 1 -> Hello, World! 1234 !@£$\n");
    my_printf("Test 2 -> int 1 : %i, int 2 : %i, int 3 : %i\n", 5, 4, 3);
    my_printf("Test 3 -> percentage sign -> %%\n");
    char message[] = "MESSAGE";
    my_printf("Test 3 -> String - %s - Inserted\n", message); // printf("Test String %s\n", message);
    return 0;
}

// ---------

// malloc perservering after va_ends:
// the memory allocated using malloc will persist past the va_end call. The va_end macro is used to clean up the memory used by the va_list macros, but it does not affect any memory allocated with malloc


// The last name parameter: va_start:
// The named parameter in va_start is simply the last parameter before the ellipsis (...)

