#include "parse.h"

client_node parse_codigo_cliente_file(char* filename){

    char line[MAXBUFFERCLIE];
    char* codigo;
    FILE* fp;

    client_node tree = NULL;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERCLIE, fp)){

        codigo = strtok(line, "\r\n");
        tree = insere_cliente(tree, codigo);
    }

    return tree;
}

prod_node parse_codigo_produto_file(char* filename){

    char line[MAXBUFFERPROD];
    char* codigo;
    FILE* fp;

    prod_node tree = NULL;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERPROD, fp)){

        codigo = strtok(line, "\r\n");
        tree = insert_produto(tree, codigo);
    }

    return tree;
}


int* parse_compras_file(char* filename, client_node treeC, prod_node treeP){

    char* codigo_cliente;
    char* codigo_produto;
    char* preco_s; float preco;
    char* quantidade_s; int quantidade;
    char* promocao_s; int estado_promocao;
    char* mes_s; int mes;

    /*lines = [linhas lidas, linhas validadas] */
    int* lines = malloc(sizeof(int) * 2); 

    char line[MAXBUFFERCOMP];
    char* to_check;
    FILE* fp;
    compra_node compra = NULL;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERCOMP, fp)){

        lines[0]++;

        to_check = dupstr(line);
        if (validate_compras(to_check)){

            codigo_produto = strtok(line, " ");
            preco_s        = strtok(NULL, " ");
            quantidade_s   = strtok(NULL, " ");
            promocao_s     = strtok(NULL, " ");
            codigo_cliente = strtok(NULL, " ");
            mes_s          = strtok(NULL, " ");

            preco = atof(preco_s);
            quantidade = atoi(quantidade_s);
            estado_promocao = promocao_s[0] == 'P' ? 1 : 0;
            mes = atoi(mes_s);

            compra = create_compra(codigo_cliente, codigo_produto, 
                                   preco, mes, quantidade,
                                   estado_promocao,
                                   treeC, treeP);

            if (procura_cliente(treeC, codigo_cliente) != NULL && 
                procura_produto(treeP, codigo_produto) != NULL){
                    lines[1]++; 
                    /* printf("Existe cliente: %d", procura_cliente(treeC, codigo_produto) != NULL); */
            }
        }

    }

    return lines;
}
