/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 28/11/2026
Objetivo    : Inserir valores em uma árvore binária de busca e imprimir valores
Dificuldade : Implementar a queue junto da arvore
Uso de IA   : Não foi utilizado
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void percursoNivel(No *raiz) {
    No *fila[500];
    int inicio = 0, fim = 0;
    int primeiro = 1;

    fila[fim++] = raiz;

    while (inicio < fim) {
        No *atual = fila[inicio++];

        if (!primeiro)
            printf(" ");

        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL)
            fila[fim++] = atual->esq;

        if (atual->dir != NULL)
            fila[fim++] = atual->dir;
    }

    printf("\n");
}

void liberarArvore(No *raiz) {
    if (raiz == NULL)
        return;

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, valor, caso;
    No *raiz;

    scanf("%d", &C);

    for (caso = 1; caso <= C; caso++) {
        raiz = NULL;

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);
        percursoNivel(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
