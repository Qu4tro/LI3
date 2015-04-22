#ifndef PARSE_H
#define PARSE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "validate.h"
#include "utils.h"

#include "catalogo_produtos.h"
#include "catalogo_cliente.h"

#include "compras.h"

#define MAXBUFFERPROD 10
#define MAXBUFFERCLIE 10
#define MAXBUFFERCOMP 60

client_node parse_codigo_cliente_file(char* filename);

prod_node parse_codigo_produto_file(char* filename);

int* parse_compras_file(char* filename, client_node treeC, prod_node treeP);

#endif
