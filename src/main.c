#include <stddef.h>
#include <stdio.h>

#include "menu.h"
#include "get_user_input.h"

int main () {

    print_menu(); 	
    puts("Escolha uma opção:");
    handle_queries(get_opcao());
    return 1;

}
