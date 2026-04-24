#include <cstdlib>
#include <iostream>

// Declaraciones forward
void bus(int arr[], int n);
void busquedaBinaria(int arr[], int n);
void busquedaSecuencial(int arr[], int n);

// Función para mostrar el arreglo
void mA(int arr[], int n, const char *titulo) {
  std::cout << titulo;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void menu() {

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
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = arr_orig[i];

  int movimientos = 0;
  int comparaciones = 0;

  std::cout << "\n===== Metodo de ordenacion por burbuja =====\n";
  mA(arr, n, "Arreglo original: ");

  // Algoritmo simplificado
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      comparaciones++;
      if (arr[j] > arr[j + 1]) {
        // Intercambio
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        movimientos++;
      }
    }
  }

  mA(arr, n, "Arreglo ordenado: ");
  std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
  std::cout << "\n--> Movimientos (intercambios): " << movimientos << std::endl;

  bus(arr, n);

  std::cout << "\nPresiona una tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void insercion(int arr_orig[], int n) {
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = arr_orig[i];

  int movimientos = 0;
  int comparaciones = 0;

  std::cout << "\n*** Algoritmo de ordenacion por insercion ***\n";
  mA(arr, n, "Arreglo original: ");

  for (int i = 1; i < n; i++) {
    int llave = arr[i];
    int j = i - 1;

    while (j >= 0) {
      comparaciones++;
      if (arr[j] > llave) {
        arr[j + 1] = arr[j];
        j--;
        movimientos++;
      } else {
        break;
      }
    }
    arr[j + 1] = llave;
  }

  mA(arr, n, "Arreglo ordenado: ");
  std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
  std::cout << "\n--> Movimientos (desplazamientos): " << movimientos
            << std::endl;

  bus(arr, n);

  std::cout << "\nPresiona una tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void rapida(int arr_orig[], int n) {
  // Copia del arreglo
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = arr_orig[i];

  int comparaciones = 0;
  int movimientos = 0;

  int pila[n];
  int tope = -1;

  pila[++tope] = 0;
  pila[++tope] = n - 1;

  std::cout << "\n*** Algoritmo de ordenacion rapida (QuickSort) ***\n";
  mA(arr, n, "Arreglo original: ");

  while (tope >= 0) {
    int alto = pila[tope--];
    int bajo = pila[tope--];

    // Particion manual
    int pivote = arr[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
      comparaciones++;
      if (arr[j] < pivote) {
        i++;
        // Intercambio
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        movimientos++;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    movimientos++;

    int p = i + 1;

    if (p - 1 > bajo) {
      pila[++tope] = bajo;
      pila[++tope] = p - 1;
    }

    if (p + 1 < alto) {
      pila[++tope] = p + 1;
      pila[++tope] = alto;
    }
  }

  mA(arr, n, "Arreglo ordenado: ");
  std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
  std::cout << "\n--> Movimientos (intercambios): " << movimientos << std::endl;

  bus(arr, n);

  std::cout << "\nPresiona una tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void bus(int arr[], int n) {
  int opcBusqueda;

  std::cout << "\n========================================" << std::endl;
  std::cout << "          MODULO DE BUSQUEDA" << std::endl;
  std::cout << "========================================" << std::endl;
  std::cout << "El arreglo esta ordenado. Que desea hacer?" << std::endl;
  std::cout << "1. Busqueda Binaria (Eficiente)" << std::endl;
  std::cout << "2. Busqueda Secuencial (Lineal)" << std::endl;
  std::cout << "3. Omitir busqueda y regresar al menu" << std::endl;
  std::cout << "Seleccione una opcion: ";
  std::cin >> opcBusqueda;

  switch (opcBusqueda) {
  case 1:
    busquedaBinaria(arr, n);
    break;
  case 2:
    busquedaSecuencial(arr, n);
    break;
  case 3:
    std::cout << "Regresando al menu principal..." << std::endl;
    break;
  default:
    std::cout << "Opcion no valida." << std::endl;
    break;
  }
}

void shell(int arr_orig[], int n) {
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = arr_orig[i];

  int comparaciones = 0;
  int movimientos = 0;

  std::cout << "\n*** Algoritmo de ordenacion Shell ***\n";
  mA(arr, n, "Arreglo original: ");

  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;

      for (j = i; j >= gap; j -= gap) {
        comparaciones++;
        if (arr[j - gap] > temp) {
          arr[j] = arr[j - gap];
          movimientos++;
        } else {
          break;
        }
      }
      arr[j] = temp;

      if (j != i)
        movimientos++;
    }
  }

  mA(arr, n, "Arreglo ordenado: ");
  std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
  std::cout << "\n--> Movimientos (desplazamientos): " << movimientos
            << std::endl;

  bus(arr, n);

  std::cout << "\nPresiona una tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void monticulo(int arr_orig[], int n) {
  // Copia del arreglo
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = arr_orig[i];

  int comparaciones = 0;
  int movimientos = 0;

  std::cout << "\n*** Algoritmo de ordenacion de monticulo (HeapSort) ***\n";
  mA(arr, n, "Arreglo original: ");

  for (int i = 1; i < n; i++) {
    int hijo = i;
    while (hijo > 0) {
      int padre = (hijo - 1) / 2;
      comparaciones++;
      if (arr[hijo] > arr[padre]) {
        // Intercambio
        int temp = arr[hijo];
        arr[hijo] = arr[padre];
        arr[padre] = temp;
        movimientos++;
        hijo = padre;
      } else {
        break;
      }
    }
  }

  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    movimientos++;

    int padre = 0;
    int hijo;
    while (true) {
      hijo = 2 * padre + 1;
      if (hijo >= i)
        break;

      if (hijo + 1 < i) {
        comparaciones++;
        if (arr[hijo + 1] > arr[hijo]) {
          hijo++;
        }
      }

      comparaciones++;
      if (arr[hijo] > arr[padre]) {
        int aux = arr[padre];
        arr[padre] = arr[hijo];
        arr[hijo] = aux;
        movimientos++;
        padre = hijo;
      } else {
        break;
      }
    }
  }

  mA(arr, n, "Arreglo ordenado: ");
  std::cout << "\n--> Comparaciones realizadas: " << comparaciones;
  std::cout << "\n--> Movimientos (intercambios): " << movimientos << std::endl;

  bus(arr, n);

  std::cout << "\nPresiona una tecla para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void busquedaBinaria(int arr[], int n) {
  int dato, inferior = 0, superior = n - 1, mitad;
  bool encontrado = false;
  int comparaciones = 0;

  std::cout << "\n--- BUSQUEDA BINARIA ---" << std::endl;
  std::cout << "Ingrese el valor a buscar en el arreglo ordenado: ";
  std::cin >> dato;

  // Algoritmo de Búsqueda Binaria
  while (inferior <= superior) {
    comparaciones++;
    mitad = inferior + (superior - inferior) / 2;

    if (arr[mitad] == dato) {
      encontrado = true;
      break;
    }

    if (arr[mitad] < dato) {
      inferior = mitad + 1; // Buscar en la mitad derecha
    } else {
      superior = mitad - 1; // Buscar en la mitad izquierda
    }
  }

  if (encontrado) {
    std::cout << "-> Elemento " << dato
              << " encontrado en la posicion: " << mitad << std::endl;
  } else {
    std::cout << "-> Elemento " << dato << " no existe en el arreglo."
              << std::endl;
  }

  std::cout << "-> Comparaciones realizadas en busqueda: " << comparaciones
            << std::endl;
}

