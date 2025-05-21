#include <iostream>
#include <vector>
using namespace std;

// Función para mezclar dos subarreglos ordenados
void mezclar(vector<int>& arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Arreglos temporales
    vector<int> izquierda(n1), derecha(n2);

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izquierda[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = arr[medio + 1 + j];

    // Mezclar los arreglos temporales de vuelta al arreglo original
    int i = 0, j = 0, k = inicio;
    
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de izquierda[] si los hay
    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de derecha[] si los hay
    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

// Función principal de MergeSort
void ordenamientoMezcla(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Ordenar primero y segundo subarreglos
        ordenamientoMezcla(arr, inicio, medio);
        ordenamientoMezcla(arr, medio + 1, fin);

        // Mezclar los subarreglos ordenados
        mezclar(arr, inicio, medio, fin);
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> datos = {12, 11, 13, 5, 6, 7};
    int n = datos.size();
    
    cout << "Arreglo original: ";
    imprimirArreglo(datos);

    ordenamientoMezcla(datos, 0, n - 1);

    cout << "Arreglo ordenado: ";
    imprimirArreglo(datos);
    
    return 0;
}
