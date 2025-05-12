#Makefile for "main" C++ application
#Created by Jarlisson Ivis 08/05/2025

PROG = main #Executável
CC = g++ #CC
CPPFLAGS = -O0 -g -Wall -pedantic
OBJS = main.o classes.o

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

main.o: main.cpp header.h
	$(CC) $(CPPFLAGS) -c $< -o $@

classes.o: classes.cpp header.h
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG)