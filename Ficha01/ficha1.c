#include <stdio.h>
#include <math.h>
//------------
// 1
//------------

void exc1() {
    for (int i = 0; i < 5; i++) {
        int x = 0;
        while(x<5){
            putchar('#');
            x++;
        }
        printf("\n");
    }
}

//1.2
void exc1v2(int n){
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            putchar('#');
        }
        printf("\n");
    }
}

//------------
// 2
//------------

void exc2(int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0){
            for (int j = 0; j < n; j++) {
                if(j % 2 == 0) putchar('#');
                else putchar('_');
            }
        }
        else{
            for (int j = 0; j < n; j++) {
                if(j % 2 == 0) putchar('_');
                else putchar('#');
            }
        }
        printf("\n");
    }
}

//------------
// 3
//------------

void exc3v1(int size){

    //  uper
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            putchar('#');
        }
        printf("\n");
    }

    //  lower
    for (int i = size-1; i != 0; i--) {
        for (int j = 0; j < i; j++) {
            putchar('#');
        }
        printf("\n");
    }
}

// exc3v2

void exc3v2(int size){
    int esc = size;
    for (int i = 0; i < size; i++) {
        esc--;
        for (int x = 0; x < esc; x++) {
            printf(" ");
        }
        for (int j = 0; j <= i*2; j++) {
            putchar('#');
        }
        printf("\n");
    }
}

//------------
// 4
//------------

void exc4(int size){
    int num = 0;
    int i,j;
    double x,y,dist;
    for(i = 0; i < (size*2)+1; i++){
        for(j = 0; j < (size*2)+1; j++) {
            x = size - i;
            y = size - j;

            if((x*x + y*y) <= size*size){
                putchar('#');
                num++;
            }
            else putchar(' ');
        }
        printf("\n");
    }
}

