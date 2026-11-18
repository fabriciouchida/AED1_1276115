
#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

typedef struct No
{
    int destino;
    struct No *prox;
} No;

No *graph[MAX];
int estado[MAX];

void inserir(int a, int b)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->destino = b;
    novo->prox = graph[a];
    graph[a] = novo;
}

int dfs(int v)
{
    estado[v] = 1;

    No *atual = graph[v];

    while (atual != NULL)
    {
        int u = atual->destino;

        if (estado[u] == 1)
            return 1;

        if (estado[u] == 0 && dfs(u))
            return 1;

        atual = atual->prox;
    }

    estado[v] = 2;
    return 0;
}

int main(void)
{
    int T, N, M, A, B;

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++)
        {
            graph[i] = NULL;
            estado[i] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &A, &B);
            inserir(A, B);
        }

        int ciclo = 0;

        for (int i = 1; i <= N; i++)
        {
            if (estado[i] == 0 && dfs(i))
            {
                ciclo = 1;
                break;
            }
        }

        printf("%s\n", ciclo ? "SIM" : "NAO");

        for (int i = 1; i <= N; i++)
        {
            No *atual = graph[i];

            while (atual != NULL)
            {
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
    }

    return 0;
}
