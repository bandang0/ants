# makefile for the ants project

#variables
CC=g++
TFLAGS= -g	#gdb flag for testing
EXEC=main

test: World.o Ant.o test.cpp
	$(CC) $(TFLAGS) test.cpp World.o Ant.o -o test.out

all: World.o Ant.o main.c
	$(CC) main.c World.o Ant.o -o ants



World.o: World.cpp
	$(CC) -c World.cpp -o World.o

Ant.o: Ant.cpp
	$(CC) -c Ant.cpp -o Ant.o

clean:
	rm -rf *.o

remove:
	rm -rf *.out ants
