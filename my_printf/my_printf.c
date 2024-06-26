#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_strlen(char* str){
    int i = 0;char* temp_ptr = str;while(*temp_ptr++ != '\0'){i++;}return i;
}

char* my_strcpy(char* param_1, char* param_2){
    while((*param_1++ = *param_2++));
    return param_1;
}

char* number_to_char(int number){
    printf("\n handle large number -> %i\n", number);

    int is_negative = number < 0;
    unsigned int abs_number = is_negative ? -number : number;
    int temp = abs_number;

    int n = (temp >=          10) + (temp >=         100) + (temp >=        1000) +
            (temp >=       10000) + (temp >=      100000) + (temp >=     1000000) +
            (temp >=    10000000) + (temp >=   100000000) + (temp >=  1000000000) + 1;

    n += is_negative;
    
    char *ptr_output = (char*)malloc(n + 1);
    if(!ptr_output){
        return NULL;
    }

    ptr_output[n] = '\0';

    for(int i = n; i > 0; i--){
        ptr_output[i-1] = '0' + abs_number%10;
        abs_number /= 10;
    }

    if(is_negative){
        ptr_output[0] = '-';
    }

    // https://www.reddit.com/r/C_Programming/comments/xxcxdu/faster_way_to_convert_double_to_string_not_using_f/

    printf("\n handle large number out -> %s\n", ptr_output);

    return ptr_output;
}

// char* number_to_octal(int number){
//     char out_str[32];
//     char* ptr_out = out_str;

//     long quotient, octalnum=0;
//     int octalNumber[100], i = 1, j;
//     quotient = number;

//     while (quotient != 0){
//         octalNumber[i++] = quotient % 8;
//         quotient = quotient / 8;
//     }

//     for(j = i - 1; j > 0;j--){
//         octalnum = octalnum*10 + octalNumber[j];
//         out_str[j] = octalnum + '0';
//     }

//     return ptr_out;

//     // https://www.sanfoundry.com/c-program-convert-decimal-octal/
//     // https://en.wikipedia.org/wiki/Octal
// }

char* number_to_octal(int number){
    // Array to store octal number digits
    int octalNumber[32];
    int i = 0, j;

    // Process the number to convert to octal
    while(number != 0 ){
        octalNumber[i++] = number % 8;
        number = number / 8;
    }

    // Allocate memory for the output string 
    char* out_str = (char*)malloc((i + 1)*sizeof(char));
    if(!out_str){
        // Handle malloc failure
        return NULL;
    }

    // Convert the digits to characters in reverse order
    for(j = 0; j < i;j++){
        out_str[j] = octalNumber[i - j - 1] + '0';
    }
    // reverse the order of digit assignment by leveraging the fact that
    // the digits in 'octalNumber' are stored from least significant
    // to most significant (right to left) - while the 'out_st'
    // needs to stoore these digits from most significant to least significant
    // (left to right) - [i - j - 1] reverses the order

    // Null-terminate the string
    out_str[i] = '\0';

    return out_str;
}

char* number_to_hexadecimal(int number){
    printf("\nhexa start number -> %i", number);
    int hexaNumber[32];
    int i = 0, j;

    while(number != 0){
        hexaNumber[i++] = number%16;
        number = number/16;
        printf("\nhexaNumber -> %i", hexaNumber[i]);
    }

    char* out_str = (char*)malloc((i+1)*sizeof(char));

    for(j = 0;j < i;j++){
        out_str[j] = hexaNumber[i - j - 1];
    }
    out_str[i] = '\0';

    return out_str;
}

