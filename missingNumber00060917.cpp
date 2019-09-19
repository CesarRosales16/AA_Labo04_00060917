/* 
 * File:   missingNumber00060917.cpp
 * Author: Cesar
 *
 * Created on 15 de septiembre de 2019, 10:02 PM
 */

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Esta función toma el último elemento como pivote, lo coloca en su posición
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    for (int j = low; j <= high - 1; j++) {
        // Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot) {
            i++; // incrementar el index del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* La función principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> límite inicial,
high --> límite final */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la
        // partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Función para imprimir arreglo */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int minMultipleNumber(int num, int base) {
    if (num % base == 0) return num;
    return num - 1;
}

int main() {
    int T, N, num, i, j, res = 0;
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> N;
        int A[N];
        for (j = 0; j < N; j++) {
            cin >> num;
            A[j] = (num == 0 ? num : (num - 1));
        }
        quickSort(A, 0, N - 1);
        for (j = 0; j < N; j++) {
            A[j] = minMultipleNumber(A[j], 2);
        }
        //printArray(A, N);
        res = 0;
        for (j = 0; j < N; j++) {
            if (A[j] <= res && A[j + 1] != res) res += 2;
        }
        cout << res << endl;
    }
    return 0;
}