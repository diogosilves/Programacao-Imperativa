#include "101Q.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


//1
int max(){
    int x, max = 0;
    scanf("%d", &x);
    while(x != 0){
        if (x > max)
            max = x;
        scanf("%d", &x);
    }
    printf("O maior é %d",max);
    return 0;
}

//2
int media(){
    int x, max = 0, num = 0;
    scanf("%d", &x);
    while(x != 0){
        max += x;
        scanf("%d", &x);
        num++;
    }
    printf("A media é %d",max/num);
    return 0;
}

//3
int segMaior(){
    int x, m1 = 0, m2 = 0;
    scanf("%d", &x);
    while(x != 0){
        if(x > m1 && x > m2)
            m1 = x;
        else if(x < m1 && x > m2)
            m2 = m1;
            m1 = x;
        scanf("%d",&x);
    }
    printf("A 2ºmaior é %d",m2);
    return 0;
}

//4
int bitsUm(unsigned int n){
    int bits = 1;
    while(n != 1) {
        if (n % 2 != 0) {
            bits++;
            n--;
        }
        n = n/2;
    }
    printf("O nº de bits iguais a 1 é %d",bits);
    return 0;
}

//5
int trailingZ(unsigned int n){
    int contaZ = 0;
    while (n % 2 == 0){
        n = n/2;
        contaZ++;
    }
    printf("O nº de bits iguais a 1 é %d",contaZ);
    return 0;
}

//6
int qDig(unsigned int n){
    int dig = 0;
    while(n > 0){
        n /= 10;
        dig++;
    }
    printf("%d",dig);
    return 0;
}

//7
char *mystrcat(char s1[], char s2[]){
    int size, pos;
    for(size = 0; s1[size] != '\0'; size++);
    for(pos = 0; s1[pos] != '\0'; pos++) {
        s1[size] = s2[pos];
        size++;
    }
    s1[size] = '\0';
    return s1;
}

//8
char *mystrcpy(char *dest, char source[]){
    int i;
    for(i = 0; source[i] != '\0'; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}

//9
int mystrcmp(char s1[], char s2[]){
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}

//10
char *mystrstr(char s1[], char s2[]){
    int i, j=0, pos=0;
    if(s2[0] == '\0') return s1;
    for(i = 0; s1[i] != '\0'; i++){
        if (s1[i] == s2[0]) pos=i;
        if (s1[i] == s2[j]) j++;
        if (s2[j] == '\0') return s1+pos;
    }
    return NULL;
}

//11
void strrev(char s[]){
    int i = strlen(s);
    int j = 0;
    char inv[i+1];
    for (; s[i-1] != '\0' ; i--) {
        inv[j] = s[i-1];
        j++;
    }
    inv[j+1] = '\0';
    printf("%s",inv);
}

//12
void strnoV(char s[]){
    int i, j = strlen(s), n;
    char str[j];
    strcpy(str,s);
    for (i = n=0; str[i] != '\0'; i++){
        if(!(isVowel(s[i]))){
            s[n]=str[i];
            n++;
        }
    }
    s[n]='\0';
}

int isVowel(char s){
    return(s == 'a' || s == 'A' ||
       s == 'e' || s == 'E' ||
       s == 'i' || s == 'I' ||
       s == 'o' || s == 'O' ||
       s == 'u' || s == 'U' );
}

//13(Not sure)

void truncW (char t[], int n){
    int length = strlen(t);
    int i,j=0,rep = n;
    for (i = 0; t[i] != '\0'; i++) {
        if(t[i] == ' '){
            t[j] = ' ';
            j++;
            rep = n;
        }
        else{
            if(rep != 0){
                t[j] = t[i];
                j++;
                rep--;
            }
        }
    }
    t[j] = '\0';
    printf("%s",t);
}

//14
int charMaisfreq (char s[]){
    int i;
    int maisFreq = 0;
    char c;
    if(s[0] == '\0') return 0;
    for (i = 0; s[i] != '\0'; i++) {
        if(maisFreq < aparicoes(s[i], s)) {
            maisFreq = aparicoes(s[i], s);
            c = s[i];
        }
    }
    printf("%c",c);
    return 1;

}

int aparicoes(char c, char str[]){
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if(c == str[i])
            contador++;
    }
    return contador;
}

//15
int iguaisConsecutivos (char s[]){
    int i,n = 1, max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if(s[i+1] == s[i]) n++;
        else{
            if(n>max){
                max = n;
                n = 1;
            }
        }
    }
    return max;
}

//16
int difConsecutivos (char s[]){
    int i,n = 1, max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if(s[i+1] != s[i]) n++;
        else{
            if(n>max){
                max = n;
                n=1;
            }
        }
    }
    return max;
}

