#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "validate.h"

#ifndef INPUT_H
#define INPUT_H

char get_letter();

size_t get_mes();

size_t get_opcao();

char* get_codigo_cliente();

char* get_codigo_produto();

char* get_filename();

#endif
