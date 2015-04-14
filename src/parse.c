#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parse.h"
#include "validate.h"

#define MAXBUFFERPROD 10
#define MAXBUFFERCLIE 10
#define MAXBUFFERCOMP 60

int parse_codigo_cliente_file(char* filename){

    char line[MAXBUFFERCLIE];
    char* codigo;
    FILE* fp;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERCLIE, fp)){

        codigo = strtok(line, "\r\n");
        printf("%d\n", strlen(codigo));
    }


}

int parse_codigo_produto_file(char* filename){

    char line[MAXBUFFERPROD];
    char* codigo;
    FILE* fp;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERPROD, fp)){

        codigo = strtok(line, "\r\n");
        printf("%d\n", strlen(codigo));
    }


}

int parse_compras_file(char* filename){

    char* codigo_cliente;
    char* codigo_produto;
    char* preco_s; float preco;
    char* quantidade_s; int quantidade;
    char* promocao_s; int promocao;
    char* mes_s; int mes;

    float t = 0;

    char line[MAXBUFFERCOMP];
    char* to_check;
    FILE* fp;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERCOMP, fp)){

        to_check = strdup(line);
        if (validate_compras(to_check)){

            codigo_produto = strtok(line, " ");
            preco_s        = strtok(NULL, " ");
            quantidade_s   = strtok(NULL, " ");
            promocao_s     = strtok(NULL, " ");
            codigo_cliente = strtok(NULL, " ");
            mes_s          = strtok(NULL, " ");

            preco = atof(preco_s);
            quantidade = atoi(quantidade_s);
            promocao = promocao_s[0] == 'P' ? 1 : 0;
            mes = atoi(mes_s);

            t += preco;
        } else {
            printf("Failed validation: %s", line);
        
        }

    }
}

int main(){
    
    /* parse_codigo_cliente_file("../testfiles/Clientes1.txt"); */
    /* parse_strlen(codigo)codigo_produto_file("../testfiles/Produtos1.txt"); */
    parse_compras_file("../testfiles/Compras1.txt");
    return 0;
}
