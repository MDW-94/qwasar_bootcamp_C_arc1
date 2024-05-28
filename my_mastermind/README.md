# <h1 align="center" >&#128290; my_mastermind.c &#128290;</h1>

<div align="center">

![Alt Text - "Will you find the secret code?" The opening line of the game](./screenshots/Screenshot_1.png)

**A text-based game written in C that takes user input and evaluates it against a declared/randomly generated secret code.** 
  
Based of the classic code-breaking game Mastermind, the goal is to guess the four integer secret code within 10 or a designated number of rounds. If a valid guess isn't correct then feedback will be provided - 'well placed' integers are ones that are correct in value and position, 'misplaced' integers are ones that are correct in value but inocrrect in position.

**If the player finds the code, they win, and the game stops.**

>The game runs in the terminal,  
>recieving input through STDIN (the keyboard).  
>Ctrl + d (^d) has been implemented  
>to end the program when the player wants.

![Alt Text - A screenshot of the game running, specifically the text prompts in the terminal](./screenshots/Screenshot_2.png)
  
</div>



## Table of Contents
- [Task](#task)
- [MVP](#mvp)
- [Installation](#installation)
- [Usage](#usage)
    -[ Customise](#customising-your-game)
-

## Task
As part of the Elite software Engineering track through Qwasar, Contemporary School of Engineering I was assigned the task of recreating the famous Mastermind game using C.

The assignment required me to create a Makefile which would handle all the compilation processes of the program, including cleanup (clean/fclean (full-clean)). 

#### &#9989; **I was allowed to use only specific functions within certain header file libraries, these include:**

- printf()
- write()
- read()
- rand() (/srand())
- time()
- atoi()
- strcmp()

*It was a requirement that read() be set to read in only one char data type at a time: read(0,&ch,1)*

#### &#10060; **I was not allowed to use any other functions/syscalls, this included exit**

### Further Requirements:
- the program handles the standard *Ctrl + d* (EOF/End Of File) sequence
- Must be compiled with -Wall -Wextra -Werror
- Multiline macros are forbidden
- Macros with logic are forbidden (while/if/variables/...)

## MVP
A program that can generate a randomised 4-digit array of integers, or accept a predetermined 4-digit array through a command-line argument during compilation (ac, av) - this feature will be triggers through "-c". Once the integer array has been generated, a sequence of rounds will allow the player/user to input 4-digit integers in an attempt to guess what the Secret Code is. After each failed attempt the player will recieve feedback as to what integers they have chosen are either 'well placed' or 'misplaced'. The game will run for either 10 rounds, or for a predetermined number of rounds decided at compilation ("-t 20"). The game must return "Wrong Input!" and allow the player to input another answer if they declare an input that is either less or greater than 4-digits OR contains characters outside of 0-9 (only integers may be used). Once the player finds the code - the game ends.

## Installation

This program comes with a Makefile which will handle all the necessary compilation processes for installation.

1. **Clone the repository**:
```bash
git clone <repository URL>
```

2. **Compile program in directory**:
```bash
make
```

## Usage

To run the project, use the following commands (assuming repository has been pulled to local directory):

```bash
make
```
*(Note: This will compile and the run program with the default number of 10 Rounds and a randomly generated Secret Code)*

### Customising Your Game:

1. **To declare a Secret Code**:

```bash
./my_mastermind.c -c <"Your 4 digit code here">
```
*(Note: Replace <"Your 4 digit code here"> with a valid four digit number, e.g. ./my_mastermind -c 1234)*


2. **To declare the number of Rounds**:

```bash
./my_mastermind.c -t <"No. of Rounds">
```

*(Note: Replace <"No. of Rounds"> with a valid number, e.g. ./my_mastermind -t 20)*


3. **To Declare both a Secret Code and a Number of Rounds**:

```bash
./my_mastermind.c -c <"4 digit code"> -t <"No. of Rounds">
```

## Key Features

### Command-Line Arguments 

As specified by MVP the program accepts command line arguments that define certain parameters of the game at runtime. Within the mian function, the command line arguments are set to 'int ac' (argument count - the number of command line argumetns being passed in) & 'char** av' (argument vector - an array of arrays containing the arguments passed into the program as strings).

These include:

1. "-c"
2. <4-Digit Array>
3. "-t"
4. <Number of Rounds>

These arguments are passed to the respective functions 'generate_secret_code' and 'initialize_rounds' where they are handled to specify customisable properties for the games setup.

### generate_secret_code()

This function takes a total of four parameters and makes use of a self-built 'my_strcpy', strcmp, srand, time and rand utilities. The first two parameters 'ac' and 'av' are the command line arguments defined by the user at compilation time. This function observes the value of ac, noticing that if it is greater than '1' (ie. it has more values than just the program name) then it is to check the second command line argument being passed with the value "-c", determining whether the player is deciding to declare a secret code for play. As this comparison is nested within an if statement there are two potential results for this function:

1. The first result is that the self-built 'my_strcpy' will copy the contents of the second array in the argument vector parameter ('av') and copy its contents to the 'secret_code[5]' array - that is defined in the main function.

2. The second result is if there is no intention to declare a secret code for the games setup. This result utilises "srand", this time.h library function seeds the random number generator used by "rand". They work in tandem in order to output a random numerical value - in order for this value to remain within the bounds of 0-9 a modulo is used in conjunction with 'pieces_size' variable (equivalent to 9). As the program uses char data tpyes, after the number is radomly generated each number is added to the charcater value '0' in order to convert it to a char data type.

At the end of both results the final index value of the secret_code array is initialized to '\0'.

