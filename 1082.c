/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 28/11/2026
Objetivo    : Checar quais componentes são conexos.
Dificuldade : Fazer a lógica de elementos visitados
Uso de IA   : Não foi utilizado
-------------------------------------------------------------------------- */

#include <stdio.h>

#define MAX 26

int graph[MAX][MAX];
int visited[MAX];
int component[MAX];
int id;

void dfs(int v, int n)
{
    int i;

    visited[v] = 1;
    component[id++] = v;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
            dfs(i, n);
    }
}

void ordenar()
{
    int i, j, temp;

    for (i = 0; i < id - 1; i++)
    {
        for (j = i + 1; j < id; j++)
        {
            if (component[i] > component[j])
            {
                temp = component[i];
                component[i] = component[j];
                component[j] = temp;
            }
        }
    }
}

int main()
{
    int N, V, E;
    int i, j, k;
    int total;
    char a, b;

    scanf("%d", &N);

    for (k = 1; k <= N; k++)
    {
        scanf("%d %d", &V, &E);

        for (i = 0; i < V; i++)
        {
            visited[i] = 0;

            for (j = 0; j < V; j++)
                graph[i][j] = 0;
        }

        for (i = 0; i < E; i++)
        {
            scanf(" %c %c", &a, &b);

            graph[a - 'a'][b - 'a'] = 1;
            graph[b - 'a'][a - 'a'] = 1;
        }

        printf("Case #%d:\n", k);

        total = 0;

        for (i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                id = 0;

                dfs(i, V);

                ordenar();

                for (j = 0; j < id; j++)
                    printf("%c,", component[j] + 'a');

                printf("\n");

                total++;
            }
        }

        printf("%d connected components\n\n", total);
    }

    return 0;
}
