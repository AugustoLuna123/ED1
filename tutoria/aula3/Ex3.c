#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int dist[][V], int V);
void printSolution(int dist[][V], int V);

int main() {
    /* Exemplo de gráfico de entrada */
    int graph[V][V] = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    /* Cria uma cópia da matriz de entrada */
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    /* Aplica o algoritmo de Floyd-Warshall */
    floydWarshall(dist, V);

    /* Imprime a solução */
    printSolution(dist, V);

    return 0;
}

void floydWarshall(int dist[][V], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printSolution(int dist[][V], int V) {
    printf("Matriz de distâncias mais curtas entre cada par de vértices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}
