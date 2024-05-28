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
- [Installation](#installation)
- [Usage](#usage)
    -[ Customise](#customising-your-game)

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

### MVP

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