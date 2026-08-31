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
    //Declaração de variáveis
    int Maior = 0;
    int pMaior = 0;
    
    for (int i = 0; i < 100; i++){
        int temp = 0;
        scanf("%d", &temp);
        if(temp > Maior){ //Se temp for maior, substituir Maior e pMaior (posição) 
            Maior = temp;
            pMaior = i;
        }
    }
    printf("%d\n", Maior);
    printf("%d\n", pMaior + 1); //+1 pois queremos a posição levando em conta que ela começa no 1
 
    return 0;
}
