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

int read_input(char* ptr_array, char c_array[]) {

    for(int i = 0 ; i < 4;i++){
        c_array[i] = 0;
    }

  int result = 0;
  while(result != 1){
    int n = 0, index = 0, x = 0; char ch = 00; char* ptr_c = ptr_array;

    while((n = read(0,ptr_c,1)) != 0 && n != -1 && *ptr_c != '\n'){ 

      if(*ptr_c == '^'){
        *ptr_c = '0';
        x = 1;
        }

      if(x == 1 && *ptr_c == 'd'){
        //  printf("EOF\n");
         *ptr_c = '0';
         ptr_c = &ch;
         n = 0;
         return result = 1;
        }

      if((*ptr_c < '0' && *ptr_c != '\n') || (*ptr_c > '9' && *ptr_c != '\n')){
        x = 2;
        // printf("x changes (invalid char - inside read while) %i\n", x);
      }

    //   printf("index %i\n", index);
      index++;
      ptr_c++;

      if(index > 3 && n != 0){
        *ptr_c = '\0';
        ptr_c = &ch;
        // printf("*buffer changed @ %i*\n", index);
        if(index > 4){
            // printf("*buffer changed @ %i*\n", index);
            x = 2;
        }
      }
    }

    // printf("read while loop finished: x -> %i && index -> %i\n", x, index);

    if(n == 0){
    x = 1;
    return 0;
    }

    if(n == -1){
      return result = 1;
    }
    
    if(*ptr_c == '\n' && index < 4){
        *ptr_c = '0';
        x = 2;
        // printf("x changes (input too short - outside read while loop) %i\n", x);
        for(; index < 4;index++){
        c_array[index] = '0';
        }
      }

    if(*ptr_c == '^'){
      *ptr_c = '0';
      x = 1;
      }

    if(x == 1 && *ptr_c == 'd'){
        //    printf("EOF\n");
       *ptr_c = '0';
       ptr_c = &ch;
       n = 0;
       return result = 1;
      }

    if((*ptr_c < '0' && *ptr_c != '\n')|| (*ptr_c > '9' && *ptr_c != '\n')){
      x = 2;
    //   printf("x changes (invalid char (2)) %i\n", x);
        if(index < 4){
            // *ptr_c = '0';
            ptr_c = &ch;
        } else {
            ptr_c = &ch;
        }
    }

    if(index > 4){
       x = 2;
    //    printf("x changes (input to big) %i\n", x);
        ptr_c = &ch;
      }

    if(x == 0 && index == 4){
        // printf("X value -> %i\n", x);
        //printf("Good String -> %s", c_array); //read automatically makes a newline?
        return 1;
    } 

    if((x != 0 && x != 1) || x == 2 || index != 4){
        // printf("X value -> %i\n", x);
        //printf("Wrong input -> %s", c_array); //read automatically makes a newline?
        printf("Wrong Input!\n");
      x = 0;
    }
  
  }
  return 0;
}

