CC=gcc
# CFLAGS=-Wall -pedantic -ansi -O2
CFLAGS=-pedantic -ansi -O2

all: main.o menu.o get_user_input.o validate.o
	$(CC) $(CFLAGS) -o main main.o menu.o get_user_input.o validate.o

clean: 
	rm *.o main
