CC=gcc
# CFLAGS=-Wall -pedantic -ansi -O2
# CFLAGS=-pedantic -ansi -O2
CFLAGS=-O2

all: main.o interface.o utils.o get_user_input.o validate.o parse.o compras.o catalogo_cliente.o catalogo_produtos.o
	$(CC) $(CFLAGS) -o main main.o interface.o utils.o get_user_input.o validate.o parse.o compras.o catalogo_cliente.o catalogo_produtos.o

clean: 
	rm *.o main
