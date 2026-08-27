#include <stdio.h>
 
int main() {
 
    int Maior = 0;
    int pMaior = 0;
    
    for (int i = 0; i < 100; i++){
        int temp = 0;
        scanf("%d", &temp);
        if(temp > Maior){
            Maior = temp;
            pMaior = i;
        }
    }
    printf("%d\n", Maior);
    printf("%d\n", pMaior + 1);
 
    return 0;
}
