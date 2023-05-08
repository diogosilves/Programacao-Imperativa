#include "ficha8.h"
#include "stdlib.h"
//o elemento do topo da stack é o mais á direita na lista

LInt newLInt (int x, LInt xs){
    LInt r = malloc(sizeof(struct slist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

//------------
// STACK
// -----------
void myInitStack(Stack *s){
    (*s) = NULL;
}

int mySisEmpty(Stack s){
    return(s == NULL);
}

int push(Stack *s, int x){
    LInt new = malloc(sizeof (struct slist));
    if(new == NULL) return 1;
    new->valor = x;
    new->prox = *s;
    (*s) = new;
    return 0;
}

int pop(Stack *s, int *x){
    LInt aux = *s;
    if(*s == NULL) return 1;
    *x = (*s)->valor;
    *s = (*s)->prox;
    free(aux);
    return 0;
}

int tamanho(Stack *s){
    if((*s) == NULL) return 0;
    int conta = 0;
    LInt aux = *s;
    while(aux->prox != NULL){
        conta++;
        aux = aux->prox;
    }
    return conta;
}

// ---------
// QUEUE
// ---------

void initQueue(Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q){
    return(q.inicio == NULL);
}

int enqueue(Queue *q, int x){
    LInt new = malloc(sizeof (struct slist));
    if(new == NULL) return 1;

    new->prox = NULL;
    new->valor = x;

    if(q->inicio == NULL){
        q->inicio = new;
        q->fim = new;
    }
    else{
        q->fim->prox = new;
        q->fim = new;
    }
    return 0;
}

int dequeue(Queue *q, int *x){
    LInt aux = q->inicio;
    if(q->inicio == NULL) return 1;

    if(q->inicio == q->fim){
        q->inicio = NULL;
        q->fim = NULL;
    }
    else
        q->inicio = q->inicio->prox;
    free(aux);
    return 0;
}

//acabar