//17
int maiorPrefixo (char s1[], char s2[]){
    int i, conta = 0;
    for (i = 0; s1[i] == s2[i] ; i++) {
        conta++;
    }
    return conta;
}

//18
int maiorSufixo (char s1 [], char s2 []){
    int j, conta = 0;
    int i = strlen(s1)-1;
    for(i,j; s1[i]==s2[j]; i--, j--){
        conta++;
    }
    return conta;
}

//19
int sufPref (char s1[], char s2[]){
    int i,j;
    int conta = 0;
    int s = strlen(s2);
    for (i = 0; i < s; i++) {
        if(s2[0] == s1[i]) {
            for(; s1[i] == s2[j]; i++, j++){
                conta++;
            }
        }
    }
    printf("%d",conta);
    return conta;
}

//20
int contaPal(char s[]){
    int conta = 0;
    int l = strlen(s);
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ' && s[i+1] == ' ') conta++;
    }
    if (s[l] != ' ') conta++;
    printf("%d",conta);
    return 0;
}

//21
int contaVogais(char s[]){
    int conta = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if(isVowel(s[i])) conta++;
    }
    return conta;
}

//22
int contida(char a[], char b[]){
    int i, j;
    for (i = 0; a[i] != '\0'; i++)
        if (pertence(a[i], b) == 0) return 0;
    return 1;
}

int pertence(char a, char b[]){
    for (int i = 0; b[i] != '\0';i++){
        if(a == b[i]) return 1;
    }
    return 0;
}

//23
int palindorome(char s[]){
    int i;
    int l = strlen(s)-1;
    for (i = 0; s[i] != '\0'; i++) {
        if(s[i] == s[l])
            l--;
        else return 0;
    }
    return 1;
}

//24
int remRep(char x[]){
    int i,j=0;
    int length = strlen(x);
    for (i = 0; i < strlen(x) ; i++) {
        x[j++] = x[i];
        while(i < strlen(x)-1 && x[i] == x[i+1])
            i++;
    }
    x[j]= '\0';
    return j;
}

//25
int limpaEspacos(char t[]){
    int i, j;
    for (i = 0; t[i] != '\0'; i++) {
        if(t[i] == ' ' && t[i+1] == ' '){
            for (j = i; t[j] != '\0'; j++){
                t[j] = t[j+1];
            }
            i--;
        }
    }
    int n = strlen(t);
    return n;
}

//26(Review)
void insere(int v[], int N, int x){
    int i,j, r=1;
    if(x < v[N-1]){
        for (i = 0; i < N && r == 1 ; i++) {
            if(x < v[i]){
                for (j = N; j != i ; j--) {
                    v[j] = v[j-1];
                }
                v[i] = x;
                r = 0;
            }
        }
    }
    else v[N] = x;
}

