# makefile for the ants project

# variables
RTDIR=$(shell pwd)
SRCDIR=ants/
TESTDIR=test/
EXEC=ants

# g++ flags for gdb and include dir
CC=g++
TFLAGS=-g
INCL=$(RTDIR)



# object files
World.o: $(SRCDIR)World.cpp
	$(CC) -c $(TFLAGS) -I $(INCL) $(SRCDIR)World.cpp -o World.o

Ant.o: $(SRCDIR)Ant.cpp
	$(CC) -c $(TFLAGS) -I $(INCL) $(SRCDIR)Ant.cpp -o Ant.o

global.o: $(SRCDIR)global.cpp
	$(CC) -c $(TFLAGS) -I $(INCL) $(SRCDIR)global.cpp -o global.o


# test compiling
test: World.o Ant.o global.o $(TESTDIR)test.cpp
	$(CC) $(TFLAGS) -I $(INCL) $(TESTDIR)test.cpp World.o Ant.o global.o \
	-o test.out

# build
all: $(SRCDIR)World.cpp $(SRCDIR)Ant.cpp $(SRCDIR)ants.cpp
	$(CC) -I $(INCL) \
	$(SRCDIR)ants.cpp $(SRCDIR)World.cpp $(SRCDIR)Ant.cpp $(SRCDIR)global.cpp \
	-o $(EXEC).out

# cleaning
clean:
	rm -rf *.o
	rm -rf *.out

remove:
	rm -rf *.out $(EXEC).out
