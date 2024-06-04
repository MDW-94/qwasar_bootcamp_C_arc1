#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


// GLOBAL AND STATIC VARIABLES ARE FORBIDDEN

// Function produces output according to a format as described below - write to stdout, the standard output stream

// writes the output under the control of a format string that specifies subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3) are converted for output

// the format string is composed of zero or more directives: ordinary characters(not percent), which are copied unchagned to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments

// Each converrsion specification is introduced by the percent character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the percent, the following appears on the screen:

// doux - the int(or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadeciaml (x)
// c - the int argument is converted to an unsigned char, and the resulting character is written
//s - the char* argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NULL character
//p - the void * pointer argument is printed in hexadecimal

// Hints - man printf, man 3 stdarg, watch out for memory leaks, test your code with debugging flags -g3 -fsanitize=address, global variables are strictly forbidden, static variables are strictly forbidden

// authorized functions: write(), malloc, free, va_start, va_arg, va_copy, va_end (see man 3 stdarg)

// unathorized functions: printf and co (any print utility), multiline macros are forbidden, including another .c file is forbidden, macros with logic (while/if/variables/...) are forbidden



int main(int ac, char** av){

    char* str;
    str = (char*) malloc(100*sizeof(char));

    if(ac > 1){
        char ch;
        write(1,&ch,1);
    } else {
        printf("\nNo stdin available");
    }



    return 0;
}

// stdin has the file descriptor 0.
// stdout has the file descriptor 1.
// stderr has the file descriptor 2.

// You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address

// ac is a number of parameters passed to the program.
// char ** av is an array of arguments.

