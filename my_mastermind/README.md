# my_mastermind.c

![Alt Text - "Will you find the secret code?" The opening line of the game](./screenshots/Screenshot_1.png);

A text-based game written in C that takes user input and evaluates it against a declared/randomly generated secret code. 

Based of the classic code-breaking game Mastermind, the goal is to guess the four integer secret code within 10 or a designated number of rounds. If a valid guess isn't correct then feedback will be provided - 'well-placed' integers are ones that are correct in value and position, 'misplaced' integers are ones that are correct in value but inocrrect in position.

The game runs in the terminal, recieving input through stdin (the keyboard). Ctrl + d (^d) has been implemented to end the program at the players' discretion. 

![Alt Text - A screenshot of the game running, specifically the text prompts in the terminal](./screenshots/Screenshot_2.png)

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)

## Installation

## Usage

To run the project, use the following commands (assuming repository has been pulled to local directory):

```bash
make
```