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
    int folhas = 0;
    if(a->esq == NULL && a->dir == NULL)
        return 1;
    folhas = nFolhas(a->esq) + nFolhas(a->dir);
    return folhas;
}

//c)
ABin maisEsquerda (ABin a){
    if(a == NULL) return NULL;
    while(a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

//d)
void imprimeNivel(ABin a, int l){
    if(!a) return;
    if(l == 0) printf("%d\n",a->valor);
    else{
        if (a != NULL) printf("%d\n", a->valor);

        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

//e)
//v1
int procuraEv1 (ABin a, int x){
    if(!a) return 0;
    else {
        int c = 0;
        if (a->valor == x) return 1;
            c += procuraEv1(a->esq, x);
            c += procuraEv1(a->dir, x);
        return (c > 0);
    }
}

//v2
int procuraEv2 (ABin a, int x){
    if(!a) return 0;
    if(a->valor == x) return 1;
    return(procuraEv2(a->esq,x) || procuraEv2(a->dir,x));
}

//v3
int procuraEv3 (ABin a, int x){
    return(a != NULL && (a->valor == x || procuraEv3(a->esq,x) || procuraEv3(a->dir,x)));
}

//------------
// 2
//------------

//a)
struct nodo *procura (ABin a, int x){}

//b)
//v1
int nivelv1(ABin a, int x){
    int cont = -1;
    while(a != NULL){
        cont++;
        if(a->valor == x) return cont;
        if(x < a->valor) a = a->esq;
        else a = a->dir;
    }
    return -1;
}

//v2
int nivelv2 (ABin a, int x){
    int aux = 0;
    if(!a) return -1;
    if(a->valor == x) return 0;
    if(x > a->valor)
        aux = nivelv2(a->dir,x);
    else
        aux = nivelv2(a->esq,x);
    if(aux != -1) return 1 + aux;
    else return -1;
}

//c)
void imprimeAte(ABin a, int x){
    if(!a) return;
    imprimeAte(a->esq,x);
    if(a->valor < x){
        printf("%d\n",a->valor);
        imprimeAte(a->dir,x);
    }

}