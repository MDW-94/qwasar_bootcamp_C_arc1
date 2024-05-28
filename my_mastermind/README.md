# <h1 align="center" >&#128290; my_mastermind.c &#128290;</h1>

![Alt Text - "Will you find the secret code?" The opening line of the game](./screenshots/Screenshot_1.png)

<div align="center">
<img src="{https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white}"/>

A text-based game written in C that takes user input and evaluates it against a declared/randomly generated secret code. 
  
Based of the classic code-breaking game Mastermind, the goal is to guess the four integer secret code within 10 or a designated number of rounds. If a valid guess isn't correct then feedback will be provided - 'well-placed' integers are ones that are correct in value and position, 'misplaced' integers are ones that are correct in value but inocrrect in position.

**If the player finds the code, they win, and the game stops.**

>The game runs in the terminal,  
>recieving input through STDIN (the keyboard).  
>Ctrl + d (^d) has been implemented  
>to end the program at the players' discretion.
  
</div>

![Alt Text - A screenshot of the game running, specifically the text prompts in the terminal](./screenshots/Screenshot_2.png)

## Table of Contents
- [Task](#task)
- [Installation](#installation)
- [Usage](#usage)
    -[ Customise](#customising-your-game)

## Task
As part of the Elite software Engineering track through Qwasar, Contemporary School of Engineering I was assigned the task of recreating the famous Mastermind game using C.

The assignment required me to create a Makefile which would handle all the compilation processes of the program, including cleanup (clean/fclean (full-clean)). 

&#9989; **I was allowed to use only specific functions within certain header file libraries, these include:**

- printf()
- write()
- read()
- rand() (/srand())
- time()
- atoi()
- strcmp()

*It was a requirement that read() be set to read in only one char data type at a time: read(0,&ch,1)*

&#10060; **I was not allowed to use any other functions/syscalls, this included exit**

### Further Requirements:
- the program handles the standard *Ctrl + d* (EOF/End Of File) sequence
- Must be compiled with -Wall -Wextra -Werror
- Multiline macros are forbidden
- Macros with logic are forbidden (while/if/variables/...)


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