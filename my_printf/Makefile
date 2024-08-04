UNITY_DIR = ../third_party/Unity

CC := gcc
CFLAGS := -g3 -Wall -Wextra -Werror -fsanitize=address -I$(UNITY_DIR)/src -I.
LDFLAGS := 

TARGET := my_printf
SOURCE_FILES := my_printf.c
TEST_SRC := test/test_module.c
UNITY_SRC := $(UNITY_DIR)/src/unity.c
TEST_EXEC := test_module

# Default target
all: compile run

# Compile the main target executable
compile: $(SOURCE_FILES)
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(TARGET)

# Run the main target executable
run: $(TARGET)
	./$(TARGET)

# Clean up all build files
clean:
	rm -f *.o ./$(TARGET) ./$(TEST_EXEC)

# Compile the test executable
test_compile: $(TEST_SRC) $(SOURCE_FILES) $(UNITY_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(SOURCE_FILES) $(UNITY_SRC) -o $(TEST_EXEC)

# Run the test executable
test_run: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean up test build files
test_clean:
	rm -f *.o ./$(TEST_EXEC)

# Combined target to compile and run tests
test: test_compile test_run


# Use make V=1 to troubleshoot

# Explanation
# UNITY_DIR: Specifies the path to the Unity directory.
# CC, CFLAGS, LDFLAGS: Compiler settings.
# TARGET: The main target executable (my_printf).
# MODULE_SRC: Source files for the module being tested.
# TEST_SRC: Source file for the test code.
# UNITY_SRC: Unity framework source file.
# TEST_EXEC: Name of the test executable.

# Targets
# all: Compiles and runs the main target.
# compile: Compiles the main target.
# run: Runs the main target.
# clean: Cleans up the main target and test executable.
# test_compile: Compiles the test executable using Unity.
# test_run: Runs the test executable.
# test_clean: Cleans up the test executable.
# test: Combines test_compile and test_run to compile and run the tests in one step.
