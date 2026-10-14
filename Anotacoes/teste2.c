#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define s 1000
int *criarVetor(int n){
    int *v = (int *) malloc (n*sizeof(int));
    for (int i = 0; i < n; i++){
        v[i] = rand()%1000;
    }

    return v;
}

void bubbleSort(int *n, int size){
    for (int j = 0; j < size - 1; j++){
        for(int i = 0; i < size-1-j; i++){
            if (n[i] > n[i+1]){
                int aux = n[i+1];
                n[i+1] = n[i];
                n[i] = aux;
            }
        }
    }
    
}

void imprimirVetor(int *n, int size){
    int espaco = 0;
    for (int i = 0; i < size; i++){
        printf("%d, ", n[i]);
        espaco++;
        if (espaco > 4) {printf("\n"); espaco = 0;}
    }
    printf("\n");
    printf("\n");
}

int buscaBinaria (int *n, int target, int comeco, int fim){
    int meio = (comeco+fim)/2;
    if (comeco > fim){
        return -1;
    }
    if (target == n[meio]){
        return meio;
    }
    if (target > n[meio]){
        return buscaBinaria(n, target, meio + 1, fim);
    }
    if (target < n[meio]){
        return buscaBinaria(n, target, comeco, meio - 1);
    }
}
int main(){
    srand(time(NULL));
    int *n = criarVetor(s);
    imprimirVetor(n, s);
    bubbleSort(n, s);
    imprimirVetor(n, s);
    int a;
    scanf("%d", &a);
    printf("%d", buscaBinaria(n, a, 0, s));

}