# makefile for the ants project

#variables
CC=g++
TFLAGS= -g #flags for gdb
EXEC=main

#test compiling
test: World.o Ant.o global.o test.cpp
	$(CC) $(TFLAGS) test.cpp World.o Ant.o global.o -o test.out


World.o: World.cpp
	$(CC) -c $(TFLAGS) World.cpp -o World.o

Ant.o: Ant.cpp
	$(CC) -c $(TFLAGS) Ant.cpp -o Ant.o

global.o: global.cpp
	$(CC)-c $(TFLAGS) global.cpp -o global.o

#final compiling
all: World.cpp Ant.cpp main.cpp
	$(CC) main.cpp World.cpp Ant.cpp global.cpp -o ants

#cleaning
clean:
	rm -rf *.o

remove:
	rm -rf *.out ants
