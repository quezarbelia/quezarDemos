#include <iostream>
#include <queue>
#include <vector>
#define MAXV 100
#define oo 0x3f3f3f3f
using namespace std;

struct Edge
{
    int node;
    int cost;
    Edge(int _node, int _cost) : node(_node), cost(_cost) {}
    Edge() : node(-1), cost(-1) {}
};

struct Graph
{
    vector<Edge> G[MAXV];
    int V;
    int E;
};

struct State
{
    int node;
    int cost;
    State(int _node, int _cost) : node(_node), cost(_cost) {}
    bool operator <(const State &b) const
    {
        return cost > b.cost;
    }
};

int algoritmo(const int begin, const int end, const Graph graph)
{
    priority_queue<State> pq;
    vector<int> Dist(graph.V, oo);
    vector<bool> mark(graph.V, false);

    Dist[begin] = 0;
    pq.push(State(begin, 0));
    while(!pq.empty())
    {
        State st = pq.top(); pq.pop();
        mark[st.node] = true;
        if (st.node == end)
            return st.cost;

        int T = (int)graph.G[st.node].size();
        for(int i = 0; i < T; ++i)
        {
            if (!mark[graph.G[st.node][i].node] && ((Dist[st.node] + graph.G[st.node][i].cost) < Dist[graph.G[st.node][i].node]))
            {
                Dist[graph.G[st.node][i].node] = Dist[st.node] + graph.G[st.node][i].cost;
                pq.push(State(graph.G[st.node][i].node, st.cost + graph.G[st.node][i].cost));
            }
        }
    }
    return -1;
}

struct Programa
{
    int V, E;
    int comienzo, fin;
    void definirGrafo(Graph& graph)
    {
        cout << "Ingrese Cantidad de Vertices: " << endl;
        cin >> V;
        cout << "Ingrese Cantidad de Aristas: " << endl;
        cin >> E;

        graph.V = V;
        graph.E = E;
    }
    void cargarGrafo(Graph & graph)
    {
        for (int i = 0; i < E; ++i)
        {
            int Origen, Destino, Peso;
            cout << "Ingrese Origen: " << endl;
            cin >> Origen;
            cout << "Ingrese Destino: " << endl;
            cin >> Destino;
            cout << "Ingrese Peso de la Arista: " << endl;
            cin >> Peso;

            graph.G[Origen].push_back(Edge(Destino, Peso));
            graph.G[Destino].push_back(Edge(Origen, Peso));
        }
    }
    void Dijkstra(Graph graph)
    {
        cout << "Ingrese Vertice Inicial: " << endl;
        cin >> comienzo;
        cout << "Ingrese Vertice Final: " << endl;
        cin >> fin;
        int n = algoritmo(comienzo, fin, graph);
        cout << "Longitud del Camino mas Corto: " << n << endl;
    }
};

int main()
{
    bool out = false;
    char salir;

    Programa programa;
    Graph graph;

    cout << "Ruta mas corta" << endl;

    while (!out)
    {
        programa.definirGrafo(graph);
        programa.cargarGrafo(graph);
        programa.Dijkstra(graph);

        cout << "Salir? (S/N)" << endl;
        cin >> salir;
        if (salir == 'S')
        {
            out = true;
        }
    }
}