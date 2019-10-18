# Compilers
CC=gcc
CPPC=g++

# Compiler Flags
CFLAGS=-std=c11 -O2 -w
CEFLAGS=-std=c11 -O3 -funroll -Wall
CPPFLAGS=-std=c++11 -O2 -w
CPPEFLAGS=-std=c++11 -O3 -funroll -Wall

# Make everything
all: lib crdeciph momo ntime rfciph wordcount

lib:
	$(CC) $(CFLAGS) -c src/dattyp.c -o dattyp.o 

crdeciph:
	$(CC) $(CFLAGS) src/crdeciph.c -o crdeciph

momo:
	$(CC) $(CFLAGS) -lX11 src/momo.c -o momo

ntime:
	$(CPPC) $(CPPFLAGS) src/ntime.cpp -o ntime

rfciph:
	$(CC) $(CFLAGS) src/rfciph.c -o rfciph

wordcount:
	$(CPPC) $(CPPFLAGS) src/wordcount.cpp -o wordcount

all-exp: exp-flags all

exp-flags:
	CFLAGS=$(CEFLAGS)
	CPPFLAGS=$(CPPEFLAGS)

# Clean everything
clean: clean-obj clean-binaries

clean-binaries:
	-rm -f crdeciph
	-rm -f momo
	-rm -f ntime
	-rm -f rfciph
	-rm -f wordcount

clean-obj:
	-rm -f *.o

# Clean everything and make it all again
remake: clean all
