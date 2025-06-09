#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *arr, int baixo, int alto, long long *comparacoes) {
    int pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        (*comparacoes)++;  // Incrementa a comparação
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quick_sort(int *arr, int baixo, int alto, long long *comparacoes) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, comparacoes);

        quick_sort(arr, baixo, pi - 1, comparacoes);
        quick_sort(arr, pi + 1, alto, comparacoes);
    }
}
