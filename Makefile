#Compilers
CC=gcc
CPPC=g++

#Compiler Flags
CFLAGS=-O2
CPPFLAGS=-O2

# Make everything
all: rfciph

rfciph:
	$(CC) $(CFLAGS) src/rfciph.c -o rfciph

# Clean everything
clean: clean-rfciph
	-rm -f *.o

clean-rfciph:
	-rm -f rfciph

# Clean everything and make it all again
remake: clean all
