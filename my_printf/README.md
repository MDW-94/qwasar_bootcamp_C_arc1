# Welcome to My Printf
***

```
my_printf
│   ├── Makefile
│   ├── README.md
│   └── my_printf.c
```

## Task
To recreate the printf function using variadic functions and variable argument lists in C. 

MVP: a printf function that runs through a Makefile, without other external .c files.

It must write to the standard out the characters passed in as an argument. This includes all the format specifiers which will handle most, but not all special characters - these include : %d, %,o, %u, %x, %c, %s, %p, %%. Finally, it must return the size of the outputted string as an integer.

Requirements: the program must be compiled with the flags -Wall - Wextra -Werror.

-g3 -fsantize-address is allowed.

Global and static variables are strictly forbidden!

#### Authorized Functions
<ul>
    <ul>write(2)</ul>
    <ul>malloc</ul>
    <ul>free</ul>
    <ul>va_start, va_arg, va_copy, va_end</ul>
</ul>

#### Unauthorised Functions
<ul>
    <ul>printf and co. (every printf variation)</ul>
    <ul>Multiline macros are forbidden</ul>
    <ul>Include another .c is forbidden</ul>
    <ul>Macreos with logic (while/if/variables/...) are forbidden</ul>
</ul>

## Description
The my_printf function uses... (malloc, va_list (etc), write, free - returns int return_size)

To create a cleaner and more modular function, within the my_printf are a series of helper and converter functions that fulfill specific tasks. They are a way of breaking up the development and functionality of this program to be more economical as well as readable.

Before each format speficier handler function, a small copying buffer is created to capture the variable argument passed into the my_printf function. Once the contents of this argument is copied into the buffer, it is copied into the final buffer, where it is handled with the rest of the characters to be outputted to the standard out.


### Helper Functions:

#### my_strlen & my_strcpy

- my_strlen
```
int my_strlen(char* str){
    int i = 0; char* temp_ptr = str;
    while(*temp_ptr++ != '\0'){i++;}return i;
}
```
This function traverses an argument string, incrementing a counter which is returned once completed - it return the number of characters within a character array (string).


- my_strcpy
```
char* my_strcpy(char* param_1, char* param_2){
    while((*param_1++ = *param_2++));
    return param_1;
}
```
This function takes two argument strings: the latter being the string in which the cahracters will be copied from, to the the former string which will recieve these characters - it will copy the contents of a given string to another string.

### Converter Functions:

#### number_to_char %i | %d | %u | %h
This function will take in an argument number (of various formats, including decimal, signed and unsigned) and return a buffer populated with the digits of this argument number. 

A third argument, buffer_size of type size_t is passed in, from the my_printf function a sizeof() method is used to capture the size of the array. This is done because passing the array in outright will decay the array to a pointer, losing the information regarding (it will be treated as a 'char*' rather than a 'char[12]').

If this buffer size is 0 then then function ends as no space has been allocated for the transfer performed within this function.

The main body of the function is is to first, convert the number passed in into its absolute form (non-negative). This is done by a series of ternary statements assigned to variables:

```
int is_negative = number < 0 ? 1 : 0; 

unsigned int abs_number = is_negative ? -number : number;
```

Then a series of handlers check certain conditions of the number argument passed into the function:

Handle A Zero Case
```
  if(abs_number == 0 && i < (int)buffer_size - 1){
        buffer[i++] = '0';
    }
```

Process a Non-Zero Number
```
while(abs_number != 0 && i < (int)buffer_size -1){
    buffer[i++] = '0' + abs_number % 10;
    abs_number /= 10; 
}
```
(Note: abs_number /= 10 is the same as abs_number = abs_number / 10)

This section uses the modulo (%) operator within a while loop to retrieve the singular digits of the argument number:

An example would be if the argument number is 123, then 123 % 10 would be 3, as the quotient would be 12 and the remainder would be 3. This can also be thought of as:

123 = 1*10^2 + 2*10^1 + 3*10^0

'1' would be the 100th place (10^2)
'2' would be the 10th place (10^1)
'3' would be the 1st place (10^0)

After this extraction, adding the '0' to this number converts the result to a character (instead of its original integer type).




Handle a negative number:
```
    if(is_negative && i < (int)buffer_size - 1){
        buffer[i++] = '-';
    }
```


#### number_to_octal

#### number_to_hexadecimal

#### pointer_to_memoryAddress





## Installation
TODO - How to install your project? npm install? make? make re?

## Usage
TODO - How does it work?
```
./my_project argument1 argument2
```
