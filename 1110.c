/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1110>>
Data        : 13/09/2026
Objetivo    : Descartar cartas e descobrir a carta restante
Dificuldade : Montar a lógica da lista encadeada, e manusear ponteiros
Uso de IA   : Foi utilizada para elaboração do commit no github
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

//inicializa a lista encadeada
typedef struct No {
    int carta;
    struct No *prox;
} No;

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) { //programa continua enquanto scanf conseguir ler um numero e ser diferente de 0

        No *inicio = NULL; //aponta para a primeira carta, mas lista esta vazia
        No *fim = NULL; //aponta para a primeira carta, mas lista esta vazia

        // Cria as cartas de 1 até n
        for (int i = 1; i <= n; i++) {

            No *novo = malloc(sizeof(No));//aloca memória para uma carta

            novo->carta = i;//coloca numero da carta no nó
            novo->prox = NULL;//criada no final da lista, próximo não é nada

            if (inicio == NULL) {//se for primeira carta, é o inicio e o fim
                inicio = novo;
                fim = novo;
            } else {
                fim->prox = novo;//antigo ultimo no aponta para o novo
                fim = novo;//novo nó é o ultimo
            }
        }

        printf("Discarded cards:");

        int primeiro = 1;//apenas para deixar a saida certinha

        // Enquanto houver pelo menos duas cartas
        while (inicio != fim) {

            // 1. Descarta a carta do topo
            No *temp = inicio;

            inicio = inicio->prox;

            if (primeiro) {//imprime a carta descartada, se for a primeira não colocar virgula
                printf(" %d", temp->carta);
                primeiro = 0;
            } else {
                printf(", %d", temp->carta);
            }
            //libera a memória da carta discartada
            free(temp);

        
            //Se ainda houver duas cartas,move a próxima para o final


            if (inicio != fim) {

                temp = inicio;//carta do topo

                inicio = inicio->prox;//avanca inicio para proxima carta

                temp->prox = NULL;//não aponta mais para carta pois esta no final

                fim->prox = temp;//coloca no final
                fim = temp;
            }
        }

        printf("\n");

        printf("Remaining card: %d\n", inicio->carta);

        free(inicio);
    }

    return 0;
}
