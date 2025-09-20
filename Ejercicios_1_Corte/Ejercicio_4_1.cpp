/*Ejercicio 4.1: Sumar los elementos de un arreglo
Escribe un programa que declare un arreglo de 5 enteros y calcule la suma de todos sus elementos.*/

#include <iostream>

int arr[] = {5, 6, 7, 8, 9};

int sum_arr(int arr[]) {
    int sum_a = 0;
    int i = 0;
    for (i = 0; i < 5; i++) {
        sum_a += arr[i];
    }
    return sum_a;
}

int main() {
    std::cout << "La suma de los elementos del arreglo es: " << sum_arr(arr) << std::endl;
    return 0;
}
