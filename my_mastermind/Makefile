CC := gcc
CFLAGS := -g -Wall -Wextra -Werror
TARGET := my_mastermind

all: my_mastermind.c compile run

my_mastermind.c:
	touch my_mastermind.c

compile: my_mastermind.c
	$(CC) $(CFLAGS) my_mastermind.c -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)