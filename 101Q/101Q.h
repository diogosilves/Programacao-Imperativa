int aparicoes(char c, char str[]);
int pertence(char a, char b[]);
int temRep(char v[], int n, int v1);
int maxPrime(int a[], int n);
int isPrime(int num);
int isVowel101Q(char s);

typedef struct lligada {
    int valor;
    struct lligada *prox;
} * Lint;