int my_printf(char* restrict input_str, ...){
    va_list args;
    va_start(args, input_str);

    int buffer_size = 256;
    char* buffer_ptr = malloc((buffer_size + 1)*sizeof(char));
    if(!buffer_ptr){
        va_end(args);
        return -1;
    }

    int k = 0;

    for(int i = 0; input_str[i] != '\0';i++){
        if(input_str[i] != '%'){
            buffer_ptr[k++] = input_str[i];
        } else {
            // HANDLE FORMAT SPECIFIER
            // printf("\n- Format Specifier Spotted! @ %i -", i);
            char ch1 = input_str[i + 1];
            // printf("\n- ch1 -> %c -", ch1);
            // buffer_ptr[k++] = '@'; // Start of copying in variable length argument

            if(ch1 == 'i' || ch1 == 'd' || ch1 == 'u' || ch1 == 'h'){
                int number = va_arg(args, int);
                char* ptr_va = number_to_char(number);
                for(int j = 0;j< my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                }
                i++;
            } 

            if(ch1 == 'o'){
                //HANDLE OCTAL
                int number = va_arg(args, int);
                char* ptr_va = number_to_octal(number);
                if(ptr_va != NULL){
                    free(ptr_va);
                }
                for(int j = 0;j<my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                }
                i++;
            }

            if(ch1 == 'x'){
                //HANDLE HEXADECIMAL
                int number = va_arg(args, int);
                char* ptr_va = number_to_hexadecimal(number);
                for(int j = 0;j<my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                }
                i++;
            }

            if(ch1 == 'p'){
                //HANDLE POINTER HEXADECIMAL
            }

            else if(ch1 == 'c'){
                buffer_ptr[k++] = va_arg(args, int);
                i++;
            }

            else if(ch1 == 's'){
                char* ptr_va;
                if((ptr_va = va_arg(args, char*)) != NULL){
                    for(int j = 0; j < my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                    }
                    i++;
                } else {
                    char null_result[6] = "(null)";
                    char* ptr_null = null_result;
                    for(int j =0;j<6;j++){
                        buffer_ptr[k++] = ptr_null[j];
                    }
                    i++;
                }
            }

            else if (ch1 == '%'){
                buffer_ptr[k++] = '%';
                i++;
            }
        }
        // printf("\n| index -> !%i | input_str -> %c", k, input_str[k]);
    }
    buffer_ptr[k++] = '\0';
    printf("\n\n|| COPIED STRING -> %s", buffer_ptr);
    
    char* temp_ptr = buffer_ptr;
    write(1,temp_ptr,k - 1);

    // ending traversal
    va_end(args);
    // You need to reference the original pointer before freeing it
    free(buffer_ptr);
    // printf("\n###################### End of my_printf ######################\n");
    return 0;
}

int main(){
    // my_printf("Hello, World!\n");
    // my_printf("Test 2 -> int 1 : %i, int 2 : %i, int 3 : %i\n", 5, 4, 3);
    // my_printf("Test 3 -> char 1 : %c, char 2 : %c, char 3 : %c\n", 'z', 'x', 'y');
    // my_printf("Test 4 -> string 1 : %s, string 2 : %s, string 3 : %s\n", "hello", "world", "!!!!!!");
    // my_printf("Test 4 -> string 1 : %s, string 2 : %s, string 3 : %s\n", "hello", NULL, "!!!!!!");
    // my_printf("Test 5 -> lrg_int 1 : %i, lrg_int 2 : %i, lrg_int 3 : %i\n", 123, 4567, 888999);
    // my_printf("Test 6 -> %i, %s, %c, %%, %d\n", 1234567890, "Hello", 'A', -12);
    my_printf("Test 6 -> %i | %d | %o | %x\n", 25, -25, 25, 160);
    // printf("\nTest 5b -> lrg_int 1 : %i, lrg_int 2 : %i, lrg_int 3 : %i\n", 123, 4567, 888999);
    // my_printf("Test 4 -> int 1 : %f, int 2 : %f, int 3 : %f\n", 3.5, 99.9, 234.23);
    // my_printf("Test 3 -> percentage sign -> %%\n");
    // char message[] = "MESSAGE";
    // my_printf("Test 3 -> String - %s - Inserted\n", message); // printf("Test String %s\n", message);
    return 0;
}

// ---------

// Formats:

// %d - Decimal:            255
// %o - Octal:              377
// %x - Hexadecimal:        ff
// %p = Pointer address:    0x7ffc12345678


// global-buffer-overflow - indicates your program is accessing memory outside the bounds of a defined string literal - often happens when you try to read and write beyond the allocated size of a string or buffer

// sanitize error messages - error type 'global-buffer-overflow' - address '0x00010473eed7 - location in code: my_printf.c:80 && main my_printf.c:94

// Fast Git Commit: gaa && gcmsg "-message-" && ggp  

// malloc perservering after va_ends:
// the memory allocated using malloc will persist past the va_end call. The va_end macro is used to clean up the memory used by the va_list macros, but it does not affect any memory allocated with malloc


// The last name parameter: va_start:
// The named parameter in va_start is simply the last parameter before the ellipsis (...)






//  Formatted Output Conversion
// int my_printf(char* restrict input_str, ...){
//     // Needs to be initialized to no. of chars in char array - my_strlen?
//     va_list args;
//     va_start(args, input_str);
//     // last named parameter is input_str before ellipsis

//     //  create a copy of the original string?


//     // enough space for end terminator:
//     int count;
//     if((count = my_strlen(input_str)) > 0){ //if there are any characters in the string
//         // we now have a number for chars without special characters - we need to know
//         // memory required for special characters:

