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
- [Key Features || Code Breakdown](#key-features-code-breakdown)

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

<hr/>

2. **To declare the number of Rounds**:

```bash
./my_mastermind.c -t <"No. of Rounds">
```

*(Note: Replace <"No. of Rounds"> with a valid number, e.g. ./my_mastermind -t 20)*

<hr/>

3. **To Declare both a Secret Code and a Number of Rounds**:

```bash
./my_mastermind.c -c <"4 digit code"> -t <"No. of Rounds">
```

## Key Features (Code Breakdown)

### - Command-Line Arguments 

As specified by MVP the program accepts command line arguments that define certain parameters of the game at runtime. Within the mian function, the command line arguments are set to 'int ac' (argument count - the number of command line argumetns being passed in) & 'char** av' (argument vector - an array of arrays containing the arguments passed into the program as strings).

These include:

1. "-c"
2. <4-Digit Array>
3. "-t"
4. <"Number of Rounds">

These arguments are passed to the respective functions 'generate_secret_code' and 'initialize_rounds' where they are handled to specify customisable properties for the games setup.

### - generate_secret_code()

This function takes a total of four parameters and makes use of a self-built 'my_strcpy', strcmp, srand, time and rand utilities. The first two parameters 'ac' and 'av' are the command line arguments defined by the user at compilation time. This function observes the value of ac, noticing that if it is greater than '1' (ie. it has more values than just the program name) then it is to check the second command line argument being passed with the value "-c", determining whether the player is deciding to declare a secret code for play. As this comparison is nested within an if statement there are two potential results for this function:

1. The first result is that the self-built 'my_strcpy' will copy the contents of the second array in the argument vector parameter ('av') and copy its contents to the 'secret_code[5]' array - that is defined in the main function.

2. The second result is if there is no intention to declare a secret code for the games setup. This result utilises "srand", this time.h library function seeds the random number generator used by "rand". They work in tandem in order to output a random numerical value - in order for this value to remain within the bounds of 0-9 a modulo is used in conjunction with 'pieces_size' variable (equivalent to 9). As the program uses char data tpyes, after the number is radomly generated each number is added to the charcater value '0' in order to convert it to a char data type.

At the end of both results the final index value of the secret_code array is initialized to '\0'.

This funcion ultimately returns void as the secret code array is declared with the main function. Therefore, the initialized values resulting from the generate_secret_code function are available to be passed through the other functions that run throughout the rest of the game.

### - initialize_rounds()

Similarly to the generate_secret_code function this function accepts the argument count and argument vector parameters. Allowing the user to declare the number of rounds for the game they are about to play, if none are declared then the default value is 10 rounds.

The strcmp (string comparison) function is nested within an if statement, if the value returned from strcmp is 0 (ie. there is no difference between the two strings) then the function will run, providing there is a value at the fourth index position of the argument vector array. The comparison is made against "-t".

If the conditions of the if statement are met, then the function calls the atoi function. This function converts the array at the index position of the parent array in the argument vector into a returned value that can be stored in a variable to be used in the program. In this case, it will take the integer value and set the rounds_declared variable to this value.

### - game_engine()

This function is responsible for the running of the entire game. It takes two parameters, a character array (which will be our secret code) and an integer (which will be the number of rounds declared). A couple of integer variables are declared and initialized to 0 (rounds_index, answer_check).

A while loop is declared and bound to the condition that if the rounds_index is less that the rounds_declared (the number of rounds set for the game) then the loop will trigger the following - importantly it will also only run if the answer_check does not reach 1:

During each iteration, a pair of print statements create the visual implication of each round for the player (Round 1, Round 2 etc.). At this point the iteration of the while loop declares and empty array which will be populated with the players input. In order to populate this array the **read_input** function is called - this will be discussed in another section. This function essentially populates the empty array variable defined at each round using a pointer variable and the array itself - the function will return an integer.

If this integer returned is anything other than 1 then the game will end, as this is how errors or EOF is handled within the game. If the value returned is 1 then a strcmp, nested in an if statement is declared. If there are no differences between the secret_code variable and the newly populated player_answer character array then the game ends (as the answer_check is then set to 1 triggering the end of the while loop) - as the player has successfully guessed the secret code!

If the player has not managed to guess the Secret Code then the **determine_diff** function is called, which will perform an evaluation of the two character arrays (the secret code & the players inputtedf answer). After this evaluation, the round_index is incremented, trigger the next while loop iteration and thus the next round of the game that allows for the player to continue guessing.

### - read_input()

This function is responsible for taking user input from STDIN and analysing whether it is an acceptable input for the determine_diff function. It accepts two parameters, the empty character player_answer and a pointer to its first index poisition.

Firstly, this function clears the array of any potential values leftover from previous guesses, initializing the array so it is ready to accept the values from STDIN. 

A parent while loop is triggered to handle the conditions of the read() function utilised in this read_input function.

**Read():**

This function is responsible for reading in data by a specified amount into a buffer. In this scenario, I have changed the buffer to be the player_answer array so that when the STDIN input from the keyboard is read it is stored directly in the place it needs to be. The read functions first argument is the location of where the data will be read from (here it is set to 0, which is stdin), the second is the location of where the dat will be stored (here this is set to the pointer created for the array) and finally the integer at the end specifies the number of bytes of data to be read at a time (in this asisgnment it is required that it be set to 1).

There were a few issues that I encountered when using read as it was set to read one byte at a time - the main issue was handling a EOF sequence from the user input, as this is overrided whilst the nested read() function is being called within the while loop. As a result there are some if statements to handle the stream of character data as it is being read in.

As the while loop is called several integer variables, a character variable and a pointer variable (set to the positino of the original pointer) are declared - these variables are a menas of either dynamically changing the buffer of the read() function, creating conditions that are met as the data is being read in (in order to trigger EOF or other conditions) or to populate the player_answer array with the users input.

Since read() returns and integer which corresponds to the number of bytes it has read upon being called, the while loop is bound to the condition that while read does not return 0 or -1 (ie. it is still reading characters and hasn't reached the end of the input) then the if statements within are called. Note, there is also a condition to evaluate the character at the dereferenced pointer position, this is to stop a newline being passed into the player_answer array before four characters are declared.

The first sequence of if statements handle EOF - they evaluate whether the dereferenced pointer is equivalent to ctrl + d. It is a two-stage unlocking process of the while loop, the first if statement allows the second to trigger and as a result, end the while. During this process the buffer is swapped to the address of the empty character variable, which is later used to deal with buffer overflow but here it is to prevent unwanted values being placed within the array. This final if statement returns "result = 1" which will terminate the parent while loop, containing the read while loop.

Further handling of the data stream includes the next if statement which evaluates whether the character read in is within the correct range required for the games evaluation (0-9). If the value at the dereferenced pointer position is not within this range, or it is a newline character then the "x" integer variable is set to 2 - this is an error handling process which prevents the data being sent to the player_answer array aand instead returns a "Wrong Input!" message to the player. This is a requirement of the game and means that the player, within the same turn, can input another until that answer is suitable for evaluation (thus incrementing to the next round or wining the game).

