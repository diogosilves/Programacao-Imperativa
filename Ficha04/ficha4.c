#include "ficha4.h"
#include "stdio.h"
#include "string.h"
//------------
// 1
//------------
int isVowel(char s){
    return(s == 'a' || s == 'A' ||
           s == 'e' || s == 'E' ||
           s == 'i' || s == 'I' ||
           s == 'o' || s == 'O' ||
           s == 'u' || s == 'U' );
}

int contaVowels(char *s){
    int conta = 0;
    for (int i = 0; s[i] != '\0'; i++) {   //for(; *s != '\0'; s++)
        if(isVowel(s[i]) == 1)             //   if(isVowel(*s)) r++;
            conta++;
    }
    return conta;
}

//------------
// 2
//------------

//sem array auxiliar
int retiraVogaisRep(char *s){
    int i,j, vogais = 0;
    int length = strlen(s);
    for (i = 0; s[i] != '\0' ;i++) {
        if(isVowel(s[i]) && s[i+1] == s[i]) {
            for (j = i + 1; j < length; j++) {
                s[j] = s[j + 1];
            }
            vogais++;
        }
    }
    return vogais;
}

//com array auxiliar

//Versao do alcino
int retiraVogaisRepV2(char *s){
    int i, c = 0, j= 0;
    char max[strlen(s)+1];
    for(i = 0; s[i] != '\0'; i++) {
        if(!isVowel(s[i]) && s[i] == s[i+1]){
            max[j] = s[i];
            j++;
        }
        else j++; //i++;
    }
    max[j] = '\0';
    for (i = 0; max[i] != '\0'; i++) {
        s[i] = max[i];
    }
    s[j] = '\0';
    return c;
}
// ------------
// 3
// ------------

int duplicaVogais (char *s){
    int i,j;
    int length = strlen(s);
    for (i = 0; i < length; i++) {
        if(isVowel(s[i])){
            //incrementa um char na string
            for (j = length; j != i ; j--){
                s[j+1] = s[j];
            }
            s[i+1] = s[i];
            i++;
            length++;
        }
    }
}

//------------------
// Arrays ordenados
//------------------

//------------
// 1
//------------
int ordenado(int v[], int N){
    int i;
    for (i = 0; i < N-1; i++)
        if(v[i] > v[i+1]) return 0;
    return 1;
}

//------------
// 2
//------------
void myMerge(int a[], int na, int b[], int nb, int r[]){
    int i=0,j=0,k;

    for(k = 0; i < na && j < nb;) {
        if(a[i] > b[j]){
            r[k] = b[j];
            j++;
        }
        else{
            r[k] = a[i];
            i++;
        }
        k++;
    }

    for (; i < na; i++){
        r[k] = a[i];
        k++;
    }

    for (; j < nb; j++) {
        r[k] = b[j];
        k++;
    }
}

//------------
// 3
//------------

//com array auxiliar
//TODO
int partition(int v[], int N, int x){;
    int array[N+1];
    int capUsed = 0;
    int i;

    //menores que x
    for (i = 0; i < N; i++) {
        if(v[i] <= x){
            array[i] = v[i];
            capUsed++;
        }
    }

    //maiores que x
    for (i = 0; i < N; i++){
        if(v[i] > x){
            array[capUsed+1] = v[i];
        }
    }

    //copia array para v
    for (int j = 0; j < N; j++){
        v[j] = array[j];
    }

    return capUsed-1;
}

//sem array
