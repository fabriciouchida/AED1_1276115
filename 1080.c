/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Identificar maior e valor e sua posição entre 100 entradas
Dificuldade : Fazer a verificação utilizando valores temporários
Uso de IA   : Não foi utilizado
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
    int Maior = 0;
    int pMaior = 0;
    
    for (int i = 0; i < 100; i++){
        int temp = 0;
        scanf("%d", &temp);
        if(temp > Maior){
            Maior = temp;
            pMaior = i;
        }
    }
    printf("%d\n", Maior);
    printf("%d\n", pMaior + 1);
 
    return 0;
}
