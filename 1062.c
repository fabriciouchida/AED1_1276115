#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {

        while (1) {
            int desejado[1000];
            int pilha[1000];

            scanf("%d", &desejado[0]);

            // Um zero encerra os testes deste bloco
            if (desejado[0] == 0) {
                printf("\n");
                break;
            }

            // Lê a ordem desejada dos vagões
            for (int i = 1; i < n; i++) {
                scanf("%d", &desejado[i]);
            }

            int topo = -1;
            int proximo = 1;
            int possivel = 1;

            for (int i = 0; i < n; i++) {

                // Coloca vagões na pilha até encontrar
                // o vagão que deve sair
                while (proximo <= n &&
                       (topo == -1 ||
                        pilha[topo] != desejado[i])) {

                    pilha[++topo] = proximo;
                    proximo++;
                }

                // Se o topo corresponde ao vagão desejado,
                // podemos retirá-lo
                if (topo >= 0 &&
                    pilha[topo] == desejado[i]) {

                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
