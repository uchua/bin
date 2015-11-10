#Compilers
CC=gcc
CPPC=g++

#Compiler Flags
CFLAGS=-std=c11 -O2 -w
CEFLAGS=-std=c11 -O3 -funroll -Wall
CPPFLAGS=-std=c++11 -O2 -w
CPPEFLAGS=-std=c++11 -O3 -funroll -Wall

# Make everything
all: momo rfciph wordcount

momo:
	$(CC) $(CFLAGS) src/momo.c -o momo -lX11

rfciph:
	$(CC) $(CFLAGS) src/rfciph.c -o rfciph

wordcount:
	$(CPPC) $(CPPFLAGS) src/wordcount.cpp -o wordcount

all-experimental: exp-flags all

exp-flags:
	CFLAGS=$(CEFLAGS)
	CPPFLAGS=$(CPPEFLAGS)

# Clean everything
clean: clean-binaries
	-rm -f *.o

clean-binaries:
	-rm -f rfciph
	-rm -f wordcount

# Clean everything and make it all again
remake: clean all