//27
void merge(int a[], int na, int b[], int nb, int r[]){
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

//28
int crescente(int a[], int i, int j){
    for (; i != j+1 ; i++) {
        if(a[i] > a[i+1]) return 0;
    }
    return 1;
}

//29
int retiraNeg(int v[], int N){
    int n = N;
    for (int i = 0; i < N; i++){
        if(v[i] < 0){
            for (int j = i; j < N; j++){
                v[j] = v[j+1];
            }
            n--;
        }
    }
    return n;
}

//30
int menosFreq(int v[], int N){
    int i,j,cont, n = N;
    int min = v[0];

    //percorre o array
    for (i = 0; i < N; i++) {
        cont = 0;
        //vê o nº de elementos iguais a v[i]
        for(j = 0; j < N; j++){
            if(v[i] == v[j]) cont++;
        }

        //atualiza o valor de min caso cont seja menor que o antigo valor
        if(cont < n){
            min = v[i];
            n = cont;
        }
    }
    return min;
}

//31
/*
int maisFreq(int v[], int N){
    int i,j,cont, n = 0;
    int max = v[0];

    //percorre o array
    for (i = 0; i < N; i++) {
        cont = 0;
        //vê o nº de elementos iguais a v[i]
        for(j = 0; j < N; j++){
            if(v[i] == v[j]) cont++;
        }

        //atualiza o valor de min caso cont seja menor que o antigo valor
        if(cont > n){
            max = v[i];
            n = cont;
        }
    }
    return max;
}*/

//32
int maxCresc(int v[], int N){
    int i, j, cont, max = 0;
    //percorre o array
    for (i = 0; i < N; i++) {
        cont = 0;
        //continua desde a posição onde ficou enquanto a sequencia aumenta
        for (j = i; j < N-1 && v[j+1] >= v[j] ; j++) {
            cont++;
        }
        //caso encontre uma sequencia maior substitui o valor de max
        if(cont > max) max = cont;
    }
    return max;
}

//33
int elimRep(int v[], int N){
    int i,j,k;
    //percorre o array
    for (i = 0; i < N; i++) {
        //encontra um elemento igual nas posiçoes para a frente no array
        for (j = i+1;  j < N; j++) {
            if(v[i] == v[j]){
                //apaga o elemento repetido
                for (k = i; k < N; k++) {
                    v[k] = v[k+1];
                }
                N--;
                j--;
            }
        }
    }
    return N;
}

//34
int elimRepOrd (int v[], int n){
    int i, j;
    for (i = 0; i < n; i++) {
        if (v[i] == v[i+1]) {
            for (j = i + 1; j < n; j++) {
                v[j] = v[j + 1];
            }
            n--;
        }
    }
    return n;
}

//35(REVIEW)
int comunsOrd (int a[], int na, int b[], int nb){
    int i,j, com = 0;
    i = j = 0;
    while(i<na && j<nb){
        if(a[i]<b[j]) i++;
        else if (a[i]>b[j]) j++;
        else if (a[i] == b[j]){
            com++;
            i++;
            j++;
        }
    }
    return com;
}

//36(REVIEW)
int comuns(int a[], int na, int b[], int nb){
    int i, j, com = 0;
    for(i = 0; i < na; i++){
        for(j = 0;j < nb; j++){
            if (a[i] == b[j]){
                com++;
                break;
            }
        }
    }
    return com;
}

//37
int midInd(int v[], int n){
    int i, var = v[0], indice = 0;

    for (i = 0; i < n; i++) {
        if(v[i] < var){
            var = v[i];
            indice = i;
        }
    }
    return indice;
}

//38
void somasAc(int v[],int Ac[], int N){
    int i;
    Ac[0] = v[0];
    for (i = 1; i < N; i++)
        Ac[i] = Ac[i-1] + v[i];
}

////////////////////////////////////////////////////////////////

//39(REVIEW)
int triSup(int N, float m [N][N]){
    int i, j, r = 1;
    //percorre as linhas
    for (i = 0; i < N; i++) {
        //percorre as colunas
        for (j = 0; j < N; j++) {
            //se estiver no lado inferior da diagonal
            if(j<i)
                //se algum dos valores for != 0
                if(m[i][j] != 0) r = 0;
        }
    }
    return r;
}

//40(REVIEW)
void transposta(int N, float m [N][N]){
    int i, j;
    float vt[N][N];
    //troca a parte superior
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            vt[j][i] = m[i][j];
        }
    }
    //troca a parte inferior
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++) {
            m[j][i] = vt[i][j];
        }
    }
}

//41
void addTo(int N, int M, int a[N][M], int b[N][M]){
    int i,j;
    for (i = 0; i < N; i++){
        for (j = 0; j < M ; j++) {
            a[i][j] += b[i][j];
        }
    }
}


//42-50


//51
int length(LInt x){
    int conta = 0;
    while(x != NULL){
        conta++;
        x = x->prox;
    }
    return conta;
}

//52
void freeL(LInt x){
    while(x != NULL){
        free(x);
        x = x->prox;
    }
}

//53
void imprimeL(LInt x){
    while(x != NULL){
        printf("%d",x->valor);
        x = x->prox;
    }
}

//54 (inveter uma lista ligada)
LInt reverseL(LInt x){
    LInt aux, ant = NULL;
    while(x != NULL){
        aux = x->prox;              //guarda o proximo nodo
        x->prox = ant;              //coloca o proximo nodo a apontar para o anterior
        ant = x;                    //atualiza o anterior para o atual
        x = aux;                    //atualiza o atual para o proximo
    }
    return ant;
}

//55 (inserir um novo nodo no meio da lista ligada)
void insertOrd(LInt *x, int s){
    LInt novo, *aux;
    novo = malloc(sizeof(struct lligada));
    novo->valor = s;
    aux = x;
    while(*aux != NULL && (*aux)->valor < s){
        aux = &((*aux)->prox);
    }
    novo->prox = *aux;
    *aux = novo;
}

//56
int removeOneOrd (LInt *x, int s){
    //verificar se a lista esta vazia
    if((*x) == NULL) return 1;
    if((*x)->valor == s){
        LInt temp = *x;
        (*x) = (*x)->prox;
        free(temp);
        return 0;
    }
    LInt prev = (*x);
    while(prev->prox){
        LInt list = prev->prox;
        if(list->valor == s){
            prev->prox = list->prox;
            free(list);
            return 0;
        }
        prev = prev->prox;
    }
    return 1;
}

