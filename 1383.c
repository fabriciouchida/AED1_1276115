#include <stdio.h>

int main() {

    int k;
    scanf("%d", &k);

    for (int instancia = 1; instancia <= k; instancia++) {

        int sudoku[9][9];
        int valido = 1;

        // Ler sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Checar linhas
        for (int i = 0; i < 9; i++) {

            int seen[10] = {0};

            for (int j = 0; j < 9; j++) {

                int value = sudoku[i][j];

                if (seen[value]) {
                    valido = 0;
                }

                seen[value] = 1;
            }
        }

        // Checar colunas
        for (int j = 0; j < 9; j++) {

            int seen[10] = {0};

            for (int i = 0; i < 9; i++) {

                int value = sudoku[i][j];

                if (seen[value]) {
                    valido = 0;
                }

                seen[value] = 1;
            }
        }

        // Checar bloquinhos
        for (int startRow = 0; startRow < 9; startRow += 3) {

            for (int startCol = 0; startCol < 9; startCol += 3) {

                int seen[10] = {0};

                for (int i = startRow; i < startRow + 3; i++) {

                    for (int j = startCol; j < startCol + 3; j++) {

                        int value = sudoku[i][j];

                        if (seen[value]) {
                            valido = 0;
                        }

                        seen[value] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", instancia);

        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
