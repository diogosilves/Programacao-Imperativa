#include "ficha3.h"
//------------
// 1
//------------

//a)
int exc1f3(){
    int x [15] = {1, 2, 3, 4, 5,
                  6, 7, 8, 9,10,
                  11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",
                x[i], *y, *z);
        y = y+1; z = z+2;
    }
}

//b)
int exc2f3(){
    int i, j, *a, *b;
    i=3; j=5;
    *a = *b = 42;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf ("%d\n", j);
    return 0;
}

//------------
// 2
//------------

void swapM(int *x, int *y){
    int n = *y;
    *y = *x;
    *x = n;
    //printf("%d %d\n", *x, *y);
}

//------------
// 3
//------------

void swap(int v[], int i, int j){
    int n = v[i];
    v[i] = v[j];
    v[j] = n;
}

//------------
// 4
//------------

int soma(int v[], int N){
    int conta = 0;
    for (int i = 0; i != N; i++) {
        conta += v[i];
    }
    return conta;
}

//------------
// 5
//------------

void inverteArray(int v[], int N){
    for (int i = N-1, j = 0; i != j; j++,i--) {
        swap(v,i,j);
    }
}

//------------
// 6
//------------

int maximum(int v[], int N, int *m){
    if(N <= 0) return 1;
    int maior = v[0];
    for (int i = 0; i < N ; i++){
        if(v[i] > maior) maior = v[i];
    }
    *m = maior;
    return 0;
}

//------------
// 7
//------------

void quadrados(int q[], int N){
    int n = 0;
    for (int i = 0; i < N ; i++) {
        q[i] = n*n;
        n++;
    }
}
//------------
// 8
//------------

void pascal(int v[], int N){}