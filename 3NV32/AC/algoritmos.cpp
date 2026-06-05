//Programador: Gabriel Quezada Avila
//Grupo: 3NV32
//Fecha: 01/06/2026

#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cctype>
#include <algorithm>
#include <limits>
#define MAXV 100
#define oo 0x3f3f3f3f
using namespace std;

int arrTemp[100];
int nTemp = 0;

void limpiarBuffer() {
    cin.ignore(numeric_limits<int>::max(), '\n');
}

void menu();
void recursividad();
void hanoi(int n, char origen, char destino, char auxiliar, long long &movimientos);
void ingresarAr();
void Inserccion(int arr_orig[], int n);
void mA(int arr[], int n, const char *titulo);
void menuB();
void bus(int arr[], int n);
void busquedaBinaria(int arr[], int n);
void busquedaSecuencial(int arr[], int n);
void grafo();
void arbol();

// MENU PRINCIPAL
void menu(){
    int op=1;
    while(op==1){
        system("cls");
        cout << "\n========== M E N U ==========" << endl;
        cout << "Quezada Avila Gabriel" << endl;
        cout << "1) Recursividad" << endl;
        cout << "2) Ordenamientos" << endl;
        cout << "3) Grafo" << endl;
        cout << "4) Arbol" << endl;
        cout << "5) Salir" << endl;
        cout << "\nIngresa una opcion: ";
        cin >> op;

        if (op==5){
            cout<<"Saliendo..."<<endl;
            break;
            return;
        }

        switch(op){
            case 1:
                recursividad();
                break;
            case 2:
                ingresarAr();
                break;
            case 3:
                grafo();
                break;
            case 4:
                arbol();
                break;
            default:
                break;
                return;
        }
    }
    system("cls");
}

// RECURSIVIDAD TORRES DE HANOI
void hanoi(int n, char origen, char destino, char auxiliar, long long &movimientos){
    if(n == 1){
        cout << "Mover disco de " << origen << " a " << destino << endl;
        movimientos++;
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino, movimientos);
    cout << "Mover disco de " << origen << " a " << destino << endl;
    movimientos++;
    hanoi(n - 1, auxiliar, destino, origen, movimientos);
}

void recursividad(){
    system("cls");
    cout<<"=== Torres de Hanoi ==="<<endl;
    int discos;
    cout << "Ingresa el numero de discos (maximo 10): ";
    cin >> discos;
    
    if(discos < 1 || discos > 10){
        cout << "\nError: El numero de discos debe estar entre 1 y 10." << endl;
        cout << "\nPresiona Enter para continuar...";
        limpiarBuffer();
        cin.get();
        return;
    }
    
    cout << "\nLos movimientos para " << discos << " discos son:" << endl;
    long long movimientos = 0;
    hanoi(discos, 'A', 'C', 'B', movimientos);
    cout << "\nTotal de movimientos: " << movimientos << endl;

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
}

// FUNCIONES ARREGLO
void ingresarAr()
{
    system("cls");
    cout << "ingresa el tamanio del arreglo: ";
    int n;
    cin >> n;
    int *miArreglo = new int[n];
    cout <<"Ingresa los "<<n<<" elementos del arreglo: " << endl;
    for(int i=0;i<n;i++){
        cout<<"Elemento "<< i+1 <<": ";
        cin>>miArreglo[i];
    }
    cout << "Metodo de ordenamiento de Insercion"<<endl;
    Inserccion(miArreglo,n);
    delete[] miArreglo;
}

void Inserccion(int arr_orig[], int n){
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=arr_orig[i];
    }
    int m=0,c=0;
    system("cls");
    cout<<"\n";
    mA(arr,n,"Arreglo original: ");

    for(int i=1;i<n;i++){
        int llave=arr[i];
        int j=i-1;
        while(j>=0){
            c++;
            if(arr[j]>llave){
                arr[j+1]=arr[j];
                j--;
                m++;
            }else{
                break;
            }
        }
        arr[j+1]=llave;
    }
    mA(arr, n, "Arreglo ordenado: ");
    cout << "\n--> Comparaciones realizadas: " << c;
    cout << "\n--> Movimientos (desplazamientos): " << m << endl;

    cout << "\nDesea realizar una busqueda? (1=Si / 0=No): ";
    int opc;
    cin >> opc;
    if(opc == 1){
        bus(arr, n);
    }

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
}

