#include <stdio.h>
#include <time.h>

#ifndef GAME_SETTINGS
#define GAME_SETTINGS
typedef struct game_settings {
    char* secret_code;
    int n_attempts;
} settings;
#endif


// int ac, char** av
int main(){

    time_t sec;
    time(&sec);

    // Array of numbers "Pieces"
    const int pieces_size = 9;
    char pieces[pieces_size] = {'0','1','2','3','4','5','6','7','8'};

    char secret_code[4];
    // Secret code = n1,n2,n3,n4 where n is an int from array || specified code av[x] == '-c x'
    // int attempts = default: 10 || specfiied av[x] == '-t x'


    // switch(){} for multiple if statements?

    // default: // 



    printf("\nHello, my_mastermind -> initializing...\n");
    printf("Time: %.24s\n\n", ctime(&sec));

    for(int i = 0; i < pieces_size;i++){
            printf("Piece %i -> %c\n", i, pieces[i]);
    }

    printf("Secret Code: %s\n", secret_code);


    return 0;
}


// https://www.geeksforgeeks.org/time-function-in-c/