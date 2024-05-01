CC := gcc
CFLAGS := -g -Wall -Wextra -Werror
TARGET := my_mastermind

all: compile run

# my_mastermind.c:
# 	touch my_mastermind.c
# 	cat << EOF > my_mastermind.c

# 	EOF


compile: my_mastermind.c
	$(CC) $(CFLAGS) my_mastermind.c -o $(TARGET)

run:
	./$(TARGET)

# always remember: ggcc filename.c -o filename && ./filename

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)