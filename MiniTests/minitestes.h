#include "stdio.h"
#include "stdlib.h"

typedef struct aluno {
    char *nome;
    int nr;
    int nota;
} Aluno;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} * LInt;


typedef struct cel {
    Aluno aluno;
    struct cel *prox;
} *Turma;
