#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compras.h"

typedef struct pnode {
    char* codigo_produto;
    struct pnode* left;
    struct pnode* right;
    struct compra_ll_s* compras;
    int height;
}* prod_node;

prod_node insert_produto(prod_node node, char* key);

prod_node procura_produto(prod_node root, char* element);
    
int get_produtos_por_letra(prod_node root, char letra);

#endif
