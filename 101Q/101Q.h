int aparicoes(char c, char str[]);
int pertence(char a, char b[]);
int temRep(char v[], int n, int v1);
int maxPrime(int a[], int n);
int isPrime(int num);
int isVowel101Q(char s);
int isVowel(char s);

typedef struct lligada {
    int valor;
    struct lligada *prox;
} * LInt;

int maximo(LInt *l);
void concatLv1(LInt *a, LInt b);
LInt arrayToList (int v[], int N);
LInt parte (LInt l);

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int altura(ABin r);
ABin cloneAB (ABin r);
void mirror (ABin *x);
void inorderaux(ABin tree, LInt * list);
void concatv2(LInt *a, LInt b);