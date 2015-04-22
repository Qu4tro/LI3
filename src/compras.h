#ifndef COMPRAS_H
#define COMPRAS_H

#include "catalogo_produtos.h"
#include "catalogo_cliente.h"

typedef struct cnode* client_node;
typedef struct pnode* prod_node;

typedef struct compra_node_s {

    struct cnode* cliente;
    struct pnode* produto;
    float preco;
    int quantidade;
    int estado_promocao;
    int mes;
    struct compra_node_s* next;

}* compra_node;


typedef struct compra_ll_s {

    compra_node root;
    size_t length;

}* compras_ll;


compra_node create_compra(char* cliente, char* produto, 
                          float preco, int quantidade, int mes, 
                          int estado_promocao,
                          client_node treeC, prod_node treeP);


void inserir_compra(compra_node compra);


#endif
