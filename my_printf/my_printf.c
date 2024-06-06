#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


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

int my_strcmp(char* src, char* ref){
  while(*src != '\0' && *ref != '\0' && *src == *ref){
      src++;
      ref++;
    }
  return *(unsigned char*)src - *(unsigned char*)ref;
}

int my_strlen(char* str){
  int i = 0;
  while(*str++ != '\0'){i++;}
  return i;
}

int sum(int count, ...){
  va_list args; // used to hold info needed to retrieve the additional arguments
  
  va_start(args, count); // initializes va_list for use (to then be used with va_arg & va_end) - takes two args: the variable to the va_list and the "last named parameter"

  int total = 0;
  for(int i = 0; i < count;i++){
    total += va_arg(args, int); // retrieves the next argument in the list - takes two args, ref to va_list and the data type of the next argument in that list
  }

  va_end(args); // used to clean the ga_list when youre done - helps avoid memory issues
  return total;

  //va_copy copies the state of one va_list to another - useful if you need to iterate over the args more
}


int main(int ac, char** av) {
  //printf("%s\n", av[0]);

  if(ac > 1){
    char ref_1[] = "-c";
    char* ptr_1 = ref_1;
    for(int i=1;i<ac;i++){
      if(my_strcmp(av[i], ptr_1) == 0){
        char* message = "-c Argument Called \n";

        write(1, message, my_strlen(message));

      } 
      printf("Sum of 1, 2, 3, 4, 5: %d\n", sum(5, 1, 2, 3, 4, 5));
    }
  } else {
    printf("\n No Arguments\n");
  }
  return 0;
}

// stdin has the file descriptor 0.
// stdout has the file descriptor 1.
// stderr has the file descriptor 2.

// You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address

// ac is a number of parameters passed to the program.
// char ** av is an array of arguments.


// https://stackoverflow.com/questions/71790470/standard-input-in-c-with-enough-memory


// -----

// In short, it requests a chunk of memory from the operating system where your program is allowed to store stuff until you free it. This memory:

// lives outside the local scope of a function

// the amount of allocated memory is determined at runtime unlike global data known at compile time (i.e. we don't necessarily know how much memory we will need when the program runs)

// The details of how the memory is managed is more complicated -- the point of the malloc/free API is so you as the programmer don't need to manually manage it.