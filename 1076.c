
/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Fabrício Ribeiro Uchida
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1076
Objetivo    : Percorrer um grafo utilizando busca em profundidade (DFS)
Dificuldade : Perceber que tínhamos que contar a ida e volta e não só a ida
Uso de IA   : Não foi utilizado
-------------------------------------------------------------------------- */

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int movimentos;

void dfs(int v, int n)
{
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            movimentos += 2;
            dfs(i, n);
        }
    }
}

int main()
{
    int T, inicio, V, A;
    int i, j, x, y;

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);

        for (i = 0; i < V; i++)
        {
            visited[i] = 0;

            for (j = 0; j < V; j++)
                graph[i][j] = 0;
        }

        for (i = 0; i < A; i++)
        {
            scanf("%d %d", &x, &y);

            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        movimentos = 0;

        dfs(inicio, V);

        printf("%d\n", movimentos);
    }

    return 0;
}
