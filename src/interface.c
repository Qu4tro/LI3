#include "interface.h"

client_node treeC;
prod_node treeP;

void handle_query1(){

    char* produtos;
    char* clientes;
    char* compras;
    int* linhas;

    puts("Ficheiro dos produtos: ");
    produtos = get_filename();
    treeP = parse_codigo_produto_file(produtos);

    puts("Ficheiro dos clientes: ");
    clientes = get_filename();
    treeC = parse_codigo_cliente_file(clientes);

    puts("Ficheiro das compras: ");
    compras = get_filename();
    linhas = parse_compras_file(compras, treeC, treeP);

    puts("\n");

    printf("Ficheiro de produtos lido: %s\n", produtos);
    printf("Ficheiro de clientes lido: %s\n", clientes);
    printf("Ficheiro de compras lido: %s\n", compras);
    printf("Linhas lidas: %d\n", linhas[0]);
    printf("Linhas validadas: %d\n", linhas[1]);

}

void handle_query2(){
    char letter;
    int matches;

    puts("Inserir letra: ");
    letter = get_letter();

    matches = get_produtos_por_letra(treeP, letter);
    printf("%d\n", matches);
}

void handle_query3(){

    size_t mes;
    char* produto;

    puts("Inserir mês: ");
    mes = get_mes();

    puts("Inserir código de produto: ");
    produto = get_codigo_produto();
}

void handle_query4(){

}

void handle_query5(){

    char* cliente;
    char* filename;

    puts("Inserir código de cliente: ");
    cliente = get_codigo_cliente();

    puts("Quer guardar num ficheiro (y/n)");
   /* TODO */ 
    puts("Inserir nome do ficheiro: ");
    filename = get_filename();
}

void handle_query6(){
    char letter;
    int matches;

    puts("Inserir letra: ");
    letter = get_letter();

    matches = get_produtos_por_letra(treeP, letter);
    printf("%d\n", matches);
}

void handle_query7(){

    size_t mes1;
    size_t mes2;

    puts("Inserir mês inicial: ");
    mes1 = get_mes();
    puts("Inserir mês final: ");
    mes2 = get_mes();

}

void handle_query8(){

    char* produto;

    puts("Inserir código de produto: ");
    produto = get_codigo_produto();

}

void handle_query9(){
    
    char* cliente;
    size_t mes;

    puts("Inserir código de cliente: ");
    cliente = get_codigo_cliente();
    puts("Inserir mês: ");
    mes = get_mes();

}

void handle_query10(){

}

void handle_query11(){
    char* filename;

    puts("Inserir nome do ficheiro: ");
    filename = get_filename();
    

}

void handle_query12(){
    puts("Inserir quantos produtos são para ser mostrados.");
/* TODO */

}

void handle_query13(){
    char* cliente;

    puts("Inserir código de cliente: ");
    cliente = get_codigo_cliente();
}

void handle_query14(){

}

void handle_query15(){
    exit(0);
}

void handle_queries(int n){

    switch (n) {
        case 1:
            handle_query1();
            break;
        case 2:
            handle_query2();
            break;
        case 3:
            handle_query3();
            break;
        case 4:
            handle_query4();
            break;
        case 5:
            handle_query5();
            break;
        case 6:
            handle_query6();
            break;
        case 7:
            handle_query7();
            break;
        case 8:
            handle_query8();
            break;
        case 9:
            handle_query9();
            break;
        case 10:
            handle_query10();
            break;
        case 11:
            handle_query11();
            break;
        case 12:
            handle_query12();
            break;
        case 13:
            handle_query13();
            break;
        case 14:
            handle_query14();
            break;
        case 15:
            handle_query15();
            break;
        default:
            fprintf(stderr, "Query not found!\n");
            break;
    }
}

void print_menu(){

    puts("1. Ler os 3 ficheiros (Produtos, Clientes e Compras).\n"); 

    puts("2. Determinar a lista e o total de produtos cujo código se inicia por uma dada letra (maiúscula); Apresentar tal lista ao utilizador e permitir que o mesmo navegue na mesma, sendo tal lista apresentada por ordem alfabética;\n");

    puts("3. Dado um mês e um código de produto válidos, determinar e apresentar o número total de vendas em modo N e em modo P, e o total facturado com esse produto em tal mês\n");

    puts("4. Determinar a lista de códigos de produtos (e o seu número total), que ninguém comprou;\n");

    puts("5. Dado um código de cliente, criar uma tabela com o número total de produtos comprados, mês a mês (para meses em que não comprou a entrada deverá ficar a 0). A tabela deverá ser apresentada em ecrã. O utilizador deverá ter a opção de guardar tal tabela num ficheiro de texto\n");

    puts("6. Determinar a lista de todos os códigos de clientes iniciados pela letra dada como parâmetro (maiúscula ou minúscula deverá ser indiferente);\n");

    puts("7. Dado um intervalo fechado de meses, por exemplo [2..6], determinar o total de compras registadas nesse intervalo e o total facturado;\n");

    puts("8. Dado um código de produto, determinar os códigos (e número total) dos clientes que o compraram, distinguido entre compra N e compra P;\n");

    puts("9. Dado um código de cliente e um mês, determinar a lista de códigos de produtos que mais comprou, por ordem descendente;\n");

    puts("10. Determinar a lista de códigos de clientes que realizaram compras em todos os meses do ano;\n");

    puts("11. Criar um ficheiro em formato CSV (compatível com Excel), contendo para cada mês em que há compras registadas, o número de compras realizadas e o número total de clientes que realizaram tais compras;\n");

    puts("12. Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o número total de clientes e o número de unidades vendidas;\n");

    puts("13. Dado um código de cliente determinar quais os 3 produtos que mais comprou durante o ano;\n");

    puts("14. Determinar o número de clientes registados que não realizaram compras bem como o número de produtos que ninguém comprou.\n");

    puts("15. Sair.\n");

}


