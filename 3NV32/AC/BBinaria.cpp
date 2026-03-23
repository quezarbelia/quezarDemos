#include <iostream>
using namespace std;

// Prototipo de la función
int Binaria(int*, int, int, int);

// Arreglo global de datos ordenados
int tabla[] = {
    1,   3,  12,  33,  42,  43,  44,  45,  54,  55,
    61,  63,  72,  73,  82,  83,  84,  85,  94,  95,
    101, 103, 112, 133, 142, 143, 144, 145, 154, 155,
    161, 163, 172, 173, 182, 183, 184, 185, 194, 195
};

int main() {
    int pos;
    int valor = 142; // Valor a buscar
    
    // Llamada a la función: (arreglo, valor_buscado, limite_inferior, limite_superior)
    pos = Binaria(tabla, valor, 0, sizeof(tabla)/sizeof(tabla[0]) - 1);
    
    if (pos >= 0) 
        cout << "Valor " << valor << " encontrado en posicion: " << pos << endl;
    else 
        cout << "Valor " << valor << " no encontrado" << endl;
        
    return 0;
}

// Implementación de la función recursiva
int Binaria(int* A, int dato, int inferior, int superior) {
    if (inferior > superior) {
        return -1; // Caso base: No se encontró el valor
    }

    int mitad = inferior + (superior - inferior) / 2;

    if (A[mitad] == dato) {
        return mitad; // Caso base: ¡Encontrado!
    } 
    else if (A[mitad] > dato) {
        // El valor es menor, buscamos en la mitad izquierda
        return Binaria(A, dato, inferior, mitad - 1);
    } 
    else {
        // El valor es mayor, buscamos en la mitad derecha
        return Binaria(A, dato, mitad + 1, superior);
    }
}