#include <stdio.h>

void print_menu(){

    puts("1. Ler os 3 ficheiros (Produtos, Clientes e Compras).\n"); 

    puts("2. Determinar a lista e o total de produtos cujo código se inicia por uma dada letra (maiúscula); Apresentar tal lista ao utilizador e permitir que o mesmo navegue na mesma, sendo tal lista apresentada por ordem alfabética;\n");

    puts("3. Dado um mês e um código de produto válidos, determinar e apresentar o número total de vendas em modo N e em modo P, e o total facturado com esse produto em tal mês \n");

    puts("4. Determinar a lista de códigos de produtos (e o seu número total), que ninguém comprou; \n");

    puts("5. Dado um código de cliente, criar uma tabela com o número total de produtos comprados, mês a mês (para meses em que não comprou a entrada deverá ficar a 0). A tabela deverá ser apresentada em ecrã. O utilizador deverá ter a opção de guardar tal tabela num ficheiro de texto \n");

    puts("6. Determinar a lista de todos os códigos de clientes iniciados pela letra dada como parâmetro (maiúscula ou minúscula deverá ser indiferente); \n");

    puts("7. Dado um intervalo fechado de meses, por exemplo [2..6], determinar o total de compras registadas nesse intervalo e o total facturado; \n");

    puts("8. Dado um código de produto, determinar os códigos (e número total) dos clientes que o compraram, distinguido entre compra N e compra P; \n");

    puts("10. Determinar a lista de códigos de clientes que realizaram compras em todos os meses do ano; \n");

    puts("11. Criar um ficheiro em formato CSV (compatível com Excel), contendo para cada mês em que há compras registadas, o número de compras realizadas e o número total de clientes que realizaram tais compras, satisfazendo assim o formato final exemplo (com linha de cabeçalho): \n");

    puts("12. Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o número total de clientes e o número de unidades vendidas; \n");

    puts("13. Dado um código de cliente determinar quais os 3 produtos que mais comprou durante o ano; \n");

    puts("14. Determinar o número de clientes registados que não realizaram compras bem como o número de produtos que ninguém comprou. \n");

    puts("15. Sair.\n");

}


