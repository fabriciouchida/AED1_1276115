#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *prox;
} No;

int main(){
    No *cabeca = (No *) malloc(sizeof(No));
    No *fim = cabeca;

    cabeca->prox = NULL;
    cabeca->info = NULL;

    for(int i = 0; i < 10; i++){
        No *c = (No *) malloc(sizeof(No));
        fim->prox = c;
        fim = c;
    }
    
}