# CSCI3081 C++ Templates

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++14 $(DEBUG)

LFLAGS = -Wall $(DEBUG)
OBJS = main.o

all: $(OBJS) binary_tree.h
	$(CC) $(LFLAGS) -o tree $(OBJS)

%.o : %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o *.*~ tree
