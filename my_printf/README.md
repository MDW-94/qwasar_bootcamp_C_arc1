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


### Helper Functions:

#### my_strlen & my_strcpy

### Converter Functions:

#### number_to_char

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
