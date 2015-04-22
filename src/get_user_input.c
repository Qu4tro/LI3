#include "get_user_input.h"

char get_letter(){

    char line[1024];
    char* input;
    
    while (1){
        if (fgets(line, sizeof(line), stdin) == NULL){
            fprintf(stderr, "fgets returns NULL\n");
            exit(1);
        }

        input = strtok(line, "\r\n");

        if (validate_single_letter(input))
            return toupper(line[0]);

    }
}


size_t get_unsigned(size_t min_range, size_t max_range){
    
    char line[1024];
    char* input;
    int i;
    
    size_t number;
    
    while (1){
        number = 0;
        if (fgets(line, sizeof(line), stdin) == NULL){
            fprintf(stderr, "fgets returns NULL\n");
            exit(1);
        }

        input = strtok(line, "\r\n");

        if (validate_unsigned(input)){

            for(i = 0; input[i] != '\0'; i++){
                number *= 10;
                number += input[i] - '0';
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
    char* input;
    
    while (1){
        if (fgets(line, sizeof(char) * 1024, stdin) == NULL){
            fprintf(stderr, "fgets returns NULL\n");
            exit(1);
        }

        input = strtok(line, "\r\n");

        if (validate_codigo_cliente(input))
            return input;
    }

    return input;
}

char* get_codigo_produto(){

    char* line = malloc(sizeof(char) * 1024);
    char* input;
    
    while (1){
        if (fgets(line, sizeof(char) * 1024, stdin) == NULL){
            fprintf(stderr, "fgets returns NULL\n");
            exit(1);
        }

        input = strtok(line, "\r\n");

        if (validate_codigo_produto(input))
            return input;
    }

    return input;
}

char* get_filename(){

    char* line = malloc(sizeof(char) * 1024);
    char* input;
    
    while (1){
        if (fgets(line, sizeof(char) * 1024, stdin) == NULL){
            fprintf(stderr, "fgets returns NULL\n");
            exit(1);
        }

        input = strtok(line, "\r\n");

        return input;
    }

    return input;
}
