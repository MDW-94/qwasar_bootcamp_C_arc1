#include <stdio.h>

int my_cat(char* fileName, FILE** readFile){
    int c;

    if((*readFile = fopen(fileName, "r")) == NULL){
        printf("No file was given");
        return 0;
    } else {
        c = fgetc(*readFile);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(*readFile);
        }
        fclose(*readFile);
    }

    printf("---------------------");
    printf("\nThe function has successfully read the file\n");
    // Remember to close the file with fclose()
    return 1;
}



int main(int ac, char** av){

    FILE* fileToBeRead;

    char filename[100];
    printf("Enter the filename to open \n");
    scanf("%s", filename);
    printf("%s\n", filename);
    printf("---------------------\n");

    // for(int i = 1; i < ac; i++){
    //         if(my_cat(av[i], &fileToBeRead) != 1){
    //     printf("\n %s: Error opening file.\n", __FUNCTION__);
    // } else {
    //     // post function code
    //     printf("File read successully\n");
    //     printf("---------------------\n");
    // }
    // }

    for(int i = 1; i < ac; i++){
        if(av[i] == filename){

        if(my_cat(av[i], &fileToBeRead) != 1){


        printf("\n %s: Error opening file.\n", __FUNCTION__);
            } else {
                // post function code
                printf("File read successully\n");
                printf("---------------------\n");
            }


        } else {
            printf("filename not found\n");
            break;
        }
    }
    return 0;
}


// https://users.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html

// https://www.geeksforgeeks.org/c-program-print-contents-file/