//         //  TEMP STR MADE THAT CAN BE MODIFIED BEFORE BEING OUTPUTTED
//         char temp_str[count];
//         my_strcpy(temp_str, input_str);
//         char* scan_ptr = temp_str;

//         while(*scan_ptr != '\0'){
//             // "hello, %-" -stop here and:
//             if(*scan_ptr == '%'){
//                 // *scan_ptr = 8; // this works but removes any empty space before special char
//                 *scan_ptr = 26; // this works fine - usually used to mark an erronous data point
//                 char* look_ptr = scan_ptr += 1; // cannot be scan_ptr++ || look_ptr = scan_ptr; look_ptr++; for some reason?
//                 //look at the next character along

//                 // the % is a conversion character - followed by the following conversino specifiers: 

//                 if(*look_ptr == 's'){
//                     // string conversion
//                     char* arg_str_ptr = va_arg(args, char*);
//                     // int str_len = my_strlen(arg_str_ptr); // calc length of input str
//                     int rem_len = my_strlen(scan_ptr+2); //take current scan_ptr pos and determine remaining length
//                     // printf("\nstr_len -> %i\n", str_len);
//                     // printf("\nrem_len -> %i\n", rem_len);
//                     // printf("\ncount -> %i\n", count);

//                     char temp_str2[rem_len];
//                     char* ptr_temp_str = temp_str2;
//                     char* ref_scan_ptr = scan_ptr + 1;

//                     for(int i = ((count-1) - rem_len);i<count;i++){
//                         *ptr_temp_str++ = *ref_scan_ptr++;
//                     }

//                     printf("\nTemp storage string -> :%s\n", temp_str2);


//                     while(*arg_str_ptr != '\0'){
//                         *scan_ptr++ = *arg_str_ptr++;
//                         count += 1; // printf("counter++");
//                     }

//                     // COPIES REMAINING TO THE FINAL
//                     // my_strcpy(temp_str, temp_str2);

//                     // scan_ptr += str_len;

//                     //Set the original temp string
//                 }

//                 if(*look_ptr == '%'){
//                     count += 1; // make space for the counter
//                     *look_ptr = '%';
//                 }

//                 if(*look_ptr == 'i'){
//                     // printf("\n i character recognised \n");
//                     // take the integer given and convert to character?                   
//                     char ch = va_arg(args, int) + '0';
//                     count += sizeof(ch);
//                     *look_ptr = ch; // can you change the original str??
//                 }

//                 if(*look_ptr == 'd'){
//                     // signed decimal notation
//                 }

//                 if(*look_ptr == 'o'){
//                     // unsigned int argument - convert to octal
//                 }

//                 if(*look_ptr == 'u'){
//                     // unsigned decimal
//                 }

//                 if(*look_ptr == 'x'){
//                     // unsigned hexadecimal
//                 }

//                 if(*look_ptr == 'p'){
//                     // pointer argument printed in hexadecimal
//                 }


//             }
//             scan_ptr++;
//         }

//         // After handling the special chars
//         char* output_str = malloc((count + 1)*sizeof(char));
//         if(output_str == NULL){return 0;};

//         for(int i = 0;i<count;i++){
//             if(temp_str[i]){ //if there is a value at temp_str[i]
//                 output_str[i] = temp_str[i];
//                 //if array of char arrays greater than 0 then copy in contents
//             }
    
//         // traverse va_list, fetch ints, convert to char data types:
//         // char ch = va_arg(args, int);

//         // store in final output string:
//         // output_str[i] = ch;
//         }
//         output_str[count] = '\0';
//         va_end(args);


//         // Pt.2 Output the contents of the output str to the stdout:
//         if(my_strlen(output_str) > 0){
//             while(*output_str != '\0'){
//             write(1, output_str, 1);
//             output_str++; 
//             // has to be here as nested incrementation increments first, then runs code block
//             //write(1, output_str, my_strlen(output_str)); THIS WAY MIGHT NOT WORK DUE TO NOT CONSIDERING SPECIAL CHARACTERS?
//             }
//         } else {
//             printf("\n my_printf -> output_str empty\n");
//         }

//     } else {
//         printf("\n malloc failed");
//         return 0;
//         // if(output_str == NULL){return 0;};
//     } 


//     // return output_str? Printf just outputs to the terminal, return is either success, failure or EOF??

//     //free memory after completion
//     // free(output_str);
//     return 0;

// }

// Maybe try substituting in malloc and write in here to make it pass?
