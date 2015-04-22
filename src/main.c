#include <stddef.h>
#include <stdio.h>

#include "interface.h"
#include "get_user_input.h"

int main () {

    print_menu(); 	
    while (1){
        puts("Escolha uma opção:");
        handle_queries(get_opcao());
        puts("\n");
    }
    return 1;

}
