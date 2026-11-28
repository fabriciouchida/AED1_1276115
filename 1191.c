/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1191
Data        : 28/11/2026
Objetivo    : reconstruir arvore binaria usando preorder e inorder
Dificuldade : Entender os conceitos de preorder e inorder e aplicalos
Uso de IA   : Explicar conceitos e implementação de preorder e inorder
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

char pre[27], in[27];
int pos;

void postorder(int inicio, int fim)
{
    int i, raiz;

    if (inicio > fim)
        return;

    raiz = pre[pos++];

    for (i = inicio; i <= fim; i++)
    {
        if (in[i] == raiz)
            break;
    }

    postorder(inicio, i - 1);
    postorder(i + 1, fim);

    printf("%c", raiz);
}

int main()
{
    while (scanf("%s %s", pre, in) != EOF)
    {
        pos = 0;

        postorder(0, strlen(in) - 1);

        printf("\n");
    }

    return 0;
}
