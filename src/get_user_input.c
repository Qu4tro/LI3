#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "validate.h"

char get_letter(){

    char line[1024];
    
    while (1){
        fgets(line, sizeof(line), stdin);

        if (validate_single_letter(line))
            return toupper(line[0]);

    }
}


size_t get_unsigned(size_t min_range, size_t max_range){
    
    char line[1024];
    int i;
    
    size_t number;
    
    while (1){
        number = 0;
        fgets(line, sizeof(line), stdin);

        if (validate_unsigned(line)){

            for(i = 0; line[i] != '\n' && line[i] != '\0'; i++){
                number *= 10;
                number += line[i] - '0';
            }

            if (validate_range(min_range, max_range, number)){
                break;
            }
        }
    }
    
    return number;
}

size_t get_opcao(){
    return get_unsigned(1, 15);
}

size_t get_mes(){
    return get_unsigned(1, 12);
}

char* get_codigo_cliente(){

    char* line = malloc(sizeof(char) * 1024);
    
    while (1){
        fgets(line, sizeof(line) * 1024, stdin);

        if (validate_codigo_cliente(line))
            return line;
    }

    return line;
}

char* get_codigo_produto(){

    char* line = malloc(sizeof(char) * 1024);
    
    while (1){
        fgets(line, sizeof(line) * 1024, stdin);

        if (validate_codigo_produto(line))
            return line;
    }

    return line;
}

char* get_filename(){

    char* line = malloc(sizeof(char) * 1024);
    
    while (1){
        fgets(line, sizeof(line) * 1024, stdin);

        if (validate_filename(line))
            return line;
    }

    return line;
}
