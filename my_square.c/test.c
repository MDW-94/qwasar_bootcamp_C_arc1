#include <stdio.h>

int main(int argc, char** argv) {
    // argc is the count of command line arguments
    // argv is an array of strings containing the arguments
    
    // Printing the name of the program (first argument)
    printf("Program name: %s\n", argv[0]);
    
    // Printing all the command line arguments (if any)
    if (argc > 1) {
        printf("Arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("%d: %s\n", i, argv[i]);
        }
    } else {
        printf("No arguments provided.\n");
    }

    return 0;
}