int game_engine(char secret_code[], int rounds_declared){
    int round_index     = 0;
    int answer_check    = 0;
    printf("Rounds Declared -> %i\n", rounds_declared);
    printf("Secret Code -> %s\n", secret_code);
    while(round_index < rounds_declared && answer_check != 1){
        printf("\n---\n");
        printf("Round %i\n", round_index);
        printf("Secret Code -> %s\n", secret_code); // for testing reference

        int n;
        char player_answer[5] = {0,0,0,0,'\0'};
        char* p_panswer = player_answer;
        if((n = read_input(p_panswer, player_answer)) != 0 || n != -1){
            //IF ANSWER INCORRECT - ADVANCE ROUND
            if(n == 0){
                return answer_check = 1;
            }

            if(strcmp(player_answer, secret_code) != 0){
                determine_diff(player_answer, secret_code);
            } else {
                printf("Congratz! You did it!\n");
                answer_check = 1;
            }
            
            round_index++;
            // printf("Game Engine String Check -> %s", player_answer);
        } else {
            answer_check = 1;
        }
    }
    return 00;
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


// ===========================
// int check_player_answer(const char* answer){
//     int counter = 0;
//     while(*answer != '\0'){
//         if(*answer > '9' || *answer < '0'){
//             return 0;
//         }
//         // printf("%c\n", *answer);
//         counter++;
//         answer++;
//     }
//     if(counter > 4 || counter < 4){
//         return 0;
//     }
//     return 1;
// }

// void determine_diff(char* answer, char* secret_code){
//     // SETUP
//     int well_placed     = 0;
//     int misplaced       = 0;
//     int index           = 0;
//     int check_answer[4] = {0,0,0,0};
//     int check_code[4]   = {0,0,0,0};

//     // PT.1
//     while(answer[index] != '\0'){
//         if(answer[index] == secret_code[index]){
//             // printf("WP Found at index -> %i\n", index);
//             well_placed++;
//             check_answer[index]     = 1;
//             check_code[index]       = 1;
//         }
//         // printf("\nWhile 1 Index Count: %i\n", index);
//         index++;
//     }

//     // RESET INDEX
//     index               = 0;

//     // PT.2
//     while(answer[index] != '\0'){
//         if(answer[index] != secret_code[index]){
//             int j       = 0;
//             while(secret_code[j] != '\0'){
//                 if(answer[index] == secret_code[j] 
//                 && j != index 
//                 && check_code[j] != 1 
//                 && check_answer[index] != 1){
//                     // printf("Misplaced found at index -> %i | j -> %i\n", index, j);
//                     misplaced++;
//                     check_answer[index] = 1;
//                     check_code[j]       = 1;
//                     j                   = 3;
//                 }
//                 j++; 
//             }
//         }
//         // printf("\nWhile 2 Index Count: %i\n", index);
//         index++;
//     }


//     printf("----------------------------\n");
//     printf("Well placed pieces: %i\n", well_placed);
//     printf("Misplaced pieces: %i\n", misplaced);
//     printf("----------------------------\n");
// }

// char read_input(char* p_input){
//     // for(int i = 0 ; i < 5;i++){
//     //     read(0, &p_input[i], 1);
//     // }
//     // p_input[4] = '\0';
//     // return *p_input;
//     int nr;
//     int index = 0;
//     char ch;
//    //read() upon successful completion returns the number of bytes read, if error returns -1, if EOF returns 0
//     // while((nr = read(0, &p_input[index], 1)) != -1 && nr != 0 && index != 4){
//     //     if(nr == -1){
//     //         printf("\nWrong input");
//     //     }
//     //     index++;
//     // } 

//     do  {
//         nr = read(0,&ch, 1);
//         p_input[index] = ch;
//         index++;
//     } while (nr != -1 && nr != 0 && index != 4);

//     // if(nr != 4){
//     //         printf("\nWrong input");
//     // }

//     // if(nr == 1){
//     //         printf("\n nr == 1\n");
//     // }

//     // THIS DOESN'T WORK SADLY
//     // else {
//     //     if(nr == -1){
//     //     printf("\nWrong input");
//     //     }
//     // }

//     // Apparently while((nr=read(fd,&ch,sizeof(ch))) > 0) isn't very portable to other systems as it doesn't handle -1 which is an error or 0 which is an EOF 
   
//     // if(nr == 4){
//     p_input[4] = '\0';
//     if(check_player_answer(p_input) == 1){
//         // return *p_input;
//         return 1;
//     } else {
//         return 00;
//     }
//     if(check_player_answer(p_input) == 0){
//         // HANDLE EOF
//     }
//     // }

// }

// void game_engine(char secret_code[], int rounds_declared){
//     int round_index     = 0;
//     int answer_check    = 0;
//     printf("Rounds Declared -> %i\n", rounds_declared);
//     printf("Secret Code -> %s\n", secret_code);
//     while(round_index < rounds_declared && answer_check != 1){
//         printf("\n=========================================\n");
//         printf("\nRound %i\n", round_index);
//         // printf("\nSecret Code -> %s\n", secret_code);

//         // TAKE USER INPUT
//         // char player_answer[5]; // declare char variable
//         // char ch;
//         // printf(">");
//         char player_answer[5];
//         read_input(player_answer);
//         // printf(">%s\n", player_answer);

//         // if player checked answer function equals: 1 == success, 0 == Try Again, -1 == Wrong Input!


        
//         if(strlen(player_answer) < 5 && strlen(player_answer) > 0){
//             // player_answer[3] = '\0';
//                     // COMPARE INPUT WITH SECRET CODE
//             if(strcmp(player_answer, secret_code) == 0){
//                 // printf(">");
//                 printf("Success!\n");
//                 printf("\n=========================================\n");
//                 answer_check = 1;
//             } else {
//                 // printf(">");
//                 determine_diff(player_answer, secret_code);
//                 printf("Try Again\n");
//                 round_index += 1;
//             }
//         } else {
//             printf("Wrong input!\n");
//         }


//         //DOESN'T PASS GANDALF
//         // scanf("%s", player_answer);

//         //      // VET PLAYER ANSWER
//         // if(check_player_answer(player_answer) == 0){
//         //     printf("Wrong input!\n");
//         // } else {
//         //     // COMPARE INPUT WITH SECRET CODE
//         //     if(strcmp(player_answer, secret_code) == 0){
//         //         printf("Success!\n");
//         //         printf("\n=========================================\n");
//         //         answer_check = 1;
//         //     } else {
//         //         determine_diff(player_answer, secret_code);
//         //         printf("Try Again\n");
//         //         round_index += 1;
//         //     }
//         // }

//     }
// }

// ===========================

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


// int read_input(char* ptr_answer_array, char ogstring[]){
//     // initialize_array(ptr_answer_array);
//     // Set temp_ptr to first index of original array - CLEAN
//     char* tmp_ptr = ptr_answer_array;
//     int i = 0;
//     tmp_ptr = initialize_ptr(tmp_ptr, ptr_answer_array, i);
//     printf("Player Input Check -> %s", ogstring);
//     int n;
//     while((n = handle_read(tmp_ptr, i)) != 0 && i < 4){
//         tmp_ptr++;
//         i++;
//         if(n == -1){
//             //Wrong Input
//             //Call initialize tmp_ptr function
//             tmp_ptr = initialize_ptr(tmp_ptr, ptr_answer_array, i);
//             i = 0;
//             printf("\nWrong Input!");
//             // printf("\nWrong Input!"); // PRINTS AT TEH CHARACTER AFTER THE WRONG INPUT - NEEDS TO BE ONCE
//         }
//         // printf("\nPlayer Answer Array -> %s\n", ptr_answer_array);
//     }
//     // player_answer[4] = '\0';
//     printf("Player Input Check -> %s", ogstring);
//     // for(int i = 0; i<5;i++){
//     //     printf("%c", *player_answer);
//     // }
 
//     // printf("\nPost Clear: Player Input Check -> %c", ch);
//     // CLEAR BUFFER!

//     // IF INCORRECT RETURN 0, IF CORRECT RETURN 1, IF WRONG INPUT RECURSIVE COMMENT, IF EOF RETURN -1
//     return 0;
// }


// int handle_read(char *tmp_ptr, int i){

//     // char ch;
//     int n;
//     if((n = read(0, tmp_ptr, 1)) != -1 && n != 0 && i < 5){
//         // write(1, tmp_ptr, 1);

//         //Handle Out of Bounds Characters
//         if(*tmp_ptr < '0' || *tmp_ptr > '9'){
//             return n = -1;
//             // printf("\nWrong Input!");
//             // *tmp_ptr = ' ';
//             //needs to say "Wrong Input and let them attempt another guess"
//         }

//         if(*tmp_ptr == 10 || *tmp_ptr == 14){ //NL or Carriage Return

//         }

//         //Handle EOF
//         if(n == 0){
//             return n;
//         }
//     };  
//     //Handle Null Terminator at end of string
//     printf("\nindex value -> %i\n", i);
//     if(i == 4){
//         *tmp_ptr = '\0';
//     }
//     return n;
// }


// char* initialize_ptr(char* tmp_ptr, char* ptr_ref, int i){
//     for( ; i<5; i++){
//         *tmp_ptr = 00;
//         tmp_ptr++;
//     }
//     i = 0;
//     *tmp_ptr = '\0';
//     //Set tmp_ptr to beginning of array
//     return tmp_ptr = ptr_ref;
// }