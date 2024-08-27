#include <stdio.h>

// The atoi() funcgion in C takes a string (which represents an integer) as an argument and returns its value of type int. - the function is used to convert a string argument to an integer - int atoi(const char strn) 

//  Parameters: Teh function accepts one parameter strn which refers to the string argument that is needed to be converted into its integer equivalent

// Return value: if strn is a valid input, then the function returns the equivalent integer number for the passed string number. If no valid conversion takes place, then the function returns zero

// mod operator might be useful here

int my_atoi(char* param_1){

int sum = 0;
char ch;
char sign = *param_1;
if(*param_1 == '-' || *param_1 == '+') param_1++;

while((ch = *param_1++) >= '0' && ch <= '9'){ 
    // the ascii values referenced via characters
    sum = sum * 10 - (ch - '0'); 
    //shift the position of the int alnog one to store the new value
}
if(sign != '-'){
    sum = -sum;
}
return sum;
}

int main(){

    printf("Test 1: 2 -> %i\n", my_atoi("2"));
    printf("Test 1: 2 -> %i\n", my_atoi("12345567"));

    return 0;
}