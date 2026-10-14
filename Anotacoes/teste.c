#include <stdio.h>;
#include <stdlib.h>;

typedef struct No {
    int info;
    struct No* prox;
} No;

void pushFila(int x, No **fim){
    No *c = (No *) malloc (sizeof(No));
    if (c == NULL){
        return;
    }
    c->prox = NULL;
    c->info = x;
    (*fim)->prox = c;
    *fim = c;
}

void pushPilha(int x, No **cabeca){
    No *c = (No *) malloc (sizeof(No));
    if (c == NULL){
        return;
    }
    c->prox = (*cabeca)->prox;
    c->info = x;
    (*cabeca)->prox = c;
}

void pop(No **cabeca, No **fim){
    if ((*cabeca)->prox == NULL){
        return;
    }
    No *c = (*cabeca)->prox;
    (*cabeca)->prox = c->prox;
    free(c);

    if (c == *fim){
        *fim = *cabeca;
    }
}

int listaVazia(No *cabeca){
    return cabeca->prox == NULL;
}

int main(){
    No *cabeca = (No *) malloc (sizeof(No));
    if (cabeca == NULL){
        return 1;
    }
    No *fim = cabeca;
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int info;
        scanf("%d", &info);
        pushFila(info, &fim);
    }
}
