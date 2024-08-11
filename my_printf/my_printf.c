#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_strlen(char* str){
    int i = 0; char* temp_ptr = str;
    while(*temp_ptr++ != '\0'){i++;}return i;
}

char* my_strcpy(char* param_1, char* param_2){
    while((*param_1++ = *param_2++));
    return param_1;
}

void number_to_char(int number, char* buffer, size_t buffer_size){
    // size_t = unsigned, hypothetical integer type 
    if(buffer_size == 0) return;

    int is_negative = number < 0 ? 1 : 0; 
    unsigned int abs_number = is_negative ? -number : number;
    int i = 0;

    // Handle 0
    if(abs_number == 0 && i < (int)buffer_size - 1){
        buffer[i++] = '0';
    }

    while(abs_number != 0 && i < (int)buffer_size -1){
        buffer[i++] = '0' + abs_number % 10;
        abs_number /= 10; // abs_number = abs_number / 10
    }

    if(is_negative && i < (int)buffer_size - 1){
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    for(int start = 0, end = i -1; start < end; start++, end--){
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
    }
}

char* number_to_octal(int number, char* buffer, size_t buffer_size){
    char* buffer_ptr = malloc((buffer_size + 1)*sizeof(char));
    int i = 0, j;

    // Handle 0
    if(number == 0){
        if(buffer_size >= 2){
            buffer[0] = '0';
            buffer[1] = '\0';
        }
        return buffer;
    }

    // Convert to octal 
    while(number != 0 && i < (int)buffer_size - 1){
        int remainder = number % 8;
        if(remainder < 10){
            buffer_ptr[i++] = '0' + remainder;
        }
        number /= 8;
    }

    if(i >= (int)buffer_size) return NULL;

    for(j = 0; j < i; j++){
        buffer[j] = buffer_ptr[i - j - 1];
    }
    buffer[i] = '\0';

    return buffer;
}

char* number_to_hexdecimal(int number, char* buffer, size_t buffer_size){
    int hexaNumber[32];
    int i = 0, j;

    if(number == 0){
        if(buffer_size >= 2){
            buffer[0] = '0';
            buffer[1] = '\0';
        }
        return buffer;
    }

    while(number != 0 && i < (int)buffer_size - 1){
        int remainder = number % 16;
        if(remainder < 10){
            hexaNumber[i++] = '0' + remainder;
        } else {
            hexaNumber[i++] = 'A' + (remainder - 10);
        }
        number /= 16;
    }

    if(i >= (int)buffer_size) return NULL;

    for(j = 0; j < i;j++){
        buffer[j] = hezNumber[i - j - 1];
    }
    buffer[i] = '\0';

    return buffer;
}