#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a function that combines an array of strings from separator characters

// Eg. ["Hello", "World", "!"] && ' ' => "Hello World !"

// You will recieve two parameters, an array of strings and a separator character
// The function should return a string where all the strings from the array are joined with the separator

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_ATRING_ARRAY
typedef struct s_string_Array {
    int size;
    char** array;
} string_array;
#endif

int my_strlen(char* str){
    int result = 0;

    while(*str != 00){
        result++;
        str++;
    }

    return result;
}

char* my_strcpy(char* dest, const char* src){
    char* temp = dest; // store the start of the dest str - the pointer to the first mem address

    while((*dest++ = *src++) != 00)

    return temp; // after copying data to dest, we still now have the ref for first mem adddress - we return this, it is unchanged - but the string now has new data
}

void my_strcat(char* dest, const char* src){

    while(*dest != 00){
        dest++;
    } // set pointer to end of destinatino string, ready for concatenation

    while(*src != 00){
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

char* my_join(string_array* array, char* sep_char){

}

int main(){

    // ------- SETUP DATA for STRUCT

    char* test_strings[] = {
        "Hello",
        "World",
        "!"
    };

    int size_1 = 3;

    // ------- declare and initialize new  struct for test, inc malloc

    string_array* test_1 = (string_array*)malloc(sizeof(string_array));

    test_1->size = size_1;

    test_1->array = (char**)malloc(size_1*sizeof(char*)); // allocate memory for 3 string pointers - parent array

    // allocate memory for each child array, then copy it into the parent array

    for(int i = 0; i , size_1;i++){
        test_1->array[i] = (char*)malloc((my_strlen(test_strings[i]) + 1) * sizeof(char));
        // + 1 is including space for null terminator
        my_strcpy(test_1->array[i], test_strings[i]);
    };

    // ------ print result

    for(int i = 0 ; i < test_1->size;i++){
        printf("String %d: %s\n", i + 1, test_1->array[i]);
    } // printing the incrementator +1 && the string at test_1->array[i] - checking to see if a string has been copied into this allocated memory space


    //  ------- call my_join function and print the result

    char* result = my_join(test_1-> " ");


    // -------- free the memory

    for(int i = 0; i < test_1->size;i++){
        free(test_1->array[i]); // free the individual strings after allocation - child arrays
    }
    free(test_1->array); // free the space allocatet for the parent arrays

    

    return 0;
}











// Do I need to allocate memory for this?

// How do you determine the size of space that malloc should allocate?

// void my_strcat(char* dest, const char* src){

//     while(*dest != '\0'){
//         dest++;
//     } // get to the end of the character array

//     while(*src != '\0'){
//         *dest = *src; //now at the end of the charcater array, set it to the first character of the src array
//         dest++; // move on by 1 from that position
//         src++; // move to the next character in the src array
//     } 

//     *dest = '\0'; // at the end, declare a null terminator
// }

// char* my_join(string_array* array, char* sep_char){

//     int char_nums = 0; // counter for characters
//     char concat_str[] =  "";
//     // concat_str[char_nums];

//     for(int i = 0; i < array->size;i++){
//         char* str = strdup(array->array[i]);

//         while(*str != '\0'){
//             char_nums++;
//             str++;
//         }

//         while(*sep_char != '\0'){
//             char_nums++;
//             // concat_str[*sep_char] TRYING TO FILL THIS EMPTY ARRAY WITH THE CHARACTERS OF THE TWO ARGUMENTS AS THEY LOOP THROUGH
//             sep_char++;
//         }

//         my_strcat(concat_str, array->array[i]);
//     // we need to determine the size of character in sep_char

//     } // determine nunmber of characters


//     // strcat() ?

//     char* result = (char*)malloc(char_nums*sizeof(char));
//      // how many characters do we make space for?
    
//     result = concat_str;

//     return result;
// }

// int main(){

//     string_array* test_1 = (string_array*)malloc(sizeof(string_array));
//     test_1->size = 4;
//     test_1->array = (char**)malloc(test_1->size*sizeof(char*));

//     test_1->array[0] = strdup("Hello");
//     test_1->array[1] = strdup("World");
//     test_1->array[2] = strdup("!");

//     char* result = my_join(test_1, "");

//     printf("Result for Test 1 -> %s\n", result);

//     free(test_1);
//     free(result);
    

//     return 0;
// }