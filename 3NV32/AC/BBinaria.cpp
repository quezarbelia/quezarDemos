#include <iostream>
#include <cstdio>
using namespace std;

// Prototipo
int busquedaBinaria(const int*, int, int, int, int);

int main() {
    // Arreglo local (no global)
    const int tabla[] = {
        1, 3, 12, 33, 42, 43, 44, 45, 54, 55,
        61, 63, 72, 73, 82, 83, 84, 85, 94, 95,
        101, 103, 112, 133, 142, 143, 144, 145, 154, 155,
        161, 163, 172, 173, 182, 183, 184, 185, 194, 195
    };
    
    const int tamaño = sizeof(tabla) / sizeof(tabla[0]);
    int valor;
    
    // Validación de entrada
    cout << "Ingrese el valor a buscar: ";
    if (!(cin >> valor)) {
        cerr << "Error: entrada invalida" << endl;
        return 1;
    }
    
    int pos = busquedaBinaria(tabla, valor, 0, tamaño - 1, tamaño);
    
    cout << (pos >= 0 ? "Valor " + to_string(valor) + " encontrado en posicion: " + to_string(pos)
                      : "Valor " + to_string(valor) + " no encontrado") << endl;
    
    return 0;
}

int busquedaBinaria(const int* arr, int dato, int inferior, int superior, int n) {
    if (inferior > superior) return -1;
    
    int mitad = inferior + (superior - inferior) / 2;
    
    if (arr[mitad] == dato) return mitad;
    return arr[mitad] > dato ? busquedaBinaria(arr, dato, inferior, mitad - 1, n)
                             : busquedaBinaria(arr, dato, mitad + 1, superior, n);
}