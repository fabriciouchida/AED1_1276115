/*
Limite de tempo: 1h30min a prova

Algoritmo Merge Sort (Ordenação)
Algoritmo Quick Sort (Ordenação) 

-> Análise de complexidade (tempo de execução) de algoritmos de ordenação

Algoritmos de hoje: Divide to conquer
    ->Quebrar o problema por partes menores
    
Merge sort:
    -Merge -> juntar. 
    Pega um vetor original, quebra no meio
    Ordeno cada uma das partes
    Pegar as duas partes ordenadas e juntar um resultado ordenado
    
    *Algoritmo recursivo!

    Dois problemas:
        -Como quebrar o vetor
        -Como ordenar o vetor quebrado
    
    Algoritmo:
        -Se o vetor tem 1 elemento, ele já está ordenado
        -Se o vetor tem mais de 1 elemento, quebrar o vetor no meio
        -Ordenar cada uma das partes
        -Juntar as duas partes ordenadas em um vetor ordenado
    
    void Intercala(int p, int q, int r, int v[]) {
        int i, j, k;
        int *w = malloc((r - p) * sizeof(int)); //vetor auxiliar
        i = p; j = q; k = 0; 
        while (i < q && j < r) {
            if (v[i] <= v[j]) 
                w[k++] = v[i++];
            else
                w[k++] = v[j++];
        }
        while (i < q) w[k++] = v[i++];
        while (j < r) w[k++] = v[j++];
        for (i = p, k = 0; i < r; i++, k++) v[i] = w[i-p];
        free(w);
    } //Linear

    // intercala funciona nesses passos:
    //1. Criar um vetor auxiliar w
    //2. Percorrer os dois vetores (o da esquerda e o da direita) e ir colocando no vetor auxiliar w o menor elemento
    //3. Colocar os elementos restantes do vetor da esquerda ou da direita no vetor auxiliar w
    //4. Copiar o vetor auxiliar w para o vetor original v

    void MergeSort(int p, int r, int v[]) {
        //p = posição inicial do vetor
        //r = posição final do vetor
        if (p < r - 1) {
            int q = (p + r) / 2;
            MergeSort(p, q, v);
            MergeSort(q, r, v);
            Intercala(p, q, r, v);
        }
    }


Algoritmo Quick Sort:



    -Escolher um elemento do vetor como pivô
    -Colocar os elementos menores que o pivô à esquerda e os maiores à direita
    -Ordenar recursivamente as duas partes

    int Separa (int p, int r, int v[]) {
        int c, j, k, t;
        c = v[r]; j = p;
        for (k = p; k < r; k++) {
            if (v[k] <= c) {
                t = v[j]; 
                v[j] = v[k]; 
                v[k] = t;
                j++;
            }
        }
        v[r] = v[j]; v[j] = c;
        return j;
    } //Linear

    void QuickSort(int p, int r, int v[]) {
        
        int j;
        if (p < r) {
            j = Separa(p, r, v);
            QuickSort(p, j - 1, v);
            QuickSort(j + 1, r, v);
        }
    }
    
*/