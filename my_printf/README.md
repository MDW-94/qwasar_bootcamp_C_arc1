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

##### Handle A Zero Case
```
  if(abs_number == 0 && i < (int)buffer_size - 1){
        buffer[i++] = '0';
    }
```

##### Process a Non-Zero Number
```
while(abs_number != 0 && i < (int)buffer_size -1){
    buffer[i++] = '0' + abs_number % 10;
    abs_number /= 10; 
}
```
(Note: abs_number /= 10 is the same as abs_number = abs_number / 10)

###### Modulo Loop (Last Digit Loop):
This section uses the modulo (%) operator within a while loop to retrieve the singular digits of the argument number:

An example would be if the argument number is 123, then 123 % 10 would be 3, as the quotient would be 12 and the remainder would be 3. This can also be thought of as:

123 = 1*10^2 + 2*10^1 + 3*10^0

'1' would be the 100th place (10^2)
'2' would be the 10th place (10^1)
'3' would be the 1st place (10^0)

After this extraction, adding the '0' to this number converts the result to a character (instead of its original integer type). Adding a digit to '0' results in the ASCII value for the corresponding character.

After this the converted, singular character is added to the small copy buffer created in the my_printf function. This has now been populated with one of the values from the variable arguments list.

Finally, the abs_number is divided and reinstantiated by a value of 10. This removes the 0.n digit which will have been created from the modulo operator. As the loop iterates again the abs_number will no longer have the last digit and we be professed again until no digits remain:

Example:
1st iteration : 123, 3 is extracted, copied and removed. abs_number becomes 12

2nd iteration : 12, 2 is extracted, copied and removed. abs_number becomes 1

etc.


##### Handle a negative number:
```
    if(is_negative && i < (int)buffer_size - 1){
        buffer[i++] = '-';
    }
```
This section of the number_to_char helper function runs if the is_negative returns 1 (true) and the incrementor for the buffer has not reached the maximum size of specified by buffer_size. It's purpose is to add the '-' character to the buffer array after the number to character conversion. 


##### Reversing the String:
```
 for(int start = 0, end = i -1; start < end; start++, end--){
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
    }
```
Finally, the buffer will have all the correct characters (including sign if necessary) but will be in a reversed order, this is due to the process of extracting the last digit and storing it within the buffer. The process means the outputted stringi s reverse - therefore this section reverses the string. The result here is that the string will be outputted in the same order as the inputted integer argument.

start++ increments, end-- decrements

- 'start = 0' : initializes the 'start' index point to the first element of the array ('buffer[0]')

- 'end = i - 1' : initializes the 'end' index to point to the last valid element of the array. Here, the 'i' represents the number of characters stored in the buffer, so 'i - 1' is the index of the last character

- 'char temp = buffer[start]' : the character at the 'start' index is temporarily stored in the variable 'temp'

- 'buffer[start] = buffer[end]' : the character at the 'end' index is copied to the 'start' index, effectively moving the character from the end of the array to the start

- 'buffer[end] = temp' : the character originally at the 'start' index (stored in 'temp') is copied to the 'end' index, effectively moving the character from the start of the array to the end

This swapping process is repeated for pairs of characters from the start and end of the array, moving inward until the entire array is reversed.

[ 1, 2, 3, 4]

1st iteration: start(1), end(4), temp(1)
[4, 2, 3, 1] temp = 1
2nd interation: start = 2, end = 3, temp = 2
[4, 3, 2, 1] temp = 2

... until start >= end

This reversal occurs within the buffer that is outputted. So when the function is finally finished, the output of characters in an array will be in the same ordr as the number inputted as an argument.

#### number_to_octal %o
This function takes in a number, a pointer to a buffer (a char type array) and a reference to the size of that buffer (size_t) as arguments.

