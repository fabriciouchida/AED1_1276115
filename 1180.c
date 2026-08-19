#include <stdio.h>
 
int main() {
    int N = 0;
    int X[1000];
    
    
    scanf("%d", &N);
  //Salva cada valor em um elemento do vetor
    for (int i = 0; i < N; i++){
        scanf("%d", &X[i]);
    }
    
    int Menor = X[0];
    int pMenor = 0;
    
    for (int i = 1; i < N; i++){
      //Se a variável Menor for maior que o elemento atual do for, substitua por tal elemento
        if(Menor > X[i]){
            Menor = X[i];
            pMenor = i;
        }
        
    }
    
    printf("Menor valor: %d\n", Menor);
    printf("Posicao: %d\n", pMenor);
 
    return 0;
}
