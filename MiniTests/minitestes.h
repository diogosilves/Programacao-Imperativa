typedef struct aluno {
    char *nome;
    int nr;
    int nota;
} Aluno;

typedef struct cel {
    Aluno aluno;
    struct cel *prox;
} *Turma;
