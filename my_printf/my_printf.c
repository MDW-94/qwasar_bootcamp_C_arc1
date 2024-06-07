#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int my_printf(const char* restrict format, ...){
    int count = 0; // Needs to be initialized to no. of chars in char array
    va_list args;
    va_start(args, count);

    // enough space for end terminator:
    char* total = malloc((count + 1)*sizeof(char)); 
    if(total == NULL){return NULL;};

    
}

int main(){
    my_printf("Hello World!\n");
    return 0;
}