#include <iostream>
#include <string>

using namespace std;

// Estructura para el nodo de la lista enlazada
struct Nodo {
    string curp;
    Nodo* siguiente;
};

// Función recursiva para agregar un CURP al final de la lista
Nodo* agregarRecursivo(Nodo* cabeza, string nuevoCurp) {
    if (cabeza == nullptr) {
        // Si la lista está vacía, crear un nuevo nodo
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->curp = nuevoCurp;
        nuevoNodo->siguiente = nullptr;
        return nuevoNodo;
    } else {
        // Llamada recursiva para llegar al final
        cabeza->siguiente = agregarRecursivo(cabeza->siguiente, nuevoCurp);
        return cabeza;
    }
}

// Función recursiva para eliminar un CURP de la lista
Nodo* eliminarRecursivo(Nodo* cabeza, string curpAEliminar) {
    if (cabeza == nullptr) {
        // CURP no encontrado
        cout << "CURP no encontrado: " << curpAEliminar << endl;
        return nullptr;
    }
    if (cabeza->curp == curpAEliminar) {
        // Encontrado, eliminar este nodo
        Nodo* temp = cabeza->siguiente;
        delete cabeza;
        cout << "CURP eliminado: " << curpAEliminar << endl;
        return temp;
    } else {
        // Llamada recursiva para el siguiente nodo
        cabeza->siguiente = eliminarRecursivo(cabeza->siguiente, curpAEliminar);
        return cabeza;
    }
}

// Función recursiva para mostrar la lista de CURP
void mostrarRecursivo(Nodo* cabeza) {
    if (cabeza == nullptr) {
        return;
    }
    cout << cabeza->curp << endl;
    mostrarRecursivo(cabeza->siguiente);
}

// Función para liberar la memoria recursivamente
void liberarMemoria(Nodo* cabeza) {
    if (cabeza == nullptr) {
        return;
    }
    liberarMemoria(cabeza->siguiente);
    delete cabeza;
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion;
    string curp;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar CURP" << endl;
        cout << "2. Eliminar CURP" << endl;
        cout << "3. Mostrar CURP" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el CURP a agregar: ";
                cin >> curp;
                cabeza = agregarRecursivo(cabeza, curp);
                break;
            case 2:
                cout << "Ingrese el CURP a eliminar: ";
                cin >> curp;
                cabeza = eliminarRecursivo(cabeza, curp);
                break;
            case 3:
                cout << "Lista de CURP:" << endl;
                mostrarRecursivo(cabeza);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    // Liberar memoria antes de salir
    liberarMemoria(cabeza);

    return 0;
}