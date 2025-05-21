#include <iostream>
#include <vector>
using namespace std;

// Función para intercambiar dos elementos
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función que toma el último elemento como pivote, lo coloca en su posición correcta
// y coloca los menores a la izquierda y mayores a la derecha
int particionar(vector<int>& arr, int inicio, int fin) {
    int pivote = arr[fin]; // pivote
    int i = (inicio - 1);  // Índice del elemento más pequeño

    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (arr[j] < pivote) {
            i++; // incrementamos el índice del menor elemento
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[fin]);
    return (i + 1);
}

// Función principal de QuickSort
void ordenamientoRapido(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) {
        // pi es el índice de partición
        int pi = particionar(arr, inicio, fin);

        // Ordenar recursivamente los subarreglos
        ordenamientoRapido(arr, inicio, pi - 1);
        ordenamientoRapido(arr, pi + 1, fin);
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
    vector<int> datos = {10, 7, 8, 9, 1, 5};
    int n = datos.size();
    
    cout << "Arreglo original: ";
    imprimirArreglo(datos);

    ordenamientoRapido(datos, 0, n - 1);

    cout << "Arreglo ordenado: ";
    imprimirArreglo(datos);
    
    return 0;
}
