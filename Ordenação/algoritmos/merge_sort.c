#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r, long long *comparacoes) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*comparacoes)++;  // Incrementa a comparação
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int *arr, int l, int r, long long *comparacoes) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m, comparacoes);
        merge_sort(arr, m + 1, r, comparacoes);

        merge(arr, l, m, r, comparacoes);  // Passando comparacoes
    }
}