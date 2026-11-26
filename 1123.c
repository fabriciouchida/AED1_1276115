/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1123>>
Data        : 11/10/2026
Objetivo    : Aplicar Djikiastra para resolver um problema de trânsito
Dificuldade : Além da aplicação do Djikiastra, ele não poder sair da cidade da rota de servico
Uso de IA   : Usada para INT_MAX, biblioteca limits. Usada para continue. Usada para lógica do break e continue
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <limits.h>

#define MAX 250
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int prefix[MAX];

void dijkstra(int n, int start, int C)
{
    int i, j, u, min;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n; i++)
    {
        u = -1;
        min = INF;

        // Find the unvisited vertex with minimum distance
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Cannot leave a city belonging to the service route
        if (u < C)
            continue;

        // Explore adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (graph[u][j] != -1 && !visited[j])
            {
                if (dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }
}

int main(void)
{
    int N, M, C, K;
    int U, V, P;
    int i, j;
    int ans;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) == 4)
    {
        if (N == 0 && M == 0 && C == 0 && K == 0)
            break;

        // Initialize graph
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                graph[i][j] = -1;
        }

        // Read roads
        for (i = 0; i < M; i++)
        {
            scanf("%d %d %d", &U, &V, &P);

            graph[U][V] = P;
            graph[V][U] = P;
        }

        // Calculate cumulative service route costs
        prefix[0] = 0;

        for (i = 1; i < C; i++)
        {
            prefix[i] = prefix[i - 1] + graph[i - 1][i];
        }

        // Shortest paths without leaving the service route
        dijkstra(N, K, C);

        // Find minimum total cost
        ans = INF;

        for (i = 0; i < C; i++)
        {
            if (dist[i] != INF)
            {
                int total = dist[i] + prefix[C - 1] - prefix[i];

                if (total < ans)
                    ans = total;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
