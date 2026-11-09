/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1200>>
Data        : 09/11/2026
Objetivo    : Imprimir e busca em árvore binária
Dificuldade : Visualizar a arvore, e manipulação de strings
Uso de IA   : Usada para sugerir o uso de strcmp() para ler os comandos corretamente
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char info;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char x) {
    No *novo = (No *) malloc(sizeof(No));

    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No *inserir(No *raiz, char x) {
    if (raiz == NULL) {
        return criarNo(x);
    }

    if (x < raiz->info) {
        raiz->esq = inserir(raiz->esq, x);
    }
    else if (x > raiz->info) {
        raiz->dir = inserir(raiz->dir, x);
    }

    return raiz;
}

void imprimir(char x, int *primeiro) {
    if (*primeiro == 0) {
        printf(" ");
    }

    printf("%c", x);
    *primeiro = 0;
}

void prefixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        imprimir(raiz->info, primeiro);

        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void infixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);

        imprimir(raiz->info, primeiro);

        infixa(raiz->dir, primeiro);
    }
}

void posfixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);

        imprimir(raiz->info, primeiro);
    }
}

int buscar(No *raiz, char x) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->info == x) {
        return 1;
    }

    if (x < raiz->info) {
        return buscar(raiz->esq, x);
    }

    return buscar(raiz->dir, x);
}

int main() {
    No *raiz = NULL;
    char comando[10];
    char x;

    while (scanf("%9s", comando) != EOF) {

        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &x);
            raiz = inserir(raiz, x);
        }

        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &x);

            if (buscar(raiz, x)) {
                printf("%c existe\n", x);
            }
            else {
                printf("%c nao existe\n", x);
            }
        }

        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