The purpose of this function is to convert a given number into a [octal format](https://en.wikipedia.org/wiki/Octal).

##### What is octal?
The octal format differs from the decimal format in that the octal format is to base 8, whereas the decimal format is to base 10.

Decimal:
123 = 1*10^2 + 2*10^1 + 3*10^0

Octal:
173 = 1*8^2 + 7*8^1 + 3*8^0

The above values are equal in value in their respective base counting systems. As can be seen, the base 8 system uses digits of 0,1,2,3,4,5,6,7 before looping back round to 0. This differs to decimal which contains 0,1,2,3,4,5,6,7,8,9. Therefore, 12 in decimal would be equal in value to 14 in octal. 

Decimal:
[1,2,3,4,5,6,7,8,9] 1 [1,2] 12

Octal:
[1,2,3,4,5,6,7,8] 1 [1,2,3,4] 14

The above shows that the number of digits/values is equivalent in both the counting systems.

##### Malloc for Buffer
```
   char* buffer_ptr = malloc((buffer_size + 1)*sizeof(char));
```
This function begins by declaring memory on the heap, referencing the buffer_size argument and defining it's size by that of data type char.

This buffer will be used to as a temporary buffer to be read from when teh conversion is completed and outputted to the argument buffer (the buffer passed in which will be populated by the function).

##### Handle 0
```
 if(number == 0){
        if(buffer_size >= 2){
            buffer[0] = '0';
            buffer[1] = '\0';
        }
        return buffer;
    }
```

##### Octal Conversion Loop
```
  while(number != 0 && i < (int)buffer_size - 1){
        int remainder = number % 8;
        if(remainder < 10){
            buffer_ptr[i++] = '0' + remainder;
        }
        number /= 8;
    }
```

This loop iterates for as long as the argument number does not equal 0, it will be diminished each time the loop iterates by the conversion process. The incrementor 'i' is also bound to increment for as long as it is no larger than the argument buffer_size (as an index value reference).

In order to convert, the loop first retrieves the remainder from the argument number. The remainder is then converted to a char type by adding '0' to make it it's ASCII value. Finally, the number is divided by 8 and then reassigned to the number variable. 

First iteration
- remainder = 65 % 8 = 1
- buffer_ptr[0] = '0' + 1 = '1'
- number = 8 / 8 = 1

Second iteration
- remainder = 8 % 8 = 0
- buffer_ptr[1] = '0' + 0 = '0'
- number - 8 / 8 = 1

##### Handle Null Buffer
```
    if(i >= (int)buffer_size) return NULL;
```

##### Reverse-Copy String to Output Buffer
```
    for(j = 0; j < i; j++){
        buffer[j] = buffer_ptr[i - j - 1];
    }
    buffer[i] = '\0';

    return buffer;
```
As 'i' has been incremeneted to the final index position of the string given, it acts as a reference to the end of the array. In this for loop the incrementor 'j' is used to reference 'buffer' ascending index positions and as a decrementor value in the 'buffer_ptr' index positions.

Essentially, the loop decrements through the 'buffer_ptr' reference and copies its contents to the 'buffer' indexes in ascending order.


#### number_to_hexadecimal %x
This function is in practically the same as the number_to_octal function, as it follows the same processes to convert the argument number given into an octal format. The only difference is that there is a handler for when the number hexadecimal value goes beyond 9, as in hexadecimal numbers beyond 9 are represented by the characters a,b,c,d,e and f.

##### What is Hexadecimal?
Is a type of number system that has a base value equal to 16. it is represented as follows:

[0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f]

A side-by-side comparison with the decimal (base 9) system can be seen here:

Decimal Value of 12:

[1,2,3,4,5,6,7,8,9] 1 [1,2] 12

Hexadecimal Value of 12:

[1,2,3,4,5,6,7,8,9,a,b,c] C

As can be seen, in the decimal system the value of 12 is represented as one whole iteration of the number 1 to 9 then a digit of 2.

In the hexadecimal, 12 is represented as C as the value of 12 doesn't quite finish an iteration of the hexdecimal counting system. For example, 30 in hexdecimal would be represented as 1E and 31 would be 1F - this is because when the iteration reaches the value of 16 is will place a digit on the left-hand side to mark that one iteration has been completed.

In this function, when the conversion value goes beyond 9 then the characters a,b,c,d,e and f are used instead.


#### pointer_to_memoryAddress %p
This function takes the a number, buffer, and size_t type (buffer_size) argument in order to return a memory address (hexadecimal value) of a pointer.

##### What is a memory address?
Is an identifier of a unique location in a computer's memory. It is an address (a reference) of a specific piece of data that is stored. Pointers store memory address and can be used to fetch or point towards the data that is marked by the address. In this function, we are essentially converting the pointer into the address to which is points towards. Note, memory addresses are written as hexdecimals as these are compact ways of notation the data.

##### Handle Too Small Buffer Size

```
    if(buffer_size < 2 * sizeof(void*) + 3) return NULL;
```

##### Initial Setup of the Function
```
    unsigned long address = (unsigned long)ptr;
    char hex_digits[] = "0123456789abcdef";

    buffer[0] = '0';
    buffer[1] = 'x';
```
This setup typecasts the argument pointer passed into the function into an 'unsigned long address' (a long integer with no symbol to denote whether it is positive or minus). Afterwards, an array of all the necessary characters for creating a hexdecimal value are instantiated. This is then followed by the final output being created with the first two index position of the outputted buffer defined as '0' and 'x' - this prefix of two digits denote the following value is written in hexadecimal format.

##### Loop With Bit Operations
In a hexdecimal value (base-16) system each digit corresponds exactly to one 'nibble'. A nimble is a 4 bit piece of data. 

In this loop the right shift ('>>') shifts the bits of a number to the right by a specified number of positions. 

Example:
```
x = 0110 0010
x<<4 = 0010 0000
```
Assuming this is an integer of type char which contains only 8 bits, the four bits (from the left) are removed amd 4 new 0 bits are shifted in from the right.

In the above example, a "nibble" would be representative of the '0110' or '0010' chuncks, the 4 bits of data. A byte (8-bits) is composed of two nibbles.

This loop is responsible for extracting a specific 4-bit segment (nibble) from a memory address and converting it into its corresponding hexadecimal character. Shifting bits of the address to the right by 'i*4' effectively moves each nibble to the right. The bitwise '&' is the bitwise AND operator which compares the two numbers, if both are '1' then the result is '1' otherwise it's '0'. '0xF' is used as a mask to isolate the last 4 bits of the shifted value which isolates a single nibble.

## Installation
```
git clone
git pull
```
After updating the local version, use command:
```
make
```
This will being the Makefile compilation pipeline which will compile and run the my_printf.c program with the necesssary compilations flags.

As the makefile is responsible for compiling, cleaning and generally assembling the program, a make command followed by the task is necessary. For example:
```
make fclean
```
Would stand for 'full clean' and would effectively remove all the compiled programs and dependency files.

## Usage
This my_printf function is based on the linux printf (man printf) which effectively outputs any string with format specifier values to the standard output. It is useful for debugging code or seeing representations of data in a visual output. The function made also return certain types of data which correspond to the memory of the program.
```
./my_project argument1 argument2
```
