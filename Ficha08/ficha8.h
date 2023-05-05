typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;

LInt newLInt (int x, LInt xs);

typedef struct {
    LInt inicio,fim;
} Queue;