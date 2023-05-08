#include "ficha9.h"
#include <stdio.h>

//------------
// 1
//------------

//a)
int altura (ABin a){
    if(a == NULL) return 0;
    int e,d;
    e = 1 + altura(a->esq);
    d = 1 + altura(a->dir);
    if (e > d) return e;
    return d;
}

//b)
int nFolhas(ABin a){
    if(a == NULL) return 0;
    int folhas;
    folhas = 1 + nFolhas(a->esq) + nFolhas(a->dir);
    return folhas;
}

//c)
ABin maisEsquerda (ABin a){
    if(a == NULL) return 0;
    ABin esq = a->esq;
    while(esq->esq != NULL) {
        esq = esq->esq;
    }
    return esq;
}

//d)
void imprimeNivel(ABin a, int l){
    if(l == 0) printf("%d",a->valor);
}

//e)
int procuraE (ABin a, int x){
    int c = 0;
    if(a->valor == x) return 1;

    if((a->esq) != NULL)
        c += procuraE(a->esq, x);

    if((a->dir) != NULL)
        c += procuraE(a->dir, x);

    return c;
}

//------------
// 2
//------------

//a)
struct nodo *procura (ABin a, int x){
    if(!a) return NULL;

}

//b)
int nivel(ABin a, int x){
    int c = 0;
    if(a->valor == x) return altura(a);

    else {
        if ((a->esq) != NULL)
            c += nivel(a->esq, x);

        if ((a->dir) != NULL)
            c += nivel(a->dir, x);
    }
    return (c);
}
//c)
void imprimeAte(ABin, int x){}