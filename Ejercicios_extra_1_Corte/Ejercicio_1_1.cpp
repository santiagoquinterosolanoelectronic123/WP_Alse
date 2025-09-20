/*Ejercicio 1.2: Rastreador de Intereses de un Préstamo
Objetivo: Aplicar operaciones con números de punto flotante y toma de decisiones.

Descripción: Imagina que trabajas en un banco y se te ha asignado la tarea de escribir una herramienta para rastrear préstamos. 
Escribe un programa que calcule el interés compuesto de un préstamo, similar al ejercicio anterior, 
pero esta vez incluye una opción para que el usuario elija si quiere un interés compuesto mensual o anual. 
Compara los resultados para ambos casos y muestra cuál opción resulta en un monto final mayor.
*/

#include <iostream>
#include <math.h>

float r  = 0.12; // Tasa de interés anual en decimal
float P; // Monto inicial
float n; // Número de veces que se aplica el interés al año
float t; // Número de año

float r_prestamo (float P,float r, float n, float t){
  float Pf = 0; // Monto final

  if (n==1){
    Pf = P * pow(1+r,t);
  }

  else{
    float nt = n * t ; //Total de veces que se aplica el interés en el periodo de tiempo
    float drn = r/n; // La tasa de interés anual dividido el número de veces que se aplica el interés al año
    Pf = P * pow(1+drn,nt);
  }

  return Pf;
}

int main() {
  char respuesta;
  float n = 1;

  std:: cout <<"Bienvenido al sistema del Banco, cargando opción de ... \n  \n Prestamo: ";
  std:: cout <<"\n Ingrese la cantidad del prestamo: ";
  std:: cin >> P;
  std:: cout <<"\n La tasa de interés anual del Banco es del: " << r * 100 << '%' ;// r es una constante definida en el programa, la cual el Banco ajustara o definira en su interfaz, revise el encabezado del programa para editar el valor predeterminado
  std:: cout <<"\n ¿Desea interés compuesto efectivo mensual (m) o anual (a) m/a ?: " ;
  std:: cin >> respuesta;

  if (respuesta != 'a' && respuesta != 'A' && respuesta != 'm' && respuesta && 'M'){
      while (respuesta != 'a' && respuesta != 'A' && respuesta != 'm' && respuesta != 'M') {

         std::cout << "\n Respuesta inválida, ingrese 'm' para intéres compuesto mensual o 'a' para interés compuesto anual: ";
         std::cin >> respuesta;
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
      }
  }

  if (respuesta == 'a' || respuesta == 'A') {
    std:: cout << "\n Ingrese el número de veces que se aplica el interés al año (n): ";
    std:: cin >> n;
        }
  std:: cout <<"\n Ingrese el número de años (t): ";
  std:: cin >> t;
  float Pf = r_prestamo(P, r, n, t);
  std:: cout <<"\n Su monto final posterior a " << t << " años " << "es (Pf): " << Pf << std::endl;
  return 0;
}
