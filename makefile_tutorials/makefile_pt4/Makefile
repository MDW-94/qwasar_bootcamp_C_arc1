# https://makefiletutorial.com/

# Makefile uses the filesystem timestamp as a proxy to determine if something as changed

# Timestamps will only change if the files are modified

# https://en.wikipedia.org/wiki/Heuristic_(computer_science)

# This doesn't mean that Timestamps can't be modified themselves, meaning that it is not a fool proof way of updating a compilation of files 

#  The following Makefile ultimately runs all three targets. When you run make in the terminal, it will build a program called blah in a series of steps:

# Make selects the target blah, because the first target is the default target

# blah requires blah.o, so 'make' searches for the blah.o target

# blah.o requires blah.c, so make searches for the blah.c target

# blah.c has no dependencies, so the echo command is run

# The cc -c command is then run, because all of the blah.o dependencies are finished

# The top cc command is run, because all the blah dependencies are finished

# That's it: blah is a compiled c program

blah: blah.o
	cc blah.o -o blah # runs third

blah.o: blah.c
	cc -c blah.c -o blah.o #Runs second

# Typically blah.c would already exist, but I want to limit any additional required files

blah.c:
	echo "int main() { return 0; }" > blah.c #Run first

# If you delete blah.c, all three targets will be rerun. If you edit it (and thus change the timestamp to newer than blah.o), the first two targets will run. If you run touch blah.o (and thus change the timestamp to newer than blah), then only the first target will run. IF you change nothing, none of the targets will run. Try it out!