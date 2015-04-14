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
    float preco;
    int quantidade;
    int promocao;
    int mes;

    char line[MAXBUFFERCOMP];
    FILE* fp;
    char* temp;

    fp = fopen(filename, "r");

    if (fp == NULL){
        fprintf(stderr, "Erro na leitura do ficheiro.");
        return 0;
    }

    while(fgets(line, MAXBUFFERCOMP, fp)){

        if (validate_compras(line)){

            codigo_produto = strtok(line, " ");

            temp = strtok(NULL, " ");
            preco = atof(temp);

            temp = strtok(NULL, " ");
            quantidade = atoi(temp);

            temp = strtok(NULL, " ");
            promocao = temp[0] == 'P' ? 1 : 0;

            codigo_cliente = strtok(NULL, " ");

            temp = strtok(NULL, " ");
            mes = atoi(temp);
        }

        /* printf("%d\n", strlen(codigo)); */
    }

}

int main(){
    
    /* parse_codigo_cliente_file("../testfiles/Clientes1.txt"); */
    /* parse_codigo_produto_file("../testfiles/Produtos1.txt"); */
    return 0;
}
