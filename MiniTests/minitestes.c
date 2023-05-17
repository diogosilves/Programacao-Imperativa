#include "stdio.h"
#include "string.h"
#include "minitestes.h"

// -------------
// 1ºMINITESTE
// -------------

int count(){
    int i = 0;
    int conta = 0;
    for (i = 22; i > 5 ; i -=3) {
        conta++;
    }
    printf("conta = %d\n",conta);
    printf("i = %d", i);
    return 0;
}

// -------------
// 2ºMINITESTE
// -------------

int isPrime(int num){
    int i;
    if (num == 2 || num == 3)
        return 1;

    for (i = 2; i*i <= num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int maxPrime(int a[], int N){
    int max = -1;
    for (int i = 0; i < N; i++){
        if (isPrime(a[i]) && a[i] > max)
            max = a[i];
    }
    return max;
}

////////////////////////////////////////////////////////

int maxSeq(int a[],int N){
    int i, conta, final = 0;
    for (i = 0; i < N;i++){
        conta = 1;
        for (int j = i; j < N-1 && a[j] > a[j+1]; j++) {
            conta++;
        }

        if(conta > final){
            final = conta;
        }
    }
    return final;
}

int menosFreq1(int v[], int N){
    int i,j,conta = 0, menor = N;
    for (i = 0; i < N; i++){
        for (j = i; v[i] == v[j]; j++) conta++;
        if(conta < menor){
            menor = conta;
        }
        conta = 0;
        i = j;
    }
    return menor;
}

////////////////////////////////////////////////////////

#define TAM_TURMA 40

typedef struct estudante {
    char nome[50];
    int nota;
} Estudante;

int calcula_nota(char nome[]) {
    int i;
    int nota = 0;
    for (i = 0; nome[i] != '\0'; i++) {
        if((int)nome[i] > 96){
            nota += ((int)nome[i]-96);
        }
    }
    nota = nota % 18;
    return nota;
}

void preenche_notas(Estudante turma[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        turma[i].nota = calcula_nota(turma[i].nome);
    }
}

int adicionaAluno(Turma *t, char *nome, int nr, int nota) {

    Aluno novo_aluno;
    novo_aluno.nome = malloc(sizeof(char) * (strlen(nome)));
    if (novo_aluno.nome == NULL) {
        return 1;
    }
    strcpy(novo_aluno.nome, nome);
    novo_aluno.nr = nr;
    novo_aluno.nota = nota;

    struct cel *nova_cel = malloc(sizeof(struct cel));
    if (nova_cel == NULL) {
        free(novo_aluno.nome);
        return 1;
    }
    nova_cel->aluno = novo_aluno;

    while (*t != NULL && novo_aluno.nota < (*t)->aluno.nota) {
        t = &((*t)->prox);
    }

    nova_cel->prox = (*t);
    *t = nova_cel;

    return 0;
}

//questao 65 das 101Q
void concatQ(LInt *a, LInt b){
    if((*a) == NULL)
        (*a) = b;
    else{
        LInt aux = (*a);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = b;
    }
}