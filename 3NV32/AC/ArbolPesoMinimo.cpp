#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Estructura para representar los caminos (aristas)
struct Arista {
    int origen, destino, peso;
    bool operator<(const Arista& otra) const {
        return peso < otra.peso; // Para ordenar de menor a mayor costo
    }
};

// Estructura de control para Kruskal (Evita ciclos)
struct DisjointSet {
    vector<int> padre;
    DisjointSet(int n) {
        padre.resize(n);
        for (int i = 0; i < n; i++) padre[i] = i;
    }
    int buscar(int i) {
        if (padre[i] == i) return i;
        return padre[i] = buscar(padre[i]);
    }
    void unir(int i, int j) {
        int raiz_i = buscar(i);
        int raiz_j = buscar(j);
        if (raiz_i != raiz_j) padre[raiz_i] = raiz_j;
    }
};

// --- ALGORITMO DE KRUSKAL ---
void kruskal(int nodos, vector<Arista> aristas) {
    // 1. Ordenar caminos por peso
    sort(aristas.begin(), aristas.end());
    
    DisjointSet ds(nodos);
    int costoTotal = 0;

    cout << "\n[Resultado por Kruskal]:\n";
    for (const auto& arista : aristas) {
        // 2. Si no forma un ciclo, se conecta
        if (ds.buscar(arista.origen) != ds.buscar(arista.destino)) {
            ds.unir(arista.origen, arista.destino);
            cout << "  Ciudad " << arista.origen << " - Ciudad " << arista.destino << " (Costo: " << arista.peso << ")\n";
            costoTotal += arista.peso;
        }
    }
    cout << "Costo Total Kruskal: " << costoTotal << "\n";
}

// --- ALGORITMO DE PRIM ---
void prim(int nodos, const vector<vector<pair<int, int>>>& grafo) {
    // Cola de prioridad para elegir siempre el camino más barato disponible: {peso, {origen, destino}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    vector<bool> visitado(nodos, false);
    int costoTotal = 0;

    cout << "\n[Resultado por Prim]:\n";
    
    // Empezamos desde la ciudad 0
    visitado[0] = true;
    for (auto vecino : grafo[0]) {
        pq.push({vecino.second, {0, vecino.first}});
    }

    while (!pq.empty()) {
        auto tope = pq.top();
        pq.pop();

        int peso = tope.first;
        int u = tope.second.first;  // origen
        int v = tope.second.second; // destino

        // Si la ciudad ya está conectada al árbol, la ignoramos
        if (visitado[v]) continue;

        visitado[v] = true;
        costoTotal += peso;
        cout << "  Ciudad " << u << " - Ciudad " << v << " (Costo: " << peso << ")\n";

        // Añadimos caminos de la nueva ciudad conectada
        for (auto vecino : grafo[v]) {
            if (!visitado[vecino.first]) {
                pq.push({vecino.second, {v, vecino.first}});
            }
        }
    }
    cout << "Costo Total Prim: " << costoTotal << "\n";
}

// --- FUNCIÓN PRINCIPAL QUE COORDINA TODO ---
void ArbolPesoMinimo() {
    int nodos = 4; // Ciudades 0, 1, 2, 3

    // Estructura de datos en forma de lista (Ideal para Kruskal)
    vector<Arista> aristas = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    // Estructura de datos en forma de matriz/lista de adyacencia (Ideal para Prim)
    vector<vector<pair<int, int>>> grafo(nodos);
    for (const auto& a : aristas) {
        grafo[a.origen].push_back({a.destino, a.peso});
        grafo[a.destino].push_back({a.origen, a.peso}); // Es bidireccional
    }

    // Llamamos a los algoritmos solicitados
    kruskal(nodos, aristas);
    prim(nodos, grafo);
}

int main() {
    // Ejecutamos la función contenedora
    ArbolPesoMinimo();
    return 0;
}