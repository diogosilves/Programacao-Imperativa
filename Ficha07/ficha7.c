#include "ficha7.h"

//l é uma copia logo nao apaga nodos ao correr a lista

//------------
// 1
//------------

void libertaLista(Palavras l){
    while(l != NULL){
        Palavras aux = l;
        l = l->prox;
        free(aux->palavra);
        free(aux);
    }
}

//------------
// 2
//------------

int quantasP(Palavras l){
    int conta = 0;

    while(l != NULL){
        conta++;
        l = l->prox;
    }
    return conta;
}


//------------
// 3
//------------

void listaPal(Palavras l){
    if(l == NULL)
        printf("Lista vazia\n");
    else {
        while (l != NULL) {
            printf("%s -> %d\n", l->palavra, l->ocorr);
            l = l->prox;
        }
    }
}

//------------
// 4
//------------

char *ultima(Palavras l){
    if(l == NULL)
        return NULL;
    else {
        Palavras aux = NULL;
        while (l != NULL) {
            aux = l;
            l = l->prox;
        }
        return aux->palavra;
    }
}

//------------
// 5
//------------

Palavras acrescentaIncio(Palavras l, char *p){
    Palavras aux = malloc(sizeof(struct celula));

    aux->palavra = strdup(p);       //strdup - instead of pointing to the word
    aux->prox = l;                  //allocs memory and copies the word
    aux->ocorr = 1;

    return aux;
}

//------------
// 6
//------------

Palavras acrescentaFim(Palavras l, char *p){
    Palavras aux = malloc(sizeof (struct celula));

    aux->palavra = strdup(p);
    aux->prox = NULL;
    aux->ocorr = 1;

    if(l == NULL)
        return aux;
    //estou a perder a cabeça da lista
    while(l != NULL){
        if(l->prox == NULL){
            l->prox = aux;
        }
        l = l->prox;
    }
    return l;
}

//------------
// 7
//------------

Palavras acrescenta (Palavras l, char *p){
    //valor ja exitey
    Palavras head = l;
    if(l == NULL)
        return NULL;
    if(!ocorr(l,p)){
        while(l != NULL){
            if(l->palavra == p)
                l->ocorr = l->ocorr+1;
            l = l->prox;
        }
    }
    else acrescentaFim(l,p);
    return head;
}

int ocorr(Palavras l, char *p){
    while(l != NULL){
        if(l->palavra == p) return 0;
        l = l->prox;
    }
    return 1;
}


//------------
// 8
//------------

//Palavras = struct celula *

Palavras maisFreq(Palavras l){
    Palavras aux = l;
    if(l == NULL)
        return NULL;
    while(l != NULL){
        if(l->ocorr > aux->ocorr) {
            aux = l;
        }
        l = l->prox;
    }
    return aux;
}