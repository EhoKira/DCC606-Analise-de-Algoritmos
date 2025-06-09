#include <stdio.h>


void insertion_sort(int *arr, int n, long long *comparacoes) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            (*comparacoes)++;  // Incrementa a comparação
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}
