/*
Ordenação dos Programas
 -Para falar de tempo de execução.

Gancho para ideia de árvores 
 ->Busca binária (log n) x busca sequencial (n)
  ->Vetor ordenado, busca em saltos
   ->Árvore binária  
Lista encadeada
 ->Elemento, apontador para o próximo elemento.
  ->Árvore binária 


Árvore binária: Estrutura de dados em que eu possa representar e guardar de forma direta
os elementos. Outra forma de representar dados ordenados. Checo a raiz, se o elemento é menor que a raiz,
vou para a esquerda, se for maior, vou para a direita. 


Algoritmos de ordenação:
    Terça
 -Selection Sort
    https://coddy.tech/visualize/pt/sorting/selection-sort?view=bars&speed=0.5&size=20
 -Insertion Sort
    https://coddy.tech/visualize/pt/sorting/insertion-sort?view=bars&speed=0.5&size=20
    
    Quinta
 -Merge Sort
 -Quick Sort

Problema: rearanjar elementos de um vetor tal modo que ele fique crescente.
 *Bubble sort: https://coddy.tech/visualize/sorting/bubble-sort?lang=pt&view=bars&speed=0.5&size=20

Algoritmo de Seleção (n²):
    tem um vetor, percorre o vetor procurando o elemento da priméria posição, o menor elemento
    Escolho minimo e coloco na posição correta. Depois, escolho o próximo elemento e coloco na posição correta.

    void Seleção(int n, int v[]){
        int i, j, min, x;  
        for(i=0; i<n-1; i++){ 
            min = i;
            for(j=i+1; j<n; j++){
                if(v[j]<v[min]){
                    min = j;
                }
            }
            x = v[i];
            v[i] = v[min];
            v[min] = x;
        }    
    }

    Melhor caso/Pior caso/Caso médio: O(n²) (Exceto por uma constante, tempo de execução
    Pouco afetado)



Algoritmo de Inserção (n²):
    Começa com a fila desordenada, pega o primeiro elemento
    e coloca na posição correta, depois pega o próximo elemento e coloca na posição correta,
    e assim por diante.

    void Inserção(int n, int v[]){
        int i, j, x;
        for(j=1; j<n; j++){
            x = v[j];
            for(i=j-1; i>=0 && v[i]>x; i--){
                v[i+1] = v[i];
            }
            v[j+1] = x;
        }
    }

    Melhor caso: O(n) (vetor já ordenado)
    Pior caso: O(n²) (vetor ordenado de forma decrescente)
    Caso médio: O(n²) (vetor desordenado)

Selection e Insert são algoritmos greedy, que tomam decisões locais, mas não necessariamente globais.
 
->De pouco a pouco, vão construindo a solução ótima, sem voltar atrás.
   A cada passo, escolhem a melhor opção local, mas não necessariamente a melhor opção global.



*/