#include <stdio.h>
#include <stdlib.h>

int main() {

    int capacidade = 1;
    int quantidade = 0;

    int ***sudokus = malloc(capacidade * sizeof(int **));

    if (sudokus == NULL) {
        return 1;
    }

    while (1) {

        // Tenta ler o primeiro número da próxima instância
        int primeiro;

        if (scanf("%d", &primeiro) != 1) {
            break;
        }

        // Aumenta o vetor de instâncias quando necessário
        if (quantidade == capacidade) {

            capacidade *= 2;

            int ***temp = realloc(
                sudokus,
                capacidade * sizeof(int **)
            );

            if (temp == NULL) {
                free(sudokus);
                return 1;
            }

            sudokus = temp;
        }

        // Aloca um novo Sudoku
        sudokus[quantidade] = malloc(9 * sizeof(int *));

        if (sudokus[quantidade] == NULL) {
            return 1;
        }

        for (int i = 0; i < 9; i++) {

            sudokus[quantidade][i] = malloc(9 * sizeof(int));

            if (sudokus[quantidade][i] == NULL) {
                return 1;
            }
        }

        // O primeiro número já foi lido
        sudokus[quantidade][0][0] = primeiro;

        // Lê o restante do Sudoku
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                // Pula o primeiro elemento, que já foi lido
                if (i == 0 && j == 0) {
                    continue;
                }

                scanf("%d", &sudokus[quantidade][i][j]);
            }
        }

        quantidade++;
    }

    // Verifica os Sudokus
    for (int instancia = 0; instancia < quantidade; instancia++) {

        int valido = 1;

        // Linhas
        for (int i = 0; i < 9; i++) {

            int seen[10] = {0};

            for (int j = 0; j < 9; j++) {

                int value = sudokus[instancia][i][j];

                if (seen[value]) {
                    valido = 0;
                }

                seen[value] = 1;
            }
        }

        // Colunas
        for (int j = 0; j < 9; j++) {

            int seen[10] = {0};

            for (int i = 0; i < 9; i++) {

                int value = sudokus[instancia][i][j];

                if (seen[value]) {
                    valido = 0;
                }

                seen[value] = 1;
            }
        }

        // Blocos 3x3
        for (int startRow = 0; startRow < 9; startRow += 3) {

            for (int startCol = 0; startCol < 9; startCol += 3) {

                int seen[10] = {0};

                for (int i = startRow; i < startRow + 3; i++) {

                    for (int j = startCol; j < startCol + 3; j++) {

                        int value = sudokus[instancia][i][j];

                        if (seen[value]) {
                            valido = 0;
                        }

                        seen[value] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", instancia + 1);

        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    // Libera memória
    for (int instancia = 0; instancia < quantidade; instancia++) {

        for (int i = 0; i < 9; i++) {
            free(sudokus[instancia][i]);
        }

        free(sudokus[instancia]);
    }

    free(sudokus);

    return 0;
}