void mA(int arr[], int n, const char *titulo){
    cout << titulo;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

// MENU BUSQUEDA
void menuB(){
    cout<< "Elige el valor a buscar:" <<endl;
    cout<< "1) Busqueda Secuencial" <<endl;
    cout<< "2) Busqueda Binaria" <<endl;
    cout<< "3) Regresar" <<endl;
    int opc;
    cin >> opc;
    if(opc==1){
        busquedaSecuencial(arrTemp, nTemp);
    } else if(opc==2){
        busquedaBinaria(arrTemp, nTemp);
    }
}

void bus(int arr[], int n){
    for(int i=0;i<n;i++){
        arrTemp[i] = arr[i];
    }
    nTemp = n;
    menuB();
}

void busquedaBinaria(int arr[], int n){
    int dato, inferior = 0, superior = n - 1, mitad;
    bool encontrado = false;
    int comparaciones = 0;
    system("cls");
    cout << "\n--- BUSQUEDA BINARIA ---" << endl;
        mA(arrTemp, nTemp, "Arreglo ordenado: ");
    cout << "Ingrese el valor a buscar en el arreglo ordenado: ";
    cin >> dato;

    while (inferior <= superior) {
        comparaciones++;
        mitad = inferior + (superior - inferior) / 2;

        if (arr[mitad] == dato) {
            encontrado = true;
            break;
        }

        if (arr[mitad] < dato) {
            inferior = mitad + 1;
        } else {
            superior = mitad - 1;
        }
    }

    if (encontrado) {
        cout << "-> Elemento " << dato << " encontrado en la posicion: " << mitad+1 << endl;
    } else {
        cout << "-> Elemento " << dato << " no existe en el arreglo." << endl;
    }
    cout << "-> Comparaciones realizadas en busqueda: " << comparaciones << endl;

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
    menu();
}

void busquedaSecuencial(int arr[], int n){
    int dato;
    bool encontrado = false;
    int comparaciones = 0;
    system("cls");
    cout << "\n--- BUSQUEDA SECUENCIAL ---" << endl;
    mA(arrTemp, nTemp, "Arreglo ordenado: ");
    cout << "Ingrese el valor a buscar: ";
    cin >> dato;

    for (int i = 0; i < n; i++) {
        comparaciones++;
        if (arr[i] == dato) {
            cout << "-> Elemento " << dato << " encontrado en la posicion: " << i+1 << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "-> Elemento " << dato << " no existe en el arreglo." << endl;
    }
    cout << "-> Comparaciones realizadas en busqueda: " << comparaciones << endl;

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
    menu();
}

// GRAFO UPIICSA
struct Edge {
    int node;
    int cost;
    Edge(int _node, int _cost) : node(_node), cost(_cost) {}
    Edge() : node(-1), cost(-1) {}
};

struct Graph {
    vector<Edge> G[MAXV];
    int V;
    int E;
};

struct State {
    int node;
    int cost;
    State(int _node, int _cost) : node(_node), cost(_cost) {}
    bool operator <(const State &b) const {
        return cost > b.cost;
    }
};

pair<int, vector<int>> dijkstraCamino(int begin, int end, const Graph& graph) {
    priority_queue<State> pq;
    vector<int> Dist(graph.V, oo);
    vector<int> prev(graph.V, -1);
    vector<bool> mark(graph.V, false);

    Dist[begin] = 0;
    pq.push(State(begin, 0));

    while(!pq.empty()) {
        State st = pq.top(); pq.pop();
        mark[st.node] = true;
        if (st.node == end) {
            vector<int> camino;
            for(int at = end; at != -1; at = prev[at]) {
                camino.push_back(at);
            }
            reverse(camino.begin(), camino.end());
            return {st.cost, camino};
        }

        int T = (int)graph.G[st.node].size();
        for(int i = 0; i < T; ++i) {
            int siguienteNodo = graph.G[st.node][i].node;
            int pesoArista = graph.G[st.node][i].cost;

            if (!mark[siguienteNodo] && ((Dist[st.node] + pesoArista) < Dist[siguienteNodo])) {
                Dist[siguienteNodo] = Dist[st.node] + pesoArista;
                prev[siguienteNodo] = st.node;
                pq.push(State(siguienteNodo, st.cost + pesoArista));
            }
        }
    }
    return {-1, {}};
}

void grafo(){
    system("cls");
    Graph graph;
    graph.V = 9;

    graph.G[0].push_back(Edge(1, 50));
    graph.G[0].push_back(Edge(2, 30));
    graph.G[1].push_back(Edge(0, 50));

    graph.G[1].push_back(Edge(2, 20));
    graph.G[1].push_back(Edge(3, 40));
    graph.G[2].push_back(Edge(1, 20));
    graph.G[2].push_back(Edge(3, 50));
    graph.G[2].push_back(Edge(4, 20));

    graph.G[3].push_back(Edge(1, 40));
    graph.G[3].push_back(Edge(2, 50));
    graph.G[3].push_back(Edge(4, 30));
    graph.G[3].push_back(Edge(5, 40));
    graph.G[3].push_back(Edge(7, 70));

    graph.G[4].push_back(Edge(3, 30));
    graph.G[4].push_back(Edge(2, 20));
    graph.G[4].push_back(Edge(5, 30));
    graph.G[4].push_back(Edge(6, 70));

    graph.G[5].push_back(Edge(3, 40));
    graph.G[5].push_back(Edge(4, 30));
    graph.G[5].push_back(Edge(7, 50));
    graph.G[5].push_back(Edge(8, 80));

    graph.G[6].push_back(Edge(4, 70));
    graph.G[6].push_back(Edge(7, 20));
    graph.G[6].push_back(Edge(5, 80));

    graph.G[7].push_back(Edge(3, 70));
    graph.G[7].push_back(Edge(6, 20));
    graph.G[7].push_back(Edge(5, 50));

    graph.G[8].push_back(Edge(5, 80));
    graph.G[8].push_back(Edge(6, 30));

    char origenLetra, destinoLetra;
    cout << "======= Grafo UPIICSA =======" << endl;
    cout << "Nodos:\nGraduados(G)\nBasicas(B) \nLigeros(L) \nGobierno (A)\nSociales(S) \nCulturales(C)\nGimnasio (Y)\nIngeneria(I)\nPesados(P)" << endl;
    cout << "Ingrese nodo origen: ";
    cin >> origenLetra;
    cout << "Ingrese nodo destino: ";
    cin >> destinoLetra;

    char nodos[] = {'G','B','L','A','S','C','Y','I','P'};
    int origen = -1;
    int destino = -1;
    for(int i=0;i<9;i++){
        if(toupper(origenLetra)==nodos[i]) origen = i;
        if(toupper(destinoLetra)==nodos[i]) destino = i;
    }

    if(origen < 0 || origen >= 9 || destino < 0 || destino >= 9){
        cout << "Error: Nodos invalidos. Usa G, B, L, A, S, C, Y, I, P" << endl;
        cout << "\nPresiona Enter para continuar...";
        limpiarBuffer();
        cin.get();
        return;
    }

    auto resultado = dijkstraCamino(origen, destino, graph);
    if(resultado.first == -1){
        cout << "\nNo existe ruta entre " << origenLetra << " y " << destinoLetra << endl;
    } else {
        cout << "\nLa distancia mas corta entre " << origenLetra << " y " << destinoLetra << " es: " << resultado.first << " mts" << endl;
        cout << "Camino: ";
        for(size_t i = 0; i < resultado.second.size(); i++){
            cout << nodos[resultado.second[i]];
            if(i < resultado.second.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
    menu();
}

// ARBOL
void arbol(){
    system("cls");
    Graph graph;
    graph.V = 12;
    graph.E = 11;

    int conexiones[11][2] = {
        {0, 1},  // A - B
        {0, 2},  // A - C
        {1, 3},  // B - D
        {1, 4},  // B - E
        {1, 5},  // B - F
        {2, 6},  // C - G
        {2, 7},  // C - H
        {3, 8},  // D - I
        {5, 9},  // F - J
        {5, 10}, // F - K
        {7, 11}  // H - L
    };

    for (int i = 0; i < 11; ++i) {
        int u = conexiones[i][0];
        int v = conexiones[i][1];
        graph.G[u].push_back(Edge(v, 1));
        graph.G[v].push_back(Edge(u, 1));
    }

    char inicioLetra, finLetra;
    cout << "=== Calcular Ruta en el Arbol ===" << endl;
    cout << "Ingrese punto de origen (A-L): ";
    cin >> inicioLetra;
    cout << "Ingrese punto de destino (A-L): ";
    cin >> finLetra;

    int inicio = inicioLetra - 'A';
    int fin = finLetra - 'A';

    if (inicio < 0 || inicio >= graph.V || fin < 0 || fin >= graph.V) {
        cout << "Error: Puntos invalidos. Usa letras de la A a la L en mayuscula." << endl;
        cout << "\nPresiona Enter para continuar...";
        limpiarBuffer();
        cin.get();
        return;
    }

    char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
    auto resultado = dijkstraCamino(inicio, fin, graph);
    if(resultado.first == -1){
        cout << "\nNo existe ruta entre " << inicioLetra << " y " << finLetra << endl;
    } else {
        cout << "\nLa distancia mas corta entre " << inicioLetra << " y " << finLetra << " es: " << resultado.first << " pasos" << endl;
        cout << "Camino: ";
        for(size_t i = 0; i < resultado.second.size(); i++){
            cout << letras[resultado.second[i]];
            if(i < resultado.second.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    cout << "\nPresiona Enter para continuar...";
    limpiarBuffer();
    cin.get();
    menu();
}

// MAIN
int main()
{
    menu();
    return 0;
}