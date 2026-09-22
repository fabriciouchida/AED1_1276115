/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Fabrício Ribeiro Uchida
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Ler um vetor de casas e cartas, entregar cartas nas respectivas casas e contar passos
Dificuldade : Adaptar codigo para funcionar no beecrowd, funcionava com os exemplos mas nao com todas as verificacoes da plataforma
Uso de IA   : Usado para descobrir o presentation error (era um \n faltando)
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M, passos, posAtual;
    scanf("%d", &N); //numero de casas
    scanf("%d", &M); //numero de cartas
    int casas[N];
    for(int i = 0; i < N; i++){ //vetor de casas
        scanf("%d", &casas[i]);
    }
    passos, posAtual = 0;
    int cartas[M];
    for(int i = 0; i < M; i++){ //vetor de cartas
        scanf("%d", &cartas[i]);
    }

    for (int i = 0; i < M; i++){
        int inicio = 0;
        int fim = N-1;
        int pos_destino = -1;
        while (inicio <= fim){
            int meio = (inicio+fim)/2;
            if (casas[meio] == cartas[i]){
                pos_destino = meio;
                break;
            }
            if (casas[meio] < cartas[i]){
                inicio = meio+1;
            }else{
                fim = meio-1;
            }
        }
        passos += abs(pos_destino-posAtual);
        posAtual = pos_destino;
    }
    printf("%d\n", passos);
}