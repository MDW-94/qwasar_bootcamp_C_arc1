#include <stdio.h>
#include <stdlib.h>

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

int my_strlen(char* str){
    int result = 0;

    while(*str != 00){
        result++;
        str++;
    }

    return result;
}


char* my_spaceship(char* str_og){
    if(str_og == 00){
        return NULL; // or output format default?
    }


    char lit_orientation[4][5 + 1] = {"up", "right", "down", "left"}; //variable[no. of string][length of string] - length of string needs +1

    ship_position* position = (ship_position*)malloc(sizeof(ship_position));

    // X, Y Values:
    position->x_value = 0; // these become our counters
    position->y_value = 0;

    // Orientation:
    int struct_size = 4; // four arrays of directions
    position->orientation = (char**)malloc(struct_size*sizeof(char*)); // mem allocation for 4 orientation arrays

    // Automated: (for loop, strlen, strcpy)
    for(int i = 0; i < struct_size; i++){ // <= 3?
        // Pt. 1
        // int orient_size = my_strlen(lit_orientation[i]);
        position->orientation[i] = (char*)malloc((my_strlen(lit_orientation[i])) + 1*sizeof(char)); // mem allocated, '+1' for null terminator?

        // Pt. 2
        position->orientation[i] = lit_orientation[i]; 
        // assign string literal to array position - potential problem? If so use strcpy to iterate through string literal?
    }

        // Hardcoded:
    // position->orientation[0] = (char*)malloc(2*sizeof(char)); // 'up' extra for null?
    // position->orientation[1] = (char*)malloc(5*sizeof(char)); // 'right'
    // position->orientation[2] = (char*)malloc(4*sizeof(char)); // 'down'
    // position->orientation[3] = (char*)malloc(4*sizeof(char)); // 'left'

    // position->orientation[0] = 'up';
    // position->orientation[1] = 'right';
    // position->orientation[2] = 'down';
    // position->orientation[3] = 'left';

    // INPUT: "RRAALLAA" string of direcitons



        // TESTING PT. 1
    printf("Testing // Initialised Struct x_value: %i\n", position->x_value);
    printf("Testing // Initialised Struct y_value: %i\n", position->y_value);

    for(int i = 0; i < 4;i++){
        printf("Testing // Initialised Struct orientation array %i: %s\n", i, position->orientation[i]);
    }
    
    printf("\n");


    // DETERMINE X, Y & ORIENTATION

    int orientation_counter = 0; // counter for orientation
    char char_at_i;
    int str_og_size = my_strlen(str_og); // size of input string
    printf("str_og_size variable %i\n", str_og_size);
    printf("\n");
    for(int i = 0; i < str_og_size;i++){ 
        // iterate for amount of char in input string
        // remember to dereference the pointer!
        char* char_address = str_og + i; //pointer is incremented according to value of iteration
        char_at_i = *char_address;
        printf("char_at_i initialised with %c\n", char_at_i);

        if(char_at_i != 'R' && char_at_i != 'L' && char_at_i != 'A'){
            return NULL;
        } //handle incorrect input

        // HANDLE R

        if(char_at_i == 'R'){ //ascii 82
            orientation_counter++;

             if(orientation_counter > 3){
                orientation_counter = 0;
                printf("| Action: orientation counter was reset due to reaching ceiling \n| Ship Position %i, %i facing %s\n", 
                position->x_value, 
                position->y_value, 
                position->orientation[orientation_counter]
                );
            } 

            printf("| Action: orientation counter was incremented due to R \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );
        } // if character is R, increment orientation counter - if ceiling reached, reset to 0


        // HANDLE L
        if(char_at_i == 'L'){ // ascii 76
            orientation_counter--;

              if(orientation_counter < 0){
                orientation_counter = 3;
                printf("| Action: orientation counter was set to 3 due to decrementing below 0 \n| Ship Position %i, %i facing %s\n", 
                position->x_value, 
                position->y_value,
                position->orientation[orientation_counter]
                );
            }

        
            printf("| Action: orientation counter was decremented due to L \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );

          
        } // if character is L, decrement orientation counter - if bottom is reached, set counter to 3


        // HANDLE A 
        if(char_at_i == 'A' && orientation_counter == 0){ // ascii 65
            position->y_value++;

            printf("| Action: y incremented - due to A && up \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );
        }

        if(char_at_i == 'A' && orientation_counter == 1){
            position->x_value++;

            printf("| Action: x incremented - due to A && right \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );

        }

        if(char_at_i == 'A' && orientation_counter == 2){
            position->y_value--;

            printf("| Action: y decremented - due to A && down \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );
        }

        if(char_at_i == 'A' && orientation_counter == 3){
            position->x_value--;
            
            printf("| Action: x decremented due to A and left \n| Ship Position %i, %i facing %s\n", 
            position->x_value, 
            position->y_value, 
            position->orientation[orientation_counter]
            );
        }

        printf("\n");

    }

        // TESTING PT. 2
    printf("Testing // Updated Struct x_value: %i\n", position->x_value);
    printf("Testing // Updated Struct y_value: %i\n", position->y_value);
    printf("Testing // Updated Struct orientation value: %s\n", position->orientation[orientation_counter]);


    // Now the struct x, y values are updated && we have the index reference for which position the ship is facing

    // "{x: X, y: Y, direction: 'DIRECTION'}" - strlen?
 
    int result_size = my_strlen("{x: X, y: Y, direction: 'right'}"); //sum of all static characters in result string + dynamic characters in result in string

    char* result_str = (char*)malloc(result_size*sizeof(char)); // malloc needed for the end?

    sprintf(result_str, "{x: %i, y: %i, direction: '%s'}", 
    position->x_value,
    position->y_value,
    position->orientation[orientation_counter]
    );

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

    char* test_1 = (char*)malloc(10*sizeof(char)); // 10 just a random amount, could be more accurate
    // test_1 = "RAALLRA";
    test_1 = "RRALAA";

    printf("FINAL OUTPUT: %s\n",my_spaceship(test_1));

    return 0;
}