/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1095>>
Data        : 09/11/2026
Objetivo    : Imprimir uma sequência
Dificuldade : Nenhuma
Uso de IA   : Nenhuma
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1, j = 60; j >= 0; i += 3, j -= 5) {
        printf("I=%d J=%d\n", i, j);
    }

    return 0;
}
