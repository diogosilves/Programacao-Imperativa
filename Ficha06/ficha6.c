#include "ficha6.h"
#include "stdlib.h"

//stack - last in first out
//queue - first in first out

//------------
//1
//------------

//a)
void SinitStack(SStack s){
    int i;
    // s é um apontador
    s->sp = 0;
}

//b)
int SisEmpty(SStack s){
    if(s->sp == 0) return 1;
}

//c)
int Spush (SStack s, int x){
    int i;
    if(s->sp == Max) return 1;

    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

//d)
// *x é o endereço do sitio onde quero colocar o valor devolvido
// retira o ultimo elemento que foi inserido na stack
int Spop (SStack s, int *x){
    if(SisEmpty(s)) return 1;
    s->sp--;
    *x = s->values[s->sp];
    return 0;
}

//e)
int Stop(SStack s, int *x){
    if(SisEmpty(s)) return 1;
    *x = s->values[s->sp-1];
    return 0;
}


//------------
//2
//------------

//a)
void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

//b)
int SisEmptyQ (SQueue q){
    return (q->length == 0);
}

//c)
int Senqueue(SQueue q, int x){
    if(q->length == Max) return 1;
    q->values[(q->front + q->length) % Max] = x;
    q->length++;
    return 0;
}

int Sdequeue(SQueue q, int *x){
    if(q->length == 0) return 1;
    *x = q->values[q->front];
    if(q->front == Max-1) q->front = 0;
    else q->front++;
    q->length--;
    return 0;
}
//------------
//3
//------------

//inicia a stack
int DinitStack(DStack s){
    s->size = Max;
    s->sp = 0;
    //alocar o array na memoria
    s->values = malloc(sizeof(int) * s->size);
    return(s->values == NULL);
}

//liberta a memoria utilizada pelo array de elementos
void DfreeStack(DStack s){
    free(s->values);
}

//verifica se a stack esta vazia
int DisEmpty(DStack s){
    return(s->sp == 0);
}

//insere um elemento na stack
int Dpush(DStack s, int x){
    if(s->sp == s->size) {
        int *aux = realloc(s->values, sizeof(int) * 2 * s->size);
        if (aux == NULL) return 1;
        s->values = aux;
        s->size *= 2;
    }
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}



