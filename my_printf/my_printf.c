#include "my_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// Try implementing your own tests through unity tersting framework for C
// https://www.throwtheswitch.org/unity



int my_strlen(char* str){
    int i = 0;char* temp_ptr = str;while(*temp_ptr++ != '\0'){i++;}return i;
}

char* my_strcpy(char* param_1, char* param_2){
    while((*param_1++ = *param_2++));
    return param_1;
}

void number_to_char(int number, char* buffer, size_t buffer_size) {
    if (buffer_size == 0) {
        return; // If buffer size is 0, we cannot store anything
    }

    int is_negative = number < 0 ? 1 : 0;
    unsigned int abs_number = is_negative ? -number : number;
    int i = 0;

    // Handle 0 explicitly
    if (abs_number == 0 && i < (int)buffer_size - 1) {
        buffer[i++] = '0';
    }

    // Process each digit
    while (abs_number != 0 && i < (int)buffer_size - 1) {
        buffer[i++] = '0' + abs_number % 10;
        abs_number /= 10;
    }

    // Add negative sign if necessary
    if (is_negative && i < (int)buffer_size - 1) {
        buffer[i++] = '-';
    }

    // Null-terminate the string
    buffer[i] = '\0';

    // Reverse the string
    for (int start = 0, end = i - 1; start < end; start++, end--) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
    }
}

char* number_to_octal(int number, char* buffer, size_t buffer_size) {
    char* buffer_ptr = malloc((buffer_size + 1)*sizeof(char));

    int i = 0, j;
    
    // Special case for 0
    if (number == 0) {
        if (buffer_size >= 2) {
            buffer[0] = '0';
            buffer[1] = '\0';
        }
        return buffer;
    }

    // Convert the number to hexadecimal
    while (number != 0 && i < (int)buffer_size - 1) {
        int remainder = number % 8;
        if (remainder < 10) {
            buffer_ptr[i++] = '0' + remainder;
        } else {
            buffer_ptr[i++] = 'A' + (remainder - 10);
        }
        number = number / 8;
    }

    // Ensure buffer size is sufficient
    if (i >= (int)buffer_size) {
        // Not enough space in the buffer
        return NULL;
    }

    // Convert the array to a string
    for (j = 0; j < i; j++) {
        buffer[j] = buffer_ptr[i - j - 1];
    }
    buffer[i] = '\0';

    return buffer;
}

char* number_to_hexadecimal(int number, char* buffer, size_t buffer_size) {
    int hexaNumber[32];
    int i = 0, j;
    
    if (number == 0) {
        if (buffer_size >= 2) {
            buffer[0] = '0';
            buffer[1] = '\0';
        }
        return buffer;
    }

    while (number != 0 && i < (int)buffer_size - 1) {
        int remainder = number % 16;
        if (remainder < 10) {
            hexaNumber[i++] = '0' + remainder;
        } else {
            hexaNumber[i++] = 'A' + (remainder - 10);
        }
        number = number / 16;
    }

    if (i >= (int)buffer_size) {
        return NULL;
    }

    // Convert the array to a string
    for (j = 0; j < i; j++) {
        buffer[j] = hexaNumber[i - j - 1];
    }
    buffer[i] = '\0';

    return buffer;
}

// char* pointer_to_memoryAddress(char* ptr_ptr, char* buffer, size_t buffer_size){
//     int hexaNumber[32];
//     int i = 0, j;

//     int x = &ptr_ptr;

//     if(ptr_ptr == NULL){
//         if(buffer_size >= 2){
//             buffer[0] = '0';
//             buffer[1] = '\0';
//         }
//         return buffer;
//     }

//     while(x != NULL && i < (int)buffer_size - 1){

//     }

//     if (i >= (int)buffer_size) {
//         return NULL;
//     }

//     for(j = 0; j < i;j++){

//     }
//     buffer[i] = '\0';

//     return buffer;
// }

