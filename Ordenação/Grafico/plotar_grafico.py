import matplotlib.pyplot as plt
import csv
from collections import defaultdict

def ler_csv_ordenacao(nome_arquivo, tipo_desejado):
    dados = defaultdict(list)

    with open(nome_arquivo, "r") as arquivo:
        leitor = csv.reader(arquivo)
        next(leitor)  # Pula o cabeçalho

        for linha in leitor:
            algoritmo, tipo, tamanho, comparacoes, tempo = linha

            if tipo_desejado not in tipo:
                continue  # pula tipos que não batem (ex: filtrando só "sorted")

            # Normaliza o nome do algoritmo
            nome = algoritmo.lower().strip()
            if "bubble" in nome:
                chave = "bubble"
            elif "insertion" in nome:
                chave = "insertion"
            elif "merge" in nome:
                chave = "merge"
            elif "quick" in nome:
                chave = "quick"
            else:
                continue  # ignora outros algoritmos

            dados[chave].append((int(tamanho), int(comparacoes)))

    return dados

def plotar_comparacoes(dados_por_algoritmo, tipo_teste):
    plt.figure(figsize=(10, 6))

    for algoritmo, valores in dados_por_algoritmo.items():
        # Ordena por tamanho para melhor visualização
        valores.sort()
        tamanhos = [t for t, _ in valores]
        comparacoes = [c for _, c in valores]

        plt.plot(tamanhos, comparacoes, label=algoritmo, marker='o')

    plt.title(f"Comparações vs Tamanho do Array ({tipo_teste})")
    plt.xlabel("Tamanho do Array")
    plt.ylabel("Número de Comparações")
    plt.xscale("log")
    plt.yscale("log")
    plt.grid(True, which="both", ls="--")
    plt.legend()
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    # Ajuste o caminho conforme necessário
    caminho_csv = "../resultados/resultados_3repeticoes.csv"
    
    # Troque para "random" ou "desc" se quiser comparar outro tipo
    tipo_teste = "sorted"

    dados = ler_csv_ordenacao(caminho_csv, tipo_teste)
    plotar_comparacoes(dados, tipo_teste)