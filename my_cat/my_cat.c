#include <stdio.h>

int my_cat(char* fileName, FILE** readFile){

    if((*readFile = fopen(fileName, "r")) == NULL){
        return FILE_ERROR;
    } 
    
    return FILE_NO_ERROR;
}



int main(int ac, char** av){

    FILE* fileToBeRead;

    if(my_cat(av[1], &fileToBeRead) != FILE_NO_ERROR){
        printf("\n %s: Error opening file.\n", __FUNCTION__);
    }

    return 0;
}