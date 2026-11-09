/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1068>>
Data        : 09/11/2026
Objetivo    : Contar e separar quantos cobaias foram utilizados
Dificuldade : Nenhuma
Uso de IA   : Commit do github
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int n, amount;
    int coelhos = 0, ratos = 0, sapos = 0;
    int total = 0;
    char type;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %c", &amount, &type);

        total += amount;

        if (type == 'C') {
            coelhos += amount;
        }
        else if (type == 'R') {
            ratos += amount;
        }
        else if (type == 'S') {
            sapos += amount;
        }
    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);

    printf("Percentual de coelhos: %.2f %%\n", (coelhos * 100.0) / total);
    printf("Percentual de ratos: %.2f %%\n", (ratos * 100.0) / total);
    printf("Percentual de sapos: %.2f %%\n", (sapos * 100.0) / total);

    return 0;
}
