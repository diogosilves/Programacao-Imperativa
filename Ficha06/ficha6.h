#define Max 10

//Stack
typedef struct{
    int sp;
    int values [Max];
} STACK, *SStack;

//Queue
typedef struct{
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;


//ArraysDinamicos
typedef struct dinStack {
    int size;       // guarda o tamanho do array values
    int sp;         // posiçoes utilizadas
    int *values;    // endereço do primeiro elemento do array
} *DStack;

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;