//57

LInt meuMerge(LInt *r, LInt a, LInt b){
    if(a == NULL && b == NULL) return NULL;

    if(b == NULL || a != NULL && a->valor < b->valor){
        (*r) = a;
        meuMerge(&((*r)->prox),a->prox,b);
    }
    else{
        (*r) = b;
        meuMerge(&((*r)->prox),a,b->prox);
    }

    return *r;
}

//58(hard)
void splitQS(LInt l, int x, LInt *mx, LInt *Mx){}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//60(ask Senhor Peixoto)
int removeAll(LInt *a, int x){
    int cont = 0;
    printf("%d\n",x);
    LInt aux3 = (*a);
    while(aux3 != NULL){
        printf("%d ",aux3->valor);
        aux3 = aux3->prox;
    }
    printf("\n");

    //  primeiro elemento da lista
    while((*a) != NULL){
        if((*a)->valor == x){
            LInt aux = *a;
            (*a) = (*a)->prox;
            free(aux);
            cont++;
        }
        else break;
    }
    if((*a) == NULL || (*a)->prox == NULL){
        return cont;
    }
    //  resto da lista
    LInt prev = (*a);
    while(prev->prox != NULL){
        LInt atual = prev->prox;
        if(atual->valor == x){
            prev->prox = atual->prox;
            free(atual);
            cont++;
        }
        else prev = prev->prox;
    }
    return cont;
}

