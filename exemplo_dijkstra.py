import random
import heapq
import statistics
import time

random.seed(42)

def gerar_grafo(num_vertices, densidade=0.2, peso_max=10):
    grafo = {i: [] for i in range(num_vertices)}
    for u in range(num_vertices):
        for v in range(num_vertices):
            if u != v and random.random() < densidade:
                peso = random.randint(1, peso_max)
                grafo[u].append((v, peso))
    return grafo

def dijkstra(grafo, origem):
    dist = {v: float('inf') for v in grafo}
    dist[origem] = 0
    heap = [(0, origem)]

    while heap:
        custo, u = heapq.heappop(heap)
        if custo > dist[u]:
            continue
        for v, peso in grafo[u]:
            if dist[u] + peso < dist[v]:
                dist[v] = dist[u] + peso
                heapq.heappush(heap, (dist[v], v))
    return dist

def testar_execucao(num_vertices, densidade, execucoes=20):
    tempos = []
    grafo = gerar_grafo(num_vertices, densidade)
    for _ in range(execucoes):
        inicio = time.perf_counter()
        dijkstra(grafo, 0)
        fim = time.perf_counter()
        tempos.append(fim - inicio)
    media = statistics.mean(tempos)
    desvio = statistics.stdev(tempos)
    return media, desvio

# Variação de vértices e densidades para análise
tamanhos = [100, 1000, 5000]
densidades = [0.05, 0.1, 0.2, 0.4]  # Arestas entre 5% e 40% possíveis

for tamanho in tamanhos:
    for densidade in densidades:
        media, desvio = testar_execucao(tamanho, densidade, execucoes=20)
        print(f"Grafo com {tamanho} vértices e densidade {densidade*100:.0f}%:")
        print(f"Tempo médio: {media:.6f} segundos")
        print(f"Desvio padrão: {desvio:.6f} segundos\n")
