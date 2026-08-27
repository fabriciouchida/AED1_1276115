#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    int Maior = 0;
    int pMaior = 0;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int *vetor = (int*)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);

        if (i == 0 || vetor[i] > Maior) {
            Maior = vetor[i];
            pMaior = i;
        }
    }

    printf("Maior: %d\n", Maior);
    printf("Posicao: %d\n", pMaior + 1);

    free(vetor);

    return 0;
}
