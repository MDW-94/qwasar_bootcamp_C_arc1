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

    while((*dest++ = *src++) != 00);

    return temp; // after copying data to dest, we still now have the ref for first mem adddress - we return this, it is unchanged - but the string now has new data
}

char* my_mod_strcpy(char* dest, const char* src){
    char* temp = dest; // store the start of the dest str - the pointer to the first mem address

    while(*dest != 00){
        dest++;
    }

    while((*dest++ = *src++) != 00);

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

    *dest = '\0'; //PROBLEM?
}

void my_mod_strcat(char* dest, const char* src){

    while(*dest != 00){
        dest++;
    } // set pointer to end of destinatino string, ready for concatenation

    while(*src != 00){
        // *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; //PROBLEM?
}

char* my_join(string_array* array, char* sep_char){
    if(array == NULL || array->size == 0)
        return NULL;

    int req_size = 1; // Initialize with 1 for the null terminator
    for(int i = 0; i < array->size; i++){
        req_size += my_strlen(array->array[i]);
        if(i != array->size - 1) {
            req_size += my_strlen(sep_char);
        }
    }

    char* str = (char*)malloc(req_size * sizeof(char));
    if(str == NULL)
        return NULL;

    int position = 0;
    for(int i = 0; i < array->size; i++){
        my_mod_strcpy(str + position, array->array[i]);
        position += my_strlen(array->array[i]);
        if(i != array->size - 1) {
            my_mod_strcpy(str + position, sep_char);
            position += my_strlen(sep_char);
        }
    }

    return str;
}

int main(){

    // ------- SETUP DATA for STRUCT

    char* test_strings[] = {
        "Hello",
        "World",
        "!"
    };

    int size_1 = 3;

    // char* test_strings[] = {
    // };

    // int size_1 = 0;

    // ------- declare and initialize new  struct for test, inc malloc

    string_array* test_1 = (string_array*)malloc(sizeof(string_array));

    test_1->size = size_1;

    test_1->array = (char**)malloc(size_1*sizeof(char*)); // allocate memory for 3 string pointers - parent array

    // allocate memory for each child array, then copy it into the parent array

    for(int i = 0; i < size_1;i++){
        test_1->array[i] = (char*)malloc((my_strlen(test_strings[i]) + 1) * sizeof(char));
        // + 1 is including space for null terminator
        my_strcpy(test_1->array[i], test_strings[i]);
    };

    // ------ print result

    for(int i = 0 ; i < test_1->size;i++){
        printf("String %d: %s\n", i + 1, test_1->array[i]);
    } // printing the incrementator +1 && the string at test_1->array[i] - checking to see if a string has been copied into this allocated memory space - SO FAR THIS ONLY PRINTS THE FIRST CHARACTER OF EACH STTRING 


    //  ------- call my_join function and print the result

    // char* result = my_join(test_1, "blah");

    char* result = my_join(test_1, "blah");

    printf("RESULT: %s\n", result);


    // -------- free the memory

    for(int i = 0; i < test_1->size;i++){
        free(test_1->array[i]); // free the individual strings after allocation - child arrays
    }
    free(test_1->array); // free the space allocatet for the parent arrays
    free(test_1);

    

    return 0;
}


//  old my_join

// char* my_join(string_array* array, char* sep_char){
//     int req_size = 0;

//     for(int i = 0; i < array->size;i++){ // DETERMINE THE MAOUNT OF SPACE FOR EACH CHARACTER IN THE CHILD ARRAYS + SEPARATOR CHARACTER
//         int child_array_size = 0, req_sep_char_size = 0;
//         // increment req_size by amount of characters in each array + sep_char
//         child_array_size = my_strlen(array->array[i]);

//         if(i != array->size){ // if it is not the last string
//             req_sep_char_size = my_strlen(sep_char);
//         }

//         req_size += (child_array_size + req_sep_char_size); // increment the req_size by the sum of both these values
//     }

//     // ITERATE, DETERMINE LENGTH OF STRING, DETERMINE LENGTH OF SPACER, INCREMENT COUNTER

//     // Once amount of size required for resultant string is calculated:
//     char* str = (char*)malloc(req_size*sizeof(char));




//     // Create the resultant string with concatenation;

//     // resultant str is EMPTY HERE

//     for(int i = 0; i < array->size;i++){
//         my_mod_strcpy(str, array->array[i]); // COPY CONTENTS OF CHILD ARRAY INTO RESULT ARRAY

//         // resultant str has COPIED CONTENT FROM CHILD ARRAY HERE

//         if(i != array->size - 1){ // if this is not the last word: array->size needs to be minused by 1
//               my_strcat(str, sep_char); // CONCATENATE THE SPACER ARRAY TO THE END OF THE ARRAY
//         } else {
//             my_mod_strcat(str, sep_char);
//         };

//     // SOMEHOW THE STR IS BEING WIPED AND THEN THE FOR LOOP ASSIGNS THE VALUES AGAIN - CHECK HELPER FUNCTIONS - SOLVED
//     };



//     return str;
// }










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