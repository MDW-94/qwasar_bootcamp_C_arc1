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