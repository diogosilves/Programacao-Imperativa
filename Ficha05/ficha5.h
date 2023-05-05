typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

void swapA(Aluno t[], int i, int j);
void swapM1(Aluno *pA, Aluno *pB);
void swapI(int v[], int i, int j);
void ordenaIndPorNum(Aluno t[], int N,int ind[]);