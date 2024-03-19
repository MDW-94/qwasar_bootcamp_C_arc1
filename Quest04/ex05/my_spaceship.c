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
    int size;
    // array of integers and a string?
} direction_array;
#endif



char* my_spaceship(char* param_1){
    // INPUT: "RRAALLAA" string of direcitons

    // OUTPUT: String w array of x,y coords and orientation

    int result_size = 0; 

    // NEEDS TO BE DETERMINED

    char* result_str = (char*)malloc(result_size*sizeof(char));

    return result_str;
}

int main() {
    return 0;
}