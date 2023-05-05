
//assert(1+1 = 2) -> checks if the functions returns the given value

//------------
//1
//------------

float multInt(int n, float m){
    float r = 0;
    while(n > 0){
        r += m;
        n--;
    }
    printf("%f",r);
    return r;
}

//------------
//2
//------------

float multInt2(int n, float m){
    float soma = 0;
    while(n >= 1){/*
        if (n % 2 == 1){
            soma += m;
        }
        n /= 2;
        m *= 2;
    */
    if(n & 1) soma += m;
    n >>= 1;
    m += m;
    }

    printf("%2f",soma);
    return soma;
}

//------------
//3
//------------

int mdc1(int a, int b){
    int i = (a>b) ? a : b;
    for(; i >= 1; i--){
    if(a % i == 0 && b % i == 0) return i;
    }
}

//------------
//4
//------------

int mdc2(int a, int b){}