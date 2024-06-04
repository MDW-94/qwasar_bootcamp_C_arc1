
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror
TARGET := my_printf

all: compile run

# my_mastermind.c:
#       touch my_mastermind.c
#       cat << EOF > my_mastermind.c

#       EOF


compile: $(TARGET).c
        $(CC) $(CFLAGS) my_printf.c -o $(TARGET)

run: $(TARGET)
        ./$(TARGET)

# ./$(TARGET) -c "9090" -t 20

# always remember: ggcc filename.c -o filename && ./filename

clean:
        rm -f *.o

