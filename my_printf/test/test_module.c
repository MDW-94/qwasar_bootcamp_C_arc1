#include "unity.h"
#include "my_printf.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void setUp(void){
    // Set up before each test, if needed
}

void tearDown(void){
    // Clean up after each test, if needed
}

// Function to capture output from a function that prints to stdout
char* capture_output(void (*func)()) {
    char temp_filename[] = "/tmp/temp_output.XXXXXX";
    FILE *temp_file = fopen(temp_filename, "w+");
    if (!temp_file) return NULL;

    FILE *original_stdout = stdout;
    stdout = temp_file;

    func();

    fflush(temp_file);
    fseek(temp_file, 0, SEEK_SET);

    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fclose(temp_file);
        return NULL;
    }

    size_t size = fread(buffer, 1, BUFFER_SIZE - 1, temp_file);
    buffer[size] = '\0';

    fclose(temp_file);
    stdout = original_stdout;

    remove(temp_filename); // Clean up temporary file
    return buffer;
}

// Define test function here
void my_test_function(void) {
    my_printf("Hello World!\n");
}

// Example test function
void test_Function_Should_DoSomething(void) {
    const char* expected_output = "Hello World!\n";

    char *output = capture_output(my_test_function);
    TEST_ASSERT_NOT_NULL(output);
    TEST_ASSERT_EQUAL_STRING(expected_output, output);

    free(output);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_Function_Should_DoSomething);
    return UNITY_END();
}



// To test a function like my_printf that outputs to the terminal, you can capture the output and compare it to the expected output within your test. This typically involves redirecting the standard output to a buffer that you can then inspect.

// Here's how you can modify your test setup to capture and compare the output of my_printf:

// Steps to Capture and Test Output
// Create a function to capture the output:

// Redirect stdout to a buffer.
// Call my_printf.
// Restore stdout.
// Compare the buffer contents with the expected output.
// Modify your test file:

// Include necessary headers for capturing output.
// Implement the capture and comparison logic in your test case.