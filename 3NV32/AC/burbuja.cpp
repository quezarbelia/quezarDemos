#include<iostream>
using namespace std;
int main ()
{
    int n, i, j, temp;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamaño debe ser un numero mayor que cero." << endl;
        return 0;
    }

    int *a = new int[n];

    cout << "Ingrese " << n << " elementos:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Lista ingresada ...\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Lista ordenada ...\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    delete[] a;
    return 0;
}