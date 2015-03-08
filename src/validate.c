#include <ctype.h>
#include <stdio.h>

/* void printCharBuffer(char* b){ int i; for (i = 0; b[i] != '\0'; ++i) printf("%c ", b[i]); printf("\n");} */

size_t is_empty(char *line){

    if (line[0] == '\n' || line[0] == '\0'){
        return 1;
    }
    return 0;
}

size_t validate_single_letter(char *line){

    if (is_empty(line)){
        fprintf(stderr, "Input não pode ser vazio!\n");
        return 0;
    }

    if (!isalpha(line[0])){
        fprintf(stderr, "Tem de ser introduzida uma letra!\n");
        return 0;
    }
    if (line[1] != '\n'){
        fprintf(stderr, "Input tem de ser apenas uma letra!\n");
        return 0;
    }

    return 1;
}

size_t validate_unsigned(char* line){

    int i;

    if (is_empty(line)){
        fprintf(stderr, "Input não pode ser vazio!\n");
        return 0;
    }

    for(i = 0; line[i] != '\n' && line[i] != '\0'; ++i){ 
        if (!isdigit(line[i])){
            fprintf(stderr, "Input tem de ser um número!\n");
            return 0;
        }
    }

    return 1;
}

size_t validate_range(int min, int max, int n){

    if (n < min){
        fprintf(stderr, "Input é menor que o esperado!\n");
        return 0;
    }

    if (n > max){
        fprintf(stderr, "Input é maior que o esperado!\n");
        return 0;
    }

    return 1;
}

size_t validate_codigo_cliente(char *line){

    int i;

    for(i = 0; line[i] != '\n' && line[i] != '\0'; ++i){ 

        if (i < 2){
            if (!isupper(line[i])){
                fprintf(stderr, "Primeiros dois caracteres têm de ser letras maiuscúlas!\n");
                return 0;
            }
        }
        if (i >= 2 && i < 5){
            if (!isdigit(line[i])){
                fprintf(stderr, "Últimos três caracteres têm de ser digitos!\n");
                return 0;
            }
        }

        if (i >= 5){
            fprintf(stderr, "Input demasiado longo!\n");
            return 0;
        }

    }

    if (i != 5){
        fprintf(stderr, "Input demasiado curto!\n");
        return 0;
    }

    return 1;
}


size_t validate_codigo_produto(char *line){

    int i;

    for(i = 0; line[i] != '\n' && line[i] != '\0'; ++i){ 

        if (i < 2){
            if (!isupper(line[i])){
                fprintf(stderr, "Primeiros dois caracteres têm de ser letras maiuscúlas!\n");
                return 0;
            }
        }
        if (i >= 2 && i < 6){
            if (!isdigit(line[i])){
                fprintf(stderr, "Últimos quatro caracteres têm de ser digitos!\n");
                return 0;
            }
        }

        if (i >= 6){
            fprintf(stderr, "Input demasiado longo!\n");
            return 0;
        }

    }

    if (i != 6){
        fprintf(stderr, "Input demasiado curto!\n");
        return 0;
    }

    return 1;
}

size_t validate_filename(char *line){

    return 1;

}
