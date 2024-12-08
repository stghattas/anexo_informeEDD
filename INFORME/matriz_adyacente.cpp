#include <iostream>

#define MAX_VERTICES 10  // Definimos un número máximo de vértices

using namespace std;

class Graph {
private:
    int V;  // Número de vértices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Matriz de adyacencia

public:
    Graph(int vertices) : V(vertices) {
        // Inicializamos la matriz con 0 (sin conexiones)
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Añadir una arista (dirigida)
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjMatrix[u][v] = 1;
        }
    }

    // Mostrar la matriz de adyacencia
    void display() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);  // Creamos un grafo con 5 vértices

    g.addEdge(0, 1);  // Añadimos una arista de 0 a 1
    g.addEdge(1, 2);  // Añadimos una arista de 1 a 2
    g.addEdge(2, 3);  // Añadimos una arista de 2 a 3
    g.addEdge(3, 4);  // Añadimos una arista de 3 a 4

    cout << "Matriz de adyacencia del grafo:" << endl;
    g.display();

    return 0;
}
