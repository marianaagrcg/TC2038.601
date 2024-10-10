#include <iostream>
#include <vector>
#include <fstream>
#include <climits> // Para usar INT_MAX
using namespace std;

#define INF INT_MAX

void leerMatrizDesdeEntrada(vector<vector<int>>& matriz, int& tam) {
    cin >> tam;

    matriz.resize(tam, vector<int>(tam));

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            int valor;
            cin >> valor;
            if (valor == -1) {
                matriz[i][j] = INF; 
            } else {
                matriz[i][j] = valor;
            }
        }
    }
}

// Algoritmo de Dijkstra para un solo nodo origen
void dijkstra(const vector<vector<int>>& grafo, int src) {
    int tam = grafo.size();
    vector<int> dist(tam, INF); 
    vector<bool> visitado(tam, false); 

    dist[src] = 0;

    for (int count = 0; count < tam - 1; count++) {
        int minDist = INF, u = -1;

        // Encontrar el vértice con la distancia mínima no visitado
        for (int v = 0; v < tam; v++) {
            if (!visitado[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visitado[u] = true;

        // Actualizar las distancias de los vértices adyacentes
        for (int v = 0; v < tam; v++) {
            if (!visitado[v] && grafo[u][v] != INF && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // Imprimir distancias desde el nodo fuente
    for (int i = 0; i < tam; i++) {
        if (i != src) {
            if (dist[i] == INF)
                cout << "node " << src + 1 << " to node " << i + 1 << " : -1\n";
            else
                cout << "node " << src + 1 << " to node " << i + 1 << " : " << dist[i] << "\n";
        }
    }
}

// Algoritmo de Floyd-Warshall
void floydWarshall(vector<vector<int>>& grafo) {
    int tam = grafo.size();
    vector<vector<int>> dist = grafo;

    for (int k = 0; k < tam; k++) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Imprimir la matriz de distancias mínimas
    cout << "\nFloyd :\n";
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (dist[i][j] == INF)
                cout << "-1 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> matriz;
    int tam;

    // Leer la matriz desde la entrada
    leerMatrizDesdeEntrada(matriz, tam);

    cout << "Dijkstra :\n";
    for (int i = 0; i < tam; i++) {
        dijkstra(matriz, i);
    }

    floydWarshall(matriz);

    return 0;
}
