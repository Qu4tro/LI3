#ifndef CLIENTES_C
#define CLIENTES_C

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "compras.h"

typedef struct cnode {
    char* codigo_cliente;
    struct cnode* left;
    struct cnode* right;
    struct compra_ll_s* compras;
    int height;
}* client_node;


client_node insere_cliente(client_node node, char* key);

client_node procura_cliente(client_node root, char* cliente);

void inOrder(client_node root);

int get_clientes_por_letra(client_node root, char letra);

#endif
