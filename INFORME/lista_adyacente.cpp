#include <iostream>

#define MAX_VERTICES 10  // Número máximo de vértices

using namespace std;

// Definimos la estructura de un nodo de lista
struct Node {
    int data;
    Node* next;
    
    // Constructor para inicializar el nodo
    Node(int val) : data(val), next(nullptr) {}
};

class Graph {
private:
    int V;  // Número de vértices
    Node* adjList[MAX_VERTICES];  // Arreglo de listas de adyacencia

public:
    Graph(int vertices) : V(vertices) {
        // Inicializamos las listas de adyacencia a nullptr
        for (int i = 0; i < V; ++i) {
            adjList[i] = nullptr;
        }
    }

    // Añadir una arista (dirigida)
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            // Creamos un nuevo nodo para la lista de adyacencia de u
            Node* newNode = new Node(v);
            newNode->next = adjList[u];  // Apuntamos al primer nodo actual
            adjList[u] = newNode;  // Ahora el nuevo nodo es el primero
        }
    }

    // Mostrar las listas de adyacencia
    void display() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertice " << i << ": ";
            Node* current = adjList[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
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
    g.addEdge(0, 2);  // Añadimos una arista de 0 a 2

    cout << "Lista de adyacencia del grafo:" << endl;
    g.display();

    return 0;
}
