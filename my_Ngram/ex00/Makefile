CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: my_ngram.c compile run

my_ngram.c:
	touch my_ngram.c
 
compile: my_ngram.c 
	$(CC) my_ngram.c -o my_ngram

run: 
	@read INPUT && \
	./my_ngram $$INPUT

clean:	
	rm -f *.c my_ngram

fclean: clean
	rm - f *.c *.o



# .PHONY: do

# do:
# 	@echo "Enter a sentence: "; \
# 	read INPUT; \
# 	./my_ngram "$$INPUT"

# clean:
# 	@echo "Cleaning up..."
# 	rm *.c

# If you want to get user input from within a Makefile, ensure you run the read command in one line. It turns out that each line is run in its own subshell. So if you read in user input, ensure you have semicolons and backslashes to ensure commands are run in the same subshell.

# This is important because subshells don’t share local variables.

# https://chriswiegman.com/2021/08/using-parameters-in-a-make-target/
# https://opensource.com/article/18/8/what-how-makefile
# https://www3.nd.edu/~zxu2/acms60212-40212/Makefile.pdf
# https://makefiletutorial.com/

# Explanation:

# In the do target, the read INPUT command captures user input and stores it in the INPUT variable.
# The $$INPUT syntax is used to escape the variable so it's properly interpreted by the shell.
# Then, ./my_ngram "$$INPUT" passes the input to your my_ngram program.
# Now, when you run make do, it will prompt you to enter a sentence, and then it will pass that sentence as input to your my_ngram program.


# Explanation:

# FORCE: is a dummy target with no dependencies and no recipe. This ensures that the do target will always be considered out-of-date, triggering its recipe to execute.
# When you run make do, it will always execute the do target regardless of the status of other dependencies.
# Now, when you run make do, it will prompt you to enter a sentence and then execute your my_ngram program.


# Explanation:

# .PHONY: do declares the do target as phony.
# When you run make do, Make will execute the recipe associated with the do target regardless of whether there are any dependencies or whether the target is up to date.
# Now, when you run make do, it should prompt you to enter a sentence and then execute your my_ngram program.

# LINE BY LINE:

# my_Ngram: my_ngram.c
# This line specifies a target named my_Ngram that depends on the file my_ngram.c.
# If my_ngram.c is modified or missing, Make will rebuild the target my_Ngram by executing the commands specified in the recipe.

# gcc my_ngram.c -o my_ngram
# This line is part of the recipe for the my_Ngram target.
# It compiles the source file my_ngram.c using the GCC compiler (gcc) and creates an executable named my_ngram using the -o flag.

# .PHONY: do
# This line declares the target do as a phony target.
# Phony targets are used to specify actions that don't correspond to actual files. They are typically used for tasks like cleaning, testing, or in this case, user interaction.

# do:
# This line specifies a target named do.
# The do target doesn't have any dependencies, meaning it doesn't depend on any files. Instead, it's a target that triggers a specific action when invoked.

# @echo "Enter a sentence: "; \
# This line is part of the recipe for the do target.
# It prints the prompt "Enter a sentence: " to the terminal using the echo command.
# The @ symbol suppresses the echoing of the command itself in the terminal.

# read INPUT; \
# This line reads input from the user and assigns it to the variable INPUT.
# The read command is a shell builtin that reads a line of input from the terminal and stores it in the specified variable (INPUT in this case).
# The semicolon (;) allows multiple commands to be executed on the same line.

# ./my_ngram "$$INPUT"
# This line is the continuation of the recipe for the do target.
# It executes the my_ngram executable, passing the user input stored in the INPUT variable as a command-line argument.
# The $$INPUT syntax is used to escape the variable so that it's expanded by the shell when the command is executed.

# This Makefile allows you to compile your my_ngram.c source file into an executable named my_ngram and provides a target (do) to interactively run the compiled program, prompting the user to enter a sentence.