int my_printf(char* restrict input_str, ...){
    int return_size;
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
                char number_buffer[12]; // Buffer large enough to hold any int value
                number_to_char(number, number_buffer, sizeof(number_buffer));
                for (int j = 0; number_buffer[j] != '\0'; j++) {
                    buffer_ptr[k++] = number_buffer[j];
                }
                i++;
            }

            if(ch1 == 'o'){
                //HANDLE OCTAL
                int number = va_arg(args, int);
                char octal_buffer[9];
                char* ptr_va = number_to_octal(number, octal_buffer, sizeof(octal_buffer));
                for(int j = 0;j<my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                }
                i++;
            }

            if(ch1 == 'x'){
                //HANDLE HEXADECIMAL
                int number = va_arg(args, int);
                char hexa_buffer[9];
                char* ptr_va = number_to_hexadecimal(number, hexa_buffer, sizeof(hexa_buffer));
                for(int j = 0;j<my_strlen(ptr_va);j++){
                    buffer_ptr[k++] = ptr_va[j];
                }
                i++;
            }

            // if(ch1 == 'p'){
            //     // HANDLE POINTER HEXADECIMAL
            //     char* ptr_ptr = va_arg(args, char*);
            //     char hexa_buffer[9];
            //     char* ptr_va = pointer_to_memoryAddress(ptr_ptr, hexa_buffer, sizeof(hexa_buffer));
            //     for(int j = 0;j<my_strlen(ptr_va);j++){
            //         buffer_ptr[k++] = ptr_va[j];
            //     }
            //     i++;
            // }

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
    // printf("\n\n|| COPIED STRING -> %s", buffer_ptr);
    
    char* temp_ptr = buffer_ptr;
    return_size = my_strlen(temp_ptr);
    write(1,temp_ptr,k - 1);

    // ending traversal
    va_end(args);
    // You need to reference the original pointer before freeing it
    free(buffer_ptr);
    // printf("\n###################### End of my_printf ######################\n");
    return return_size;
}

