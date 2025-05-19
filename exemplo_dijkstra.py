import random
import heapq
import statistics
import time


random.seed(42)

# Função que gera um grafo aleatório, direcionado e ponderado
def gerar_grafo(num_vertices, densidade=0.2, peso_max=10):
    grafo = {i: [] for i in range(num_vertices)}  # Inicializa o grafo como um dicionário de listas de adjacência
    for u in range(num_vertices):
        for v in range(num_vertices):
            if u != v and random.random() < densidade:  
                peso = random.randint(1, peso_max)       
                grafo[u].append((v, peso))               
    return grafo

# Implementação do algoritmo de Dijkstra usando uma fila de prioridade (heap)
def dijkstra(grafo, origem):
    dist = {v: float('inf') for v in grafo}  # Inicializa distâncias com infinito
    dist[origem] = 0                         
    heap = [(0, origem)]                     

    while heap:
        custo, u = heapq.heappop(heap)       # Remove o vértice com menor custo
        if custo > dist[u]:                  
            continue
        for v, peso in grafo[u]:           
            if dist[u] + peso < dist[v]:     
                dist[v] = dist[u] + peso
                heapq.heappush(heap, (dist[v], v))  # Adiciona o vizinho no heap com novo custo
    return dist

# Função que mede o tempo de execução médio e desvio padrão para o algoritmo de Dijkstra
def testar_execucao(num_vertices, execucoes=20):
    tempos = []
    grafo = gerar_grafo(num_vertices)        
    for _ in range(execucoes):                
        inicio = time.perf_counter()         
        dijkstra(grafo, 0)                    
        fim = time.perf_counter()            
        tempos.append(fim - inicio)           
    media = statistics.mean(tempos)           
    desvio = statistics.stdev(tempos)         
    return media, desvio

# Lista de tamanhos de entrada (pequena, média, grande) para simulação
tamanhos = [100, 1000, 5000]
for tamanho in tamanhos:
    media, desvio = testar_execucao(tamanho, execucoes=30)  # Executa 30 vezes por entrada
    print(f"Grafo com {tamanho} vértices:")
    print(f"Tempo médio: {media:.6f} segundos")
    print(f"Desvio padrão: {desvio:.6f} segundos\n")
