#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #define RAND_MAX 9

// #ifndef GAME_SETTINGS
// #define GAME_SETTINGS
// typedef struct game_settings {
//     char* secret_code;
//     int n_attempts;
// } settings;
// #endif

// char* generate_code(){
//     char* result_code[4] = {'1','2','3','4'};
//     return result_code;

// }

char generate_secret_code(int ac, char** av, const int pieces_size, char secret_code[]){
      if(ac > 1){ //if there are any args in run command
        char code_param[1]; *code_param = atoi(av[1]);
        if(strcmp(code_param, "-c") && av[2]){
            printf("\nDeclared Secret Code: Initializing...\n");
            for(int i = 0; i < 4;i++){
                secret_code[i] = av[2][i];
            }
        }
        } else {
            printf("\nGenerating secret code...\n");
            srand(time(0)); 
            // required before rand() to use timestamp as seed for rand generator
            for(int i = 0; i < 4;i++){
                int number = (rand() % pieces_size);
                // printf("%i\n", number);
                secret_code[i] = '0' + number;
            }
         }
    return *secret_code;
}

int initialize_rounds(int ac, char** av){
    if(ac > 1){
        char code_param[2]; *code_param = atoi(av[3]);
        if(strcmp(code_param, "-t") && av[4]){
            return atoi(av[4]);
        }
    }
    return 10;
}


// int ac, char** av
int main(int ac, char** av){

    time_t sec;
    time(&sec);

    printf("\n=========================================\n");
    printf("\nHello, my_mastermind -> initializing...\n");
    printf("Time: %.24s\n", ctime(&sec));
    printf("\n=========================================\n");

    // Array of numbers "Pieces"
    const int pieces_size = 9;
    char pieces[pieces_size] = {'0','1','2','3','4','5','6','7','8'}; // necessary?
    char secret_code[4];
    int rounds_declared = 0;

    generate_secret_code(ac, av, pieces_size, secret_code); 

    printf("Secret Code: %s\n", secret_code);

    // Secret code = n1,n2,n3,n4 where n is an int from array || specified code av[x] == '-c x'
    // int attempts = default: 10 || specfiied av[x] == '-t x'

    // switch(){} for multiple if statements?
    // default: // 

    printf("\n=========================================\n");

    printf("\nInitializing pieces in array - necessary?\n\n");

    for(int i = 0; i < pieces_size;i++){
            printf("Piece %i -> %c\n", i, pieces[i]);
    }

    printf("\n=========================================\n");
    printf("\nStarting Game...\n\n");

    rounds_declared= initialize_rounds(ac, av);

    printf("\nRounds Declared -> %i\n", rounds_declared);



    return 0;
}


// https://www.geeksforgeeks.org/time-function-in-c/

// https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm


// Secret Code Generator:
        // if(ac > 1){ //if there are any args in run command
        // char code_param[2]; *code_param = atoi(av[1]);

        // if(strcmp(code_param, "-c") && av[2]){
        //     while(*secret_code != '\0'){
        //         *secret_code = atoi(av[2]);
        //     }
        // }

        // char attempt_param[1] = atoi(av[3]);
        // } else {
        // *secret_code = generate_code();

            // printf("\nGenerating secret code\n");
            // srand(time(0)); 

            // required before rand() to use timestamp as seed for rand generator
            
            // for(int i = 0; i < 4;i++){
            //     int number = (rand() % pieces_size);
            //     printf("%i\n", number);
            //     secret_code[i] = '0' + number;
            // }

        // secret_code[0] = rand();
        // secret_code[1] = rand();
        // secret_code[2] = rand();
        // secret_code[3] = rand();
        //  }