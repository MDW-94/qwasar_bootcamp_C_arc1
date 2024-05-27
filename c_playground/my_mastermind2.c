#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void generate_secret_code(int ac, char** av, const int pieces_size, char secret_code[]) {
    if (ac > 1 && strcmp(av[1], "-c") == 0 && av[2]) {
        // Declared secret code from command line
        strncpy(secret_code, av[2], 4);
        secret_code[4] = '\0';  // Ensure null-terminated
    } else {
        // Generate random secret code
        srand(time(0));  // Seed for rand()
        for (int i = 0; i < 4; i++) {
            int number = rand() % pieces_size;
            secret_code[i] = '0' + number;
        }
        secret_code[4] = '\0';
    }
}

int initialize_rounds(int ac, char** av) {
    if (ac > 3 && strcmp(av[3], "-t") == 0 && av[4]) {
        return atoi(av[4]);
    }
    return 10;
}

void determine_diff(char* answer, char* secret_code) {
    int well_placed = 0;
    int misplaced = 0;
    int check_answer[4] = {0, 0, 0, 0};
    int check_code[4] = {0, 0, 0, 0};

    // Check well-placed
    for (int i = 0; i < 4; i++) {
        if (answer[i] == secret_code[i]) {
            well_placed++;
            check_answer[i] = 1;
            check_code[i] = 1;
        }
    }

    // Check misplaced
    for (int i = 0; i < 4; i++) {
        if (check_answer[i] == 0) {
            for (int j = 0; j < 4; j++) {
                if (check_code[j] == 0 && answer[i] == secret_code[j]) {
                    misplaced++;
                    check_code[j] = 1;
                    break;
                }
            }
        }
    }

    printf("Well placed pieces: %i\n", well_placed);
    printf("Misplaced pieces: %i\n", misplaced);
}

int read_input(char* ptr_array, char c_array[]) {
    for (int i = 0; i < 4; i++) {
        c_array[i] = 0;
    }

    int result = 0;
    while (result != 1) {
        int n = 0, index = 0, x = 0;
        char ch = 0;
        char* ptr_c = ptr_array;

        while ((n = read(0, ptr_c, 1)) != 0 && n != -1 && *ptr_c != '\n') {
            if (*ptr_c == '^') {
                *ptr_c = '0';
                x = 1;
            }

            if (x == 1 && *ptr_c == 'd') {
                *ptr_c = '0';
                ptr_c = &ch;
                n = 0;
                return result = 1;
            }

            if ((*ptr_c < '0' && *ptr_c != '\n') || (*ptr_c > '9' && *ptr_c != '\n')) {
                x = 2;
            }

            index++;
            ptr_c++;

            if (index > 3 && n != 0) {
                *ptr_c = '\0';
                ptr_c = &ch;
                if (index > 4) {
                    x = 2;
                }
            }
        }

        if (n == 0) {
            x = 1;
            return 0;
        }

        if (n == -1) {
            return result = 1;
        }

        if (*ptr_c == '\n' && index < 4) {
            *ptr_c = '0';
            x = 2;
            for (; index < 4; index++) {
                c_array[index] = '0';
            }
        }

        if (x == 1 && *ptr_c == 'd') {
            *ptr_c = '0';
            ptr_c = &ch;
            n = 0;
            return result = 1;
        }

        if ((*ptr_c < '0' && *ptr_c != '\n') || (*ptr_c > '9' && *ptr_c != '\n')) {
            x = 2;
            if (index < 4) {
                ptr_c = &ch;
            } else {
                ptr_c = &ch;
            }
        }

        if (index > 4) {
            x = 2;
            ptr_c = &ch;
        }

        if (x == 0 && index == 4) {
            return 1;
        }

        if ((x != 0 && x != 1) || x == 2 || index != 4) {
            printf("Wrong Input!\n");
            x = 0;
        }
    }
    return 0;
}

int game_engine(char secret_code[], int rounds_declared) {
    int round_index = 0;
    int answer_check = 0;

    while (round_index < rounds_declared && answer_check != 1) {
        printf("---\n");
        printf("Round %i\n", round_index);

        int n;
        char player_answer[5] = {0, 0, 0, 0, '\0'};
        char* p_panswer = player_answer;
        if ((n = read_input(p_panswer, player_answer)) != 0 || n != -1) {
            if (n == 0) {
                return answer_check = 1;
            }

            if (strcmp(player_answer, secret_code) != 0) {
                determine_diff(player_answer, secret_code);
            } else {
                printf("Congratz! You did it!\n");
                answer_check = 1;
            }

            round_index++;
        } else {
            answer_check = 1;
        }
    }
    return 0;
}

int main(int ac, char** av) {
    const int pieces_size = 9;
    char secret_code[5] = {0};  // Ensure space for null terminator
    int rounds_declared = 0;

    generate_secret_code(ac, av, pieces_size, secret_code);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    rounds_declared = initialize_rounds(ac, av);
    game_engine(secret_code, rounds_declared);

    return 0;
}
