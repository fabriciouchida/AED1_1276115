/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Fabrício Ribeiro Uchida
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 31/08/2026
Objetivo    : Ler k sudokus e identificar se cada uma é válida
Dificuldade : 3° verificação, se havia números repetidos em cada bloco 3x3
Uso de IA   : Usada para lógica da 3° verificação
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    
    //Declaração de K
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

            int seen[10] = {0}; //Aqui, o vetor é utilizado diferentemente, cada posição representa um número de 1 a 9 (posição 0 não é utilizda), se a matriz detectou um número, troca o valor da posição correspondente para 1.

            for (int j = 0; j < 9; j++) {

                int value = sudoku[i][j];

                if (seen[value]) { //se seen correspondente ja for 1, é invalida a matriz
                    valido = 0;
                }

                seen[value] = 1;
            }
        }

        // Checar colunas, mesma lógica de linhas mas levemente adaptada para colunas
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
        for (int startRow = 0; startRow < 9; startRow += 3) { // temos um bloquinho a cada 3 número, pois são bloquinhos 3x3. Portanto, pulamos de 3 em 3

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
