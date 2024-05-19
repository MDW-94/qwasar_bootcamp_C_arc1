#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char generate_secret_code(int ac, char** av, const int pieces_size, char secret_code[]){
      if(ac > 1){ //if there are any args in run command
        char code_param[1]; *code_param = atoi(av[1]);
        if(strcmp(code_param, "-c") && av[2]){
            printf("\nDeclared Secret Code: Initializing...\n");
            for(int i = 0; i < 4;i++){
                secret_code[i] = av[2][i];
            }
            secret_code[4] = '\0';
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
            secret_code[4] = '\0';
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

int check_player_answer(const char* answer){
    int counter = 0;
    while(*answer != '\0'){
        if(*answer > '9' || *answer < '0'){
            return 0;
        }
        // printf("%c\n", *answer);
        counter++;
        answer++;
    }
    if(counter > 4 || counter < 4){
        return 0;
    }
    return 1;
}

void determine_diff(char* answer, char* secret_code){
    // SETUP
    int well_placed     = 0;
    int misplaced       = 0;
    int index           = 0;
    int check_answer[4] = {0,0,0,0};
    int check_code[4]   = {0,0,0,0};

    // PT.1
    while(answer[index] != '\0'){
        if(answer[index] == secret_code[index]){
            // printf("WP Found at index -> %i\n", index);
            well_placed++;
            check_answer[index]     = 1;
            check_code[index]       = 1;
        }
        // printf("\nWhile 1 Index Count: %i\n", index);
        index++;
    }

    // RESET INDEX
    index               = 0;

    // PT.2
    while(answer[index] != '\0'){
        if(answer[index] != secret_code[index]){
            int j       = 0;
            while(secret_code[j] != '\0'){
                if(answer[index] == secret_code[j] 
                && j != index 
                && check_code[j] != 1 
                && check_answer[index] != 1){
                    // printf("Misplaced found at index -> %i | j -> %i\n", index, j);
                    misplaced++;
                    check_answer[index] = 1;
                    check_code[j]       = 1;
                    j                   = 3;
                }
                j++; 
            }
        }
        // printf("\nWhile 2 Index Count: %i\n", index);
        index++;
    }


    printf("----------------------------\n");
    printf("Well placed pieces: %i\n", well_placed);
    printf("Misplaced pieces: %i\n", misplaced);
    printf("----------------------------\n");
}

void game_engine(char secret_code[], int rounds_declared){
    int round_index     = 0;
    int answer_check    = 0;
    printf("Rounds Declared -> %i\n", rounds_declared);
    printf("Secret Code -> %s\n", secret_code);
    while(round_index < rounds_declared && answer_check != 1){
        printf("\n=========================================\n");
        printf("\nRound %i\n", round_index);
        printf("\nSecret Code -> %s\n", secret_code);

        // TAKE USER INPUT
        char player_answer; // declare char variable
        while(read(0, &player_answer, 1)){
            // if(strlen(&player_answer) = 4){

            // }
            // BREAK THE LOOP
        }; 
        // 0 - reads input form keyboard
        // &player_answer - address of the variable where read characters are stored
        // 1 - specifies the number of byes to be read
        
 
        
      

        // if(read(STDIN_FILENO, &player_answer, 4) > 0){
        //     printf("\n%s\n", player_answer);
        // }

        if(strlen(&player_answer) < 4 && strlen(&player_answer) > 0){
            // &player_answer[3] = '\0';
                    // COMPARE INPUT WITH SECRET CODE
            if(strcmp(&player_answer, secret_code) == 0){
                printf(">");
                printf("Success!\n");
                printf("\n=========================================\n");
                answer_check = 1;
            } else {
                printf(">");
                determine_diff(&player_answer, secret_code);
                printf("Try Again\n");
                round_index += 1;
            }
        } else {
            printf("Wrong input!\n");
        }


        //DOESN'T PASS GANDALF
        // scanf("%s", player_answer);

        //      // VET PLAYER ANSWER
        // if(check_player_answer(player_answer) == 0){
        //     printf("Wrong input!\n");
        // } else {
        //     // COMPARE INPUT WITH SECRET CODE
        //     if(strcmp(player_answer, secret_code) == 0){
        //         printf("Success!\n");
        //         printf("\n=========================================\n");
        //         answer_check = 1;
        //     } else {
        //         determine_diff(player_answer, secret_code);
        //         printf("Try Again\n");
        //         round_index += 1;
        //     }
        // }

    }
}

int main(int ac, char** av){

    time_t sec;
    time(&sec);

    printf("\n=========================================\n");
    printf("\nHello, my_mastermind -> initializing...\n");
    printf("Time: %.24s\n", ctime(&sec));
    printf("\n=========================================\n");

    const int pieces_size = 9;
    char secret_code[4];
    int rounds_declared = 0;

    generate_secret_code(ac, av, pieces_size, secret_code); 
    printf("Secret Code: %s\n", secret_code);

    printf("\n=========================================\n");
    printf("\nStarting Game...\n\n");

    rounds_declared= initialize_rounds(ac, av);
    game_engine(secret_code, rounds_declared);

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

// Secret code = n1,n2,n3,n4 where n is an int from array || specified code av[x] == '-c x'
// int attempts = default: 10 || specfiied av[x] == '-t x'

// switch(){} for multiple if statements?
// default: // 
