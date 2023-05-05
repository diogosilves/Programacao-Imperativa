#include "ficha5.h"

//------------
// 1
//------------

int nota(Aluno a){
    int i, soma = 0;
    double notaFinal = 0;
    int menor = a.miniT[0];
    for (i = 0; i < 6; i++){
        soma += a.miniT[i];
        // menor nota mini-testes
        if(a.miniT > a.miniT[i]) menor = a.miniT[i];
    }
    soma -= menor;
    soma = (soma/5)*10;
    notaFinal = ((0.2 * soma) + (0.8 * a.teste));
    printf("Nome: %s\nNúmero: a%d\nNota final: %.1f", a.nome, a.numero, notaFinal);
    return 0;
}

//------------
// 2 (with binary search)
//------------

int procuraNum(int num, Aluno t[], int N){
    int inf = 0, sup = N-1,meio;
    while(inf <= sup){
        meio = (sup + inf)/2;
        if (t[meio].numero == num) return meio;
        if (t[meio].numero < num) inf = meio + 1;
        else sup = meio - 1;
    }
    return -1;
}

//------------
// 3
//------------

void ordenaPorNum (Aluno t[], int N){
    int i, j, m;
    for(i = 0; i < N; i++) {
        m = i;
        for (j = 0; j < N; j++) {
            if(t[j].numero < t[m].numero) m = j;
        }
        swapA(t,i,m);
    }
}
/*
void swapA(Aluno t[], int i, int j){
    Aluno aux = t[i];
    t[i] = t[j];
    t[j]= aux;
}
*/

void swapA(Aluno t[], int i, int j){
    //&das duas posiçoes a trocar
    swapM(t+i,t+j);
}

void swapM1(Aluno *pA, Aluno *pB){
    Aluno aux = *pA;
    *pA = *pB;
    *pB = aux;
}

//------------
// 4
//------------

void criaIndPorNum(Aluno t [], int N, int ind[]){
    int i,j;
    for(i = 0; i < N; i++){
        ind[i] = i;
    }
    ordenaIndPorNum(t,N,ind);
}

void ordenaIndPorNum(Aluno t[], int N,int ind[]){
    for(int i=0; i<N-1; i++)
        for(int j = i + 1; j<N; j++)
            if (t[ind[i]].numero > t[ind [j]].numero)
                swapI(ind, i,j);
}

void swapI(int v[], int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

////////////////////////////////////////////////////////////////////
void imprimeT(Aluno t[], int N, int Ind[]){
    int i;
    for (i = 0; i < N; i++)
        printf("%d, %s",t[Ind[i]].numero,t[Ind[i]].nome);
}
