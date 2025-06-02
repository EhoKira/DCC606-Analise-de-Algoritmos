#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gerar_ordenado(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

void gerar_decrescente(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void embaralhar(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void salvar_em_arquivo(int *arr, int n, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        perror("Erro ao criar arquivo");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d\n", arr[i]);
    fclose(fp);
}

int main() {
    int tamanhos[] = {1000, 5000, 10000, 50000, 100000, 250000, 500000, 750000, 1000000};
    const int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    char nome_arquivo[100];
    
    criar_pasta("../entradas");  // Ajuste o caminho relativo conforme onde executa


    srand(time(NULL)); // semente para números aleatórios

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        int *arr = malloc(n * sizeof(int));
        if (!arr) {
            fprintf(stderr, "Erro de memória para tamanho %d\n", n);
            exit(1);
        }

        // Ordenado crescente
        gerar_ordenado(arr, n);
        snprintf(nome_arquivo, sizeof(nome_arquivo), "../entradas/entrada_%d_sorted.txt", n);
        salvar_em_arquivo(arr, n, nome_arquivo);

        // Decrescente
        gerar_decrescente(arr, n);
        snprintf(nome_arquivo, sizeof(nome_arquivo), "../entradas/entrada_%d_desc.txt", n);
        salvar_em_arquivo(arr, n, nome_arquivo);

        // Aleatório
        gerar_ordenado(arr, n);
        embaralhar(arr, n);
        snprintf(nome_arquivo, sizeof(nome_arquivo), "../entradas/entrada_%d_random.txt", n);
        salvar_em_arquivo(arr, n, nome_arquivo);

        free(arr);
    }

    printf("Arquivos gerados com sucesso.\n");
    return 0;
}