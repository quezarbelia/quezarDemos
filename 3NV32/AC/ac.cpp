#include <iostream>
#include <cstdlib>

// Función para mostrar el arreglo
void mA(int arr[], int n, const char* titulo) {
    std::cout << titulo;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void menu(){

    std::cout << "\n====== M E N U ======" << std::endl;
    std::cout << "Quezada Avila Gabriel" << std::endl;
    std::cout << "1) Metodo Burbuja" << std::endl;
    std::cout << "2) Algoritmo de ordenacion por insercion" << std::endl;
    std::cout << "3) Algoritmo por ordenacion rapida" << std::endl;
    std::cout << "4) Algoritmo de ordenacion Shell" << std::endl;
    std::cout << "5) Algoritmo de ordenacion de monticulo" << std::endl;
    std::cout << "6) Salir del programa" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Selecciona una opcion: ";
}

void burbuja(int arr_orig[], int n) {
    // Creamos una copia para no alterar el original del main permanentemente
    int arr[n];
    for(int i=0; i<n; i++) arr[i] = arr_orig[i];

    int movimientos = 0;
    int comparaciones = 0;

    std::cout << "\n*** Metodo de ordenacion por burbuja ***\n";
    mA(arr, n, "Arreglo original: ");

    // Algoritmo simplificado
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++; // Cada vez que comparamos dos números
            if (arr[j] > arr[j + 1]) {
                // Intercambio
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                movimientos++; // Cada vez que movemos un número
            }
        }
    }

    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
    std::cout << "\n--> Movimientos (intercambios): " << movimientos << std::endl;
    
    std::cout << "\nPresiona una tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    // El arreglo que vas a probar
    int miArreglo[] = {2, 25, 14, 7, 20, 16, 70};
    int n = sizeof(miArreglo) / sizeof(miArreglo[0]);
    int opcion;

    while (true) {
        menu();
        std::cin >> opcion;

        if (opcion == 6) {
            std::cout << "Saliendo..." << std::endl;
            break;
        }

        switch (opcion) {
            case 1:
                burbuja(miArreglo, n);
                break;
            default:
                std::cout << "Opcion no implementada o invalida." << std::endl;
                break;
        }
        std::system("cls");
    }
    return 0;
}