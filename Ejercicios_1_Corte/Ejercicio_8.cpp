/*Ejercicio 8.1: Interés Compuesto
Escribe un programa que calcule el interés compuesto. La fórmula es la siguiente:

A=P(1+r/n)^(nt)

Donde:

A es el monto final
P es el principal (la cantidad inicial invertida)
r es la tasa de interés anual (en decimal)
n es el número de veces que se aplica el interés al año
t es el número de años
El programa debe pedir estos valores al usuario y luego imprimir el monto final.

*/

#include <iostream>
#include <math.h>

float r; // Tasa de interés anual en decimal
float P; // Monto inicial
float n; // Número de veces que se aplica el interés al año
float t; // Número de años

float interes_compuesto(float P,float r, float n, float t){
  float nt = n * t ; //Total de veces que se aplica el interés en el periodo de tiempo
  float drn = r/n; // La tasa de interés anual dividido el número de veces que se aplica el interés al año
  float A_0 = (1 + drn); // Suma entre 1 y la razón drn, lo llamamos A0
  float A_1 = pow(A_0,nt); // Elevar A0 a nt, lo llamamos A1
  float A = P * A_1; // Multiplicar P por A1, lo llamamos A
  return A;
}

int main() {
  std:: cout <<"Este programa cálcula el monto final de un interés compuesto";
  std:: cout <<"\n Ingrese el monto inicial (P): ";
  std:: cin >> P;
  std:: cout <<"Ingrese la tasa de interés anual en decimal (r): ";
  std:: cin >> r;
  std:: cout <<"Ingrese el número de veces que se aplica el interés al año (n): ";
  std:: cin >> n;
  std:: cout <<"Ingrese el número de años (t): ";
  std:: cin >> t;
  std:: cout <<"El monto final es (A): " << interes_compuesto(P,r,n,t) << std::endl;
  return 0;
}