#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *arr, int baixo, int alto, long long *comparacoes) {
    int pivo_idx = baixo + rand() % (alto - baixo + 1);
    trocar(&arr[pivo_idx], &arr[alto]);
    int pivo = arr[alto];

    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        (*comparacoes)++;
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quick_sort(int *arr, int baixo, int alto, long long *comparacoes) {
    int tamanho = alto - baixo + 1;
    int *stack_low  = malloc(tamanho * sizeof(int));
    int *stack_high = malloc(tamanho * sizeof(int));
    int top = -1;

    stack_low[++top]  = baixo;
    stack_high[top]   = alto;

    while (top >= 0) {
        baixo = stack_low[top];
        alto  = stack_high[top--];

        if (baixo < alto) {
            int pi = particionar(arr, baixo, alto, comparacoes);

            int left_size  = pi - 1 - baixo;
            int right_size = alto - (pi + 1);

            if (left_size > right_size) {
                stack_low[++top]  = baixo;
                stack_high[top]   = pi - 1;
                stack_low[++top]  = pi + 1;
                stack_high[top]   = alto;
            } else {
                stack_low[++top]  = pi + 1;
                stack_high[top]   = alto;
                stack_low[++top]  = baixo;
                stack_high[top]   = pi - 1;
            }
        }
    }

    free(stack_low);
    free(stack_high);
}

int esta_ordenado(int *arr, int n) {
    for (int i = 0; i < n-1; i++)
        if (arr[i] > arr[i+1])
            return 0;
    return 1;
}