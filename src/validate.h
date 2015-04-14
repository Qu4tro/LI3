/* Retorna true quando a string line é composta por uma única letra */
size_t validate_single_letter(char *line);

/* Retorna true quando a string line é composta por digitos */
size_t validate_unsigned(char* line);

/* Retorna true quando n está entre min e max */
size_t validate_range(int min, int max, int n);

/* Retorna true quando a string line é um codigo de produto(2 letras seguidas por 4 digitos) */
size_t validate_codigo_cliente(char *line);

/* Retorna true quando a string line é um codigo de produto(2 letras seguidas por 4 digitos) */
size_t validate_codigo_produto(char *line);

/* Retorna true quando a string line é uma linha do ficheiro de compras válida
 * (codigo produto, preço, quantidade, promoção ou não. código cliente, mês)  */
size_t validate_compras(char *line);