//61
int removeDups(LInt *l){
    int cont = 0;
    for(;*l;l = &((*l)->prox)){
        LInt prevAux = (*l);
        LInt aux = ((*l)->prox);
        for(;aux; aux = prevAux->prox){
            if(aux->valor == (*l)->valor){
                prevAux->prox = aux->prox;
                cont++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return cont;
}

//62
int removeMaiorL (LInt *l){
    int max = maximo(l);

    //1ºelemento da lista
    if((*l)->valor == max){
        LInt aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
    }
    //resto da lista
    else{
        LInt prev = (*l);
        while(prev->prox != NULL){
            LInt atual = prev->prox;
            if(atual->valor == max){
                prev->prox = atual->prox;
                free(atual);
            }
            else prev = prev->prox;
        }
    }
    return max;
}

//63
void init (LInt *x){
    if((*x) == NULL) return;
    LInt aux = (*x);
    //lista tem apenas 1 elemento
    if((*x)->prox == NULL){
        (*x) = NULL;
        free(aux);
    }
    else{
        LInt prev = (*x);
        LInt atual = (*x)->prox;
        while(prev->prox != NULL){
            if(atual->prox == NULL){
                prev->prox = NULL;
                free(atual);
            }
            else{
                prev = atual;
                atual = atual->prox;
            }
        }
    }
}

//64
void appendL(LInt *l, int x){
    LInt aux = malloc(sizeof (struct lligada));
    aux->prox = NULL;
    aux->valor = x;

    if((*l) == NULL){
        (*l) = aux;
    }
    else{
        LInt atual = (*l);
        while(atual != NULL && atual != aux){
            if(atual->prox == NULL)
                atual->prox = aux;
            else{
                atual = atual->prox;
            }
        }
    }
}

//65
void concatLv1(LInt *a, LInt b){
    if ((*a) == NULL)
        (*a) = b;
    else{
        //avança na lista de A
        concatLv1(&((*a)->prox),b);
    }
}

void concatv2(LInt *a, LInt b){
    if(*a == NULL)
        (*a) = b;
    else{
        LInt aux = (*a);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = b;
    }
}

//66(review)
LInt cloneL (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
}

//68(*l version)
int maximo(LInt *l){
    int max = 0;
    LInt aux = (*l);
    while(aux != NULL){
        if(aux->valor > max){
            max = aux->valor;
        }
        aux = aux->prox;
    }
    return max;
}

//69
int lengthL(LInt *l){
    int cont = 0;
    LInt aux = *l;
    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

//70
int take(int n, LInt *l){
    int len = lengthL(l);
    LInt aux = (*l);
    if(len <= n)
        return len;
    else{
        while(n > 0){
            aux = aux->prox;
            n--;
        }
        free(aux->prox);
        aux->prox = NULL;
    }
    return lengthL(l);
}

//71
LInt Nforward(LInt l, int N){
    LInt aux = l;
    while(N > 0){
        aux = aux->prox;
        N--;
    }
    return aux;
}

//72
int listToArray (LInt l, int v[], int N){
    int i, cont = 0;
    LInt aux = l;
    for(i = 0; i < N && (aux != NULL) ; i++){
        v[i] = aux->valor;
        aux = aux->prox;
        cont++;
    }
    return cont;
}

//73(review)
LInt arrayToList (int v[], int N){
    if(N==0) return NULL;
    LInt lista = malloc(sizeof (struct lligada));
    lista->valor = *v;
    lista->prox = arrayToList(v+1,N-1);
    return lista;
}

//74
//  o stor dá free da lista na main
//  estou a perder a informação da lista
LInt somasAcL (LInt l){
    if(!l) return NULL;
    LInt aux = l;
    while(aux->prox != NULL){
        aux->prox->valor += aux->valor;
        aux = aux->prox;
    }
    return l;
}

//75
void remreps (LInt l){
    if(l !=NULL) {
        while (l->prox != NULL) {
            if (l->prox->valor == l->valor) {
                LInt tmp = l->prox;
                l->prox = tmp->prox;
                free(tmp);
            } else l = l->prox;
        }
    }
}


//76
LInt rotateL (LInt l){
    if(!l || !l->prox) return l;
    int len = length(l);
    LInt array[len];
    for(int i = 0; i < len; i++, l = l->prox) array[i] = l;
    array[0]->prox = NULL;
    array[len - 1]->prox = array[0];
    return array[1];
}

//77
LInt parte (LInt l){
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}

//78
int altura(ABin r){
    if(r == NULL) return 0;
    int niveis;
    if(altura(r->esq) > altura(r->dir))
        niveis = 1 + altura(r->esq);
    else niveis = 1 + altura(r->dir);
    return niveis;
}

//79
ABin cloneAB (ABin r){
    if(r == NULL) return NULL;
    ABin nova = malloc(sizeof (struct lligada));
    nova->valor = r->valor;
    nova->esq = cloneAB(r->esq);
    nova->dir = cloneAB(r->dir);
    return nova;
}

//80
void mirror (ABin *x){
    if((*x) != NULL) {
        ABin tmp = (*x)->dir;
        (*x)->dir = (*x)->esq;
        (*x)->esq = tmp;
        mirror(&(*x)->esq);
        mirror(&(*x)->dir);
    }
}

//81
void inorderaux(ABin tree, LInt * list){
    LInt aux;
    if(tree) {
        inorderaux(tree->dir,list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;

        inorderaux(tree->esq,list);
    }
}

void inorder (ABin tree, LInt * list) {
    *list = NULL;
    inorderaux(tree,list);
}

//82
void preorderaux(ABin a, LInt *l) {
    LInt aux;
    if(a) {
        preorderaux(a->dir,l);
        preorderaux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}

//83
void posorderaux(ABin tree, LInt * list) {
    if(tree) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = tree->valor;
        new->prox = (*list);
        (*list) = new;
        posorderaux(tree->dir,list);
        posorderaux(tree->esq,list);
    }
}

void posorder(ABin tree, LInt * list) {
    *list = NULL;
    posorderaux(tree,list);
}

//84
int depth (ABin a, int x){
    if(!a) return -1;
    if(a->valor == x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;

    else return esq > dir ? 1 + dir : 1 + esq;
}

//85
int freeAB (ABin a){
    if(!a) return 0;
    int conta = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return conta;
}

//86
int pruneAB(ABin *a, int l){
    if((*a) == NULL) return 0;
    int c = 0;
    if(l == 0){
        c = freeAB((*a));
        (*a) = NULL;
        return c;
    }
    else{
        c += pruneAB(&(*a)->esq,l-1);
        c += pruneAB(&(*a)->dir,l-1);
    }
    return c;
}

//87
int iguaisAB (ABin a, ABin b){
    if(a && !b || !a && b) return 0;
    if(a == b || !a == !b) return 1;

    return a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}

//88
LInt concatAux(LInt a, LInt b){
    if(!a) return b;
    LInt aux = a;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = b;
    return a;
}

LInt nivelL (ABin a, int n){
    if(!a || n < 1) return NULL;
    if(n == 1){
        LInt aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = NULL;
        return aux;
    }
    else return concatAux((nivelL(a->esq,n-1)), (nivelL(a->dir,n-1)));
}


//89

int nivelV (ABin a, int n, int v[]){
    if(!a || n < 1) return 0;
    if(n == 1){
        *v = a->valor;
        return 1;
    }
    else{
        int e = nivelV(a->esq,n-1,v);
        int d = nivelV(a->dir,n-1,v+e);
        return e + d;
    }
}

//90

int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if(a && N) {
        e = dumpAbin(a->esq,v,N);
        if(e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}
