#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Implementación del algoritmo de Dijkstra
void dijkstra(const vector<vector<int>>& graph, int start, vector<int>& dist) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        // Encuentra el nodo no visitado con la distancia más pequeña
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        // Si no se puede mejorar, termina
        if (dist[u] == INT_MAX)
            break;

        visited[u] = true;

        // Actualiza las distancias
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != -1 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

// Implementación del algoritmo de Floyd-Warshall
void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    
    // Inicializar el gráfico: si no hay arco, el valor debe ser infinito (excepto la diagonal)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == -1 && i != j) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    // Leer la matriz de adyacencia
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    // Ejecutar Dijkstra para cada nodo
    cout << "Dijkstra :" << endl;
    for (int i = 0; i < n; ++i) {
        vector<int> dist(n, INT_MAX);
        dijkstra(graph, i, dist);
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (dist[j] == INT_MAX) {
                    cout << "node " << i+1 << " to node " << j+1 << " : INF" << endl;
                } else {
                    cout << "node " << i+1 << " to node " << j+1 << " : " << dist[j] << endl;
                }
            }
        }
    }

    // Ejecutar el algoritmo de Floyd-Warshall
    floydWarshall(graph);
    
    // Imprimir la matriz resultante de Floyd-Warshall
    cout << "\nFloyd :" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
