#include <stdio.h>
#include <time.h>

#define REPETICOES 1000000

int main(){

    clock_t inicio, fim;

    inicio = clock();

    for (int i = 0; i < REPETICOES; i++) {
        /*
         * Operacao que queremos medir
         */
    }

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Repeticoes: %d\n", REPETICOES);

    printf("Tempo total:\n");
    printf("  %.6f segundos\n", tempo);

    printf("Tempo medio:\n");
    printf("  %.6f microssegundos\n",
           tempo * 1000000 / REPETICOES);

    return 0;
}