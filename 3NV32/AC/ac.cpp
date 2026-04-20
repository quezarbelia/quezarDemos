#include <iostream>
#include <iomanip>

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

void burbuja(){
    std::cout << "\n*** Metodo de ordenacion por burbuja ***\n" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    mA(arr, n, "Arreglo original: ");
    
    // Algoritmo de burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\nPresiona Enter para volver al menu...";
    std::cin.ignore();
}

void insercion(){
    std::cout << "\n*** Algoritmo de ordenacion por insercion ***\n" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    mA(arr, n, "Arreglo original: ");
    
    // Algoritmo de inserción
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\nPresiona Enter para volver al menu...";
    std::cin.ignore();
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    
    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void rapida(){
    std::cout << "\n*** Algoritmo de ordenacion rapida (QuickSort) ***\n" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    mA(arr, n, "Arreglo original: ");
    
    quickSort(arr, 0, n - 1);
    
    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\nPresiona Enter para volver al menu...";
    std::cin.ignore();
}

void shell(){
    std::cout << "\n*** Algoritmo de ordenacion Shell ***\n" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    mA(arr, n, "Arreglo original: ");
    
    // Algoritmo Shell Sort
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    
    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\nPresiona Enter para volver al menu...";
    std::cin.ignore();
}

void heapify(int arr[], int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    
    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;
    
    if (der < n && arr[der] > arr[mayor])
        mayor = der;
    
    if (mayor != i) {
        int temp = arr[i];
        arr[i] = arr[mayor];
        arr[mayor] = temp;
        heapify(arr, n, mayor);
    }
}

void monticulo(){
    std::cout << "\n*** Algoritmo de ordenacion de monticulo (HeapSort) ***\n" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    mA(arr, n, "Arreglo original: ");
    
    // Construir heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extraer elementos del heap uno a uno
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
    
    mA(arr, n, "Arreglo ordenado: ");
    std::cout << "\nPresiona Enter para volver al menu...";
    std::cin.ignore();
}

int main() {
    int opcion;
    bool salir = false;
    
    while (!salir) {
        menu();
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
                burbuja();
                break;
            case 2:
                insercion();
                break;
            case 3:
                rapida();
                break;
            case 4:
                shell();
                break;
            case 5:
                monticulo();
                break;
            case 6:
                std::cout << "\n¡Hasta luego! Programa finalizado." << std::endl;
                salir = true;
                break;
            default:
                std::cout << "\nOpcion invalida. Intenta nuevamente." << std::endl;
                break;
        }
    }
    
    return 0;
}   
