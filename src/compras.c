#include "compras.h"

/*
typedef enum promocao {
    N = 0;
    P = 1;
} promocao;

typedef struct compra_node_s {

    client_node cliente;
    prod_node produto;
    float preco;
    int mes;
    promocao estado_promocao;
    struct compra_node_s next;

}* compra_node;


typedef struct compra_ll_s {

    compra_node root;
    size_t length;

}* compras_ll;
*/

compra_node create_compra(char* cliente, char* produto, 
                     float preco, int mes, int quantidade, 
                     int estado_promocao,
                     client_node treeC, prod_node treeP){

    compra_node compra = malloc(sizeof(struct compra_node_s));

    compra -> cliente = procura_cliente(treeC, cliente);
    compra -> produto = procura_produto(treeP, produto);
    compra -> preco = preco;
    compra -> quantidade = quantidade;
    compra -> mes = mes;
    compra -> estado_promocao = estado_promocao;
    compra -> next = NULL;

    return compra;

}

void inserir_ll(compra_node root, compra_node compra){

    if (root == NULL){
        root = compra; 
    } else if (root -> next == NULL){
        root -> next = compra;
    } else {
        inserir_ll(root -> next, compra);
    }

}

void inserir_compra(compra_node compra){

    client_node cliente = compra -> cliente;
    prod_node produto = compra -> produto;

    inserir_ll(cliente -> compras -> root, compra);
    inserir_ll(produto -> compras -> root, compra);


}







