#include "ficha10.h"

//------------
// 1
//------------

//a)
ABin removeMenorV1(ABin *a){
    if(*a == NULL) return NULL;

    if((*a)->esq == NULL){
        ABin raiz = *a;
        *a = (*a)->dir;
        return raiz;
    }
    ABin aux, ant;
    aux = *a;
    ant = NULL;
    while(aux->esq != NULL){
        ant = aux;
        aux = aux->esq;
        //caso o elemento mais a esquerda tenha algo á direita temos que o ligar ao pai
        ant->esq = aux->dir;
    }
    return aux;
}

//duplo endereçamento
ABin removeMenorV2(ABin *a){
    if((*a) != NULL) return NULL;
    while((*a)->esq != NULL) a = &((*a)->esq);
    ABin aux = (*a);
    (*a) = (*a)->dir;
    return aux;
}

//b)
//copia o menor da direita para a raiz
void removeRaiz(ABin *a){
    if(*a == NULL) return;
    if((*a)->dir == NULL){
        ABin aux = (*a);
        (*a) = (*a)->esq;
        free(aux);
        return;
    }
    ABin menor = removeMenorV2(&(*a)->dir);
    (*a)->valor = menor->valor;
    free(menor);
}

//c)
int removeElem(ABin *a, int x){
    if(*a == NULL) return 1;
    ABin aux = *a;
    ABin pai = NULL;
    while(aux != NULL &&  aux->valor != x){
        pai = aux;
        if(x < aux->valor) aux = aux->esq;
        else aux = aux->dir;
    }
    if(pai == NULL) removeRaiz(a);
    else{
        if(x < pai->valor) removeRaiz(&(pai->esq));
        else removeRaiz(&(pai->dir));
    }
    return 0;
}