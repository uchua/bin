#Compilers
CC=gcc
CPPC=g++

#Compiler Flags
CFLAGS=-O2
CPPFLAGS=-O2

all: rfciph

rfciph:
	$(CC) $(CFLAGS) src/rfciph.c -o rfciph

clean: clean-rfciph
	-rm -f *.o

clean-rfciph:
	-rm -f rfciph
