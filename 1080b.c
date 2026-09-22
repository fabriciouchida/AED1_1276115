/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Identificar maior e valor e sua posição entre 100 entradas com aloc. dinâmica
Dificuldade : Fazer a alocação dinamica, sintaxe
Uso de IA   : Não foi utilizado
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    int Maior = 0;
    int pMaior = 0;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int *vetor = (int*)malloc(n * sizeof(int));//alocação aqui

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");//se não houver espaço suficiente
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);

        if (i == 0 || vetor[i] > Maior) {
            Maior = vetor[i];
            pMaior = i;
        }
    }

    printf("Maior: %d\n", Maior);
    printf("Posicao: %d\n", pMaior + 1);

    free(vetor);//liberar memoria

    return 0;
}
