#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>
#include <math.h>

#define MAX_VERTICES 5000
#define PESO_MAX 10
#define EXECUCOES 30

OI

// Estrutura de aresta
typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta* prox;
} Aresta;

// Lista de adjacência
Aresta* grafo[MAX_VERTICES];

// Adiciona uma aresta ao grafo
void adicionar_aresta(int origem, int destino, int peso) {
    Aresta* nova = (Aresta*)malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->peso = peso;
    nova->prox = grafo[origem];
    grafo[origem] = nova;
}

// Libera memória do grafo
void liberar_grafo(int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        Aresta* atual = grafo[i];
        while (atual != NULL) {
            Aresta* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        grafo[i] = NULL;
    }
}

// Gera um grafo aleatório direcionado e ponderado com densidade variável
void gerar_grafo(int num_vertices, double densidade) {
    liberar_grafo(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        grafo[i] = NULL;
    }
    for (int u = 0; u < num_vertices; u++) {
        for (int v = 0; v < num_vertices; v++) {
            if (u != v && ((double)rand() / RAND_MAX) < densidade) {
                int peso = rand() % PESO_MAX + 1;
                adicionar_aresta(u, v, peso);
            }
        }
    }
}

// Estrutura para min-heap
typedef struct {
    int vertice;
    int distancia;
} NoHeap;

void trocar(NoHeap* a, NoHeap* b) {
    NoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(NoHeap heap[], int size, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < size && heap[esq].distancia < heap[menor].distancia)
        menor = esq;
    if (dir < size && heap[dir].distancia < heap[menor].distancia)
        menor = dir;

    if (menor != i) {
        trocar(&heap[i], &heap[menor]);
        heapify(heap, size, menor);
    }
}

// Algoritmo de Dijkstra com heap mínimo
void dijkstra(int num_vertices, int origem, int dist[]) {
    int visitado[MAX_VERTICES] = {0};
    for (int i = 0; i < num_vertices; i++) dist[i] = INT_MAX;
    dist[origem] = 0;

    NoHeap heap[MAX_VERTICES];
    int tamanho_heap = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        heap[i].vertice = i;
        heap[i].distancia = dist[i];
    }

    for (int i = tamanho_heap / 2 - 1; i >= 0; i--) {
        heapify(heap, tamanho_heap, i);
    }

    while (tamanho_heap > 0) {
        NoHeap min = heap[0];
        int u = min.vertice;

        heap[0] = heap[tamanho_heap - 1];
        tamanho_heap--;
        heapify(heap, tamanho_heap, 0);

        if (visitado[u]) continue;
        visitado[u] = 1;

        Aresta* atual = grafo[u];
        while (atual != NULL) {
            int v = atual->destino;
            int peso = atual->peso;
            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                // Atualiza heap para v
                for (int i = 0; i < tamanho_heap; i++) {
                    if (heap[i].vertice == v) {
                        heap[i].distancia = dist[v];
                        break;
                    }
                }
                for (int i = tamanho_heap / 2 - 1; i >= 0; i--) {
                    heapify(heap, tamanho_heap, i);
                }
            }
            atual = atual->prox;
        }
    }
}

// Calcula média e desvio padrão dos tempos
void calcular_estatisticas(double tempos[], int n, double* media, double* desvio) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) soma += tempos[i];
    *media = soma / n;

    double variancia = 0.0;
    for (int i = 0; i < n; i++) variancia += (tempos[i] - *media) * (tempos[i] - *media);
    *desvio = sqrt(variancia / n);
}

int main() {
    srand(42);  // Semente fixa

    int tamanhos[] = {100, 1000, 5000};
    double densidades[] = {0.05, 0.1, 0.2, 0.4};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int num_densidades = sizeof(densidades) / sizeof(densidades[0]);

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq); // Frequência do contador de alta resolução

    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho = tamanhos[t];
        for (int d = 0; d < num_densidades; d++) {
            double densidade = densidades[d];
            double tempos[EXECUCOES];

            gerar_grafo(tamanho, densidade);

            for (int i = 0; i < EXECUCOES; i++) {
                int dist[MAX_VERTICES];
                LARGE_INTEGER inicio, fim;

                QueryPerformanceCounter(&inicio);
                dijkstra(tamanho, 0, dist);
                QueryPerformanceCounter(&fim);

                double tempo = (double)(fim.QuadPart - inicio.QuadPart) / freq.QuadPart;
                tempos[i] = tempo;
            }

            double media, desvio;
            calcular_estatisticas(tempos, EXECUCOES, &media, &desvio);

            printf("Grafo com %d vértices e densidade %.2f:\n", tamanho, densidade);
            printf("Tempo médio: %.6f segundos\n", media);
            printf("Desvio padrão: %.6f segundos\n\n", desvio);

            liberar_grafo(tamanho);  // Liberar memória para evitar vazamento
        }
    }

    return 0;
}
