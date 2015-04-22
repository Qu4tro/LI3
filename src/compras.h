#ifndef COMPRAS_H
#define COMPRAS_H

#include "catalogo_produtos.h"
#include "catalogo_cliente.h"

typedef struct compra_node_s {

    client_node cliente;
    prod_node produto;
    float preco;
    int mes;
    int estado_promocao;
    struct compra_node_s* next;

}* compra_node;


typedef struct compra_ll_s {

    compra_node root;
    size_t length;

}* compras_ll;


compra_node create_compra(char* cliente, char* produto, 
                     float preco, int mes, 
                     int estado_promocao,
                     client_node treeC, prod_node treeP);


void inserir_compra(compra_node compra);


#endif
