#include <iostream>
using namespace std;

// Función recursiva para calcular edad
int calcularEdad(int nacimiento, int actual) {
    if (nacimiento == actual) {
        return 0; // caso base
    } else {
        return 1 + calcularEdad(nacimiento + 1, actual);
    }
}

int main() {
    int nacimiento, actual;

    cout << "Anio de nacimiento: ";
    cin >> nacimiento;

    cout << "Anio actual: ";
    cin >> actual;

    cout << "Tu edad es: " << calcularEdad(nacimiento, actual);

    return 0;
}