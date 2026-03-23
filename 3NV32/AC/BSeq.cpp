#include <stdio.h>
// Función que busca el entero 'b' en el arreglo 'A'
int encuentra(int A[], int b) {
    int k = 0; // Empezamos en 0 (en C los arreglos inician en 0)
    int result = -1;

    do {
        if (A[k] == b) {
            result = k;
        } else {
            k++;
        }
    } while ((result == -1) && (k < 10));

    return result;
}

int main() {
    int i, x[10], valor_buscado;

    // Leer los 10 números del arreglo
    printf("Introduce 10 numeros enteros:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &x[i]);
    }

    // Pedir el valor a buscar
    printf("Introduce el valor a buscar: ");
    scanf("%d", &valor_buscado);

    // Llamada a la función
    i = encuentra(x, valor_buscado);

    // Mostrar resultado
    if (i != -1) {
        printf("Resultado: encontrado en posicion %d\n", i);
    } else {
        printf("Resultado: -1 (no encontrado)\n");
    }
    return 0;
}