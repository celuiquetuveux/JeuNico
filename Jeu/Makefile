CC = gcc
CCFLAGS = -std=c99


.PHONY: all

all: main

main: main.c map.o
	$(CC) $(CCFLAGS) -o main main.c map.o

map.o: map.c map.h
	$(CC) $(CCFLAGS) -c map.c
