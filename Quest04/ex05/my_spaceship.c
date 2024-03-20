#include <stdio.h>

// Design a simulator for a spaceship.
// This simulator create a virtual "space" and kee;s track of the basic movements and directions of a given ship

// Your job is to keep track of where the ship is and it's orientation relative to its starting point

// The simulator must take in a string of letters that represent a planned flight path for the spaceship

// "RRALALAA is interpretted as Turn right, turn right, advance, turn left, advance, advance"

// Once given this initial flight path, your program must return the x,y coordinates of a ship's final destination as well as it's orientation relative to the starting point

// Orientation is represented as eft, right, up or down

// Space is infinite, so the x,y coordinates you return could be placed on a seemingly infiinite grid and can be negatieve or positive values

// EG upward facing ship at 0,0 - takes "RRALAA" - the finish will be 2, -1 and orientation will be right (facing right)

// OUTPUT: "{x: X, y: Y, direction: 'DIRECTION'}" - struct?
// This function returns a STRING

// you can use 'snprintf'

#ifndef STRUCT_DIRECTION_ARRAY
#define STRUCT_DIRECTION_ARRAY
typedef struct s_direction_array {
    int x_value; // set to 0 at beginning of function
    int y_value; // set to 0 at beginning of function
    char** orientation; // initialise with ['up', 'right', 'down', 'left']
} ship_position;
#endif



char* my_spaceship(char* param_1){

    char lit_orient[4][5] = {'up', 'right', 'down', 'left'}; //variable[no. of string][length of string]

    ship_position* position = (ship_position*)malloc(sizeof(ship_position));
    int struct_size = 4; // four arrays of directions
    position->orientation = (char**)malloc(struct_size*sizeof(char*)); // mem allocation for 4 orientation arrays

    position->x_value = 0;
    position->y_value = 0;

    // Automated: (for loop, strlen, strcpy)
    for(int i = 0; i < 4; i++){ // <= 3?
        int orient_size = my_strlen(lit_orient[i]);
        position->orientation[i] = (char*)malloc(orient_size*sizeof(char));
        
    }
    
    
    // Hardcoded:
    position->orientation[0] = (char*)malloc(2*sizeof(char)); // 'up' extra for null?
    position->orientation[1] = (char*)malloc(5*sizeof(char)); // 'right'
    position->orientation[2] = (char*)malloc(4*sizeof(char)); // 'down'
    position->orientation[3] = (char*)malloc(4*sizeof(char)); // 'left'

    position->orientation[0] = 'up';
    position->orientation[1] = 'right';
    position->orientation[2] = 'down';
    position->orientation[3] = 'left';

    // INPUT: "RRAALLAA" string of direcitons

 

    int result_size = 0; //sum of all static characters in result string + dynamic characters in result in string

    char* result_str = (char*)malloc(result_size*sizeof(char));


    // OUTPUT: String w array of x,y coords and orientation

    // sprintf to store all data inside a string

    return result_str;
}


// int main() {
//     int num1 = 10, num2 = 20;
//     char str[30]; // Allocate space for the resulting string

//     sprintf(str, "The numbers are: %d and %d", num1, num2);

//     printf("%s\n", str);  // Output: The numbers are: 10 and 20

//     return 0;
// }

int main() {
    return 0;
}