int main(){
    my_printf("Hello, World!\n");
    my_printf("Test 2   -> int 1 : %i, int 2 : %i, int 3 : %i\n", 5, 4, 3);
    my_printf("Test 3   -> char 1 : %c, char 2 : %c, char 3 : %c\n", 'z', 'x', 'y');
    my_printf("Test 4   -> string 1 : %s, string 2 : %s, string 3 : %s\n", "hello", "world", "!!!!!!");
    my_printf("Test 5   -> string 1 : %s, string 2 : %s, string 3 : %s\n", "hello", NULL, "!!!!!!");
    my_printf("Test 6   -> lrg_int 1 : %i, lrg_int 2 : %i, lrg_int 3 : %i\n", 123, 4567, 888999);
    my_printf("Test 7   -> %i, %s, %c, %%, %d\n", 1234567890, "Hello", 'A', -12);
    my_printf("Test 7   -> %i | %d | %o | %x\n", 25, -25, 25, 25);
    my_printf("Test 7b  -> lrg_int 1 : %i, lrg_int 2 : %i, lrg_int 3 : %i\n", 123, 4567, 888999);
    my_printf("Test 8   -> int 1 : %f, int 2 : %f, int 3 : %f\n", 3.5, 99.9, 234.23);
    my_printf("Test 9   -> percentage sign -> %%\n");
    char string[6] = "Hello";
    char* ptr_str = string;
    my_printf("Test 10  -> memory addresses -> | %p |\n", ptr_str);

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

// char* number_to_hexadecimal(int number){
//     // 123456789ABCDE - this is the hexidecimal range, so 32 would be 20, 31 would be 1E
//     // Because when you reach E you hit the last digit and have to start the next counting system
//     // 1000 - this would be respented like 1000 would be 3E8

//     // How to convert 1000 to hexadecimal (this formula can be used to create octa as well, it will just be divided by 8 instead of 16 - this is the same for binary, which is the SAME but just divided by 2!):

//     // 1000/16 
//     // Quotient: 62, Remainder: 8 - this is digit 0! (XX8)
//     // Then you take the Quotient and you do it again:
//     // 62/16
//     // Quotient: 3, Remainder: 14 - this is digit 1! (XE8)
//     // - NOTE THAT THIS WHEN THE HEXADECIMAL COUNTING REACHES 15 (123456789ABCDE) -
//     // You keep going until the Quotient is no longer greater than 16:
//     // 3/16
//     // Quotient: 0. Remainder 3 - this is digit 2! (3E8)
//     // The conversion is therefore: 3E8

//     // 1000/16 - save this number (quotient), 1000%16 - save this number (remainder) - do in a for loop until the quotient reaches 0
//     // the first number you get back from the remainder wants to be the last number you print - save the remainder in an array, then print - if greater than 9, perform conversion to ABCDE then print outcome

//     // do hexadeciaml first!

//     // printf("\nhexa start number -> %i", number);
//     int hexaNumber[32];
//     int i = 0, j;

//     while(number != 0){
//         hexaNumber[i++] = number%16;
//         number = number/16;
//         printf("\nhexaNumber -> %i", hexaNumber[i]);
//     }

//     char* out_str = (char*)malloc((i+1)*sizeof(char));

//     for(j = 0;j < i;j++){
//         out_str[j] = hexaNumber[i - j - 1];
//     }
//     out_str[i] = '\0';

//     return out_str;
// }

// char* number_to_octal(int number){
//     // Array to store octal number digits
//     int octalNumber[32];
//     int i = 0, j;

//     // Process the number to convert to octal
//     while(number != 0 ){
//         octalNumber[i++] = number % 8;
//         number = number / 8;
//     }

//     // Allocate memory for the output string 
//     char* out_str = (char*)malloc((i + 1)*sizeof(char));
//     if(!out_str){
//         // Handle malloc failure
//         return NULL;
//     }

//     // Convert the digits to characters in reverse order
//     for(j = 0; j < i;j++){
//         out_str[j] = octalNumber[i - j - 1] + '0';
//     }
//     // reverse the order of digit assignment by leveraging the fact that
//     // the digits in 'octalNumber' are stored from least significant
//     // to most significant (right to left) - while the 'out_st'
//     // needs to stoore these digits from most significant to least significant
//     // (left to right) - [i - j - 1] reverses the order

//     // Null-terminate the string
//     out_str[i] = '\0';

//     return out_str;
// }

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

// char* number_to_char(int number){
//     // printf("\n handle large number -> %i\n", number);

//     int is_negative = number < 0;
//     unsigned int abs_number = is_negative ? -number : number;
//     int temp = abs_number;

//     int n = (temp >=          10) + (temp >=         100) + (temp >=        1000) +
//             (temp >=       10000) + (temp >=      100000) + (temp >=     1000000) +
//             (temp >=    10000000) + (temp >=   100000000) + (temp >=  1000000000) + 1;

//     n += is_negative;
    
//     char *ptr_output = (char*)malloc(n + 1);
//     if(!ptr_output){
//         return NULL;
//     }

//     ptr_output[n] = '\0';

//     for(int i = n; i > 0; i--){
//         ptr_output[i-1] = '0' + abs_number%10;
//         abs_number /= 10;
//     }

//     if(is_negative){
//         ptr_output[0] = '-';
//     }

//     // https://www.reddit.com/r/C_Programming/comments/xxcxdu/faster_way_to_convert_double_to_string_not_using_f/

//     // printf("\n handle large number out -> %s\n", ptr_output);

//     return ptr_output;
// }

//     int number = va_arg(args, int);
//     char* ptr_va = number_to_char(number);
//     for(int j = 0;j< my_strlen(ptr_va);j++){
//         buffer_ptr[k++] = ptr_va[j];
//     }
//     i++;
// } 