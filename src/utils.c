#include <stdlib.h>
#include <string.h>

#include "utils.h"

char* dupstr (const char *s){

    char *p = malloc(strlen(s) + 1); 

    if (p != NULL){
        strcpy (p,s);
    }

    return p;
}


void printCharBuffer(char* b){ int i; for (i = 0; b[i] != '\0'; ++i) printf("%d ", b[i]); printf("\n");}


int max(int a, int b) {
    return (a > b) ? a : b;
}
