#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

int ocorr(Palavras l, char *p);