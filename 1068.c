/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1068>>
Data        : 13/09/2026
Objetivo    : Criar uma pilha e identificar se os parenteses se complementam
Dificuldade : Utilizar lógicas de string junto com ponteiros
Uso de IA   : Utilizada para enxutar o código, sem necessitar de uma struct. E no commit do github
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int main() {
    char expressao[MAX];

    // Lê todas as expressões até o fim da entrada
    while (fgets(expressao, MAX, stdin) != NULL) {

        int topo = -1;

        // Pilha para armazenar os parênteses '('
        char *pilha = malloc(MAX * sizeof(char));

        int correta = 1;

        // Percorre a expressão
        for (int i = 0; expressao[i] != '\0'; i++) {

            // Encontrou um parêntese aberto
            if (expressao[i] == '(') {
                topo++;
                pilha[topo] = '(';
            }

            // Encontrou um parêntese fechado
            else if (expressao[i] == ')') {

                // Não existe '(' correspondente
                if (topo == -1) {
                    correta = 0;
                    break;
                }

                // Remove o '(' da pilha
                topo--;
            }
        }

        // Se ainda existem '(' na pilha, faltam ')'
        if (topo != -1) {
            correta = 0;
        }

        if (correta) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        free(pilha);
    }

    return 0;
}
