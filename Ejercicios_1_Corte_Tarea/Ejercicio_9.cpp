/*Ejercicio 9.1: Cálculo del MCD
Escribe un programa que calcule el máximo común divisor (MCD) de dos números. 
El programa debe pedir dos números al usuario y luego imprimir el MCD de ambos.
*/

#include <iostream>
#include <math.h>

int num1;
int num2;

int MCD(int num1, int num2) {
 int mcd = 1 ; // Divisor
  while (num1 % mcd == 0 && num2 % mcd == 0) {
    mcd = mcd + 1;
  }
  return mcd;

}

int main() {
  std:: cout <<"Este programa cálcula el mínimo común divisor de dos números enteros";
  std:: cout <<"\n Ingrese el 1° número : ";
  std:: cin >> num1;
  std:: cout <<"\n Ingrese el 2° número: ";
  std:: cin >> num2;
  std:: cout <<"\n El máximo común divisor es: " << MCD(num1,num2) << std::endl;
  return 0;
}