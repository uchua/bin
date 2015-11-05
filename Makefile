#Compilers
CC=gcc
CPPC=g++

#Compiler Flags
CFLAGS=-std=c11 -O2 -w
CEFLAGS=-std=c11 -O3 -funroll -Wall
CPPFLAGS=-std=c++11 -O2 -w
CPPEFLAGS=-std=c++11 -O3 -funroll -Wall

# Make everything
all: lib rfciph wordcount

lib:
	$(CC) $(CFLAGS) -c -o dattyp.o src/dattyp.c

rfciph:
	$(CC) $(CFLAGS) -o rfciph src/rfciph.c

wordcount:
	$(CPPC) $(CPPFLAGS) src/wordcount.cpp -o wordcount

all-exp: exp-flags all

exp-flags:
	CFLAGS=$(CEFLAGS)
	CPPFLAGS=$(CPPEFLAGS)

# Clean everything
clean: clean-obj clean-binaries

clean-binaries:
	-rm -f rfciph
	-rm -f wordcount

clean-obj:
	-rm -f *.o

# Clean everything and make it all again
remake: clean all