void busquedaSecuencial(int arr[], int n) {
  int dato;
  bool encontrado = false;
  int comparaciones = 0;

  std::cout << "\n--- BUSQUEDA SECUENCIAL ---" << std::endl;
  std::cout << "Ingrese el valor a buscar: ";
  std::cin >> dato;

  for (int i = 0; i < n; i++) {
    comparaciones++;
    if (arr[i] == dato) {
      std::cout << "-> Elemento " << dato << " encontrado en la posicion: " << i
                << std::endl;
      encontrado = true;
      break;
    }
  }

  if (!encontrado) {
    std::cout << "-> Elemento " << dato << " no existe en el arreglo."
              << std::endl;
  }
  std::cout << "-> Comparaciones realizadas en busqueda: " << comparaciones
            << std::endl;
}

int main() {
  int opcion;

  while (true) {
    std::cout << "\n--- CONFIGURACION DEL ARREGLO ---" << std::endl;
    std::cout << "Ingresa el tamanio del arreglo (o 0 para salir): ";
    int n;
    std::cin >> n;
    if (n <= 0) {
      std::cout << "Saliendo..." << std::endl;
      break;
    }

    int *miArreglo = new int[n];
    std::cout << "Ingresa los " << n << " elementos del arreglo: ";
    for (int i = 0; i < n; i++) {
      std::cin >> miArreglo[i];
    }

    menu();
    std::cin >> opcion;

    if (opcion == 6) {
      delete[] miArreglo;
      std::cout << "Saliendo..." << std::endl;
      break;
    }

    switch (opcion) {
    case 1:
      burbuja(miArreglo, n);
      break;
    case 2:
      insercion(miArreglo, n);
      break;
    case 3:
      rapida(miArreglo, n);
      break;
    case 4:
      shell(miArreglo, n);
      break;
    case 5:
      monticulo(miArreglo, n);
      break;
    default:
      std::cout << "Opcion no implementada o invalida." << std::endl;
      break;
    }

    delete[] miArreglo;

    std::cout << "\nArreglo procesado. Reiniciando para una nueva entrada...\n";
  }

  return 0;
}