MKF = Makefile
CC = gcc
CCFLAGS = -std=c99

.PHONY: all

all: main

main: main.c map.o creature.o $(MKF)
	$(CC) -lcurses $(CCFLAGS) -o main main.c map.o creature.o

map.o: map.c map.h $(MKF)
	$(CC) $(CCFLAGS) -c map.c

creature.o: creature.c creature.h $(MKF)
	$(CC) $(CCFLAGS) -c creature.c
