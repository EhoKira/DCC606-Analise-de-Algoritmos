# Análise e Comparação de Algoritmos de Ordenação em C

## Descrição

Este projeto tem como objetivo implementar e comparar algoritmos de ordenação em C, avaliando o tempo de execução e o número de comparações feitas para diferentes tipos e tamanhos de listas de números inteiros.

---

## Organização do Projeto

A organização sugerida para o projeto é a seguinte:

- **entradas/**: arquivos contendo listas de números para ordenar.  
- **algoritmos/**: implementação dos algoritmos de ordenação.  
- **utils/**: utilitários para geração de entradas e medição de desempenho.  
- **resultados/**: arquivos com os dados coletados dos testes.  
- **graficos/**: scripts para geração dos gráficos comparativos.

---

## Algoritmos Implementados

- Bubble Sort  
- Insertion Sort  
- Merge Sort  
- Quick Sort  

---

## Tipos de Entrada

- Ordenado (exemplo: 1, 2, 3, ..., N)  
- Aleatório (números embaralhados)  
- Decrescente (exemplo: N, N-1, ..., 1)  

---

## Tamanhos das Entradas

- 1.000  
- 10.000  
- 100.000  
- 500.000  
- 1.000.000  

---

## Coleta de Dados

Para cada algoritmo e tipo de entrada, serão medidos:

- Tempo de execução utilizando a função `clock()` da biblioteca `<time.h>`.  
- Número de comparações realizadas durante a ordenação.

---

## Geração de Gráficos

Serão gerados gráficos para comparação dos algoritmos, divididos por tipo de entrada:

1. Tempo de execução vs. tamanho da entrada  
2. Número de comparações vs. tamanho da entrada  

---

## Como Executar (a preencher)

> Aqui você poderá descrever futuramente como compilar e rodar o código, por exemplo:

```bash
gcc algoritmos/bubble_sort.c utils/medir_performance.c -o bubble_sort
./bubble_sort entradas/entrada_1000_random.txt
