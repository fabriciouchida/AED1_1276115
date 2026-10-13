/*
Busca em vetor ordenado
Encontrar um dado numero x num vetor crescente v[0..n-1].

int BuscaSequecial (int x, int n, int v[]){ //inteiro x a ser buscado, n tamanho do vetor
    int j = 0;
    while (j < n && v[j] < x) ++j;
    return j;
    }

    Melhor caso = constante, apenas uma verificacao
    pior caso = n -> linear em relacao ao tamanho da instancia
    caso medio = n/2

int BuscaBinaria (int x, int n, int v[]){
    int e, m, d;
    e = -1; d = n;
    while (e < d-1){
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
        }
        return d;
    }

int binary_search(const int a[], int n, int target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) {
            lo = mid + 1; // search the right half 
        } else {
            hi = mid - 1; // search the left half 
        }
    }
    return -1;
}
    */