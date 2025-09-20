<<<<<<< HEAD
/*Ejercicio 2.2: Rastreador de Distancias para Conductores de Entregas
Objetivo: Usar arreglos para almacenar datos y realizar cálculos.
Descripción: Imagina que estás construyendo una herramienta de seguimiento de entregas para una flota de conductores. 
Crea un programa donde cada conductor registre la distancia que ha recorrido en un día específico. 
Almacena los datos para 10 conductores (usa un arreglo de flotantes para representar las distancias diarias). 
Calcula la distancia promedio recorrida por todos los conductores y muestra el conductor con la distancia máxima, 
además de la distancia total recorrida por todos los conductores.
*/

#include <iostream>
#include <math.h>

int indiceMayorDistancia;
float d_my  = 0;

void d_conductores(float camiones[], int n){

   for (int i = 0; i < n; i++) {
    std::cout <<"Ingrese la distancia del camión " << i + 1 << ": ";
    std::cin >> camiones[i];
   }
}

float o_rd_conductores(float camiones[], int n, int& indiceMayorDistancia, float& d_t, float& d_prom ){
  for (int i = 0; i < n; i++) {
    d_t += camiones[i];
    if (camiones[i] > d_my) {
      d_my = camiones[i];
      indiceMayorDistancia = i;
       }
    }

  d_prom = d_t / n;

  return d_my;
}

void mostrarResultado(float camiones[], int n, int indiceMayorMagnitud, float d_t, float d_prom, float d_my) {
    std::cout << "\n\nLa distancia total recorrida por los " << n << " es : "<< d_t << "\nLa distancia promedio de los camiones es: " << d_prom << std::endl;
    std::cout << "La distancia máxima recorrida por un camión fue: " << d_my << "\nSiendo el " << indiceMayorDistancia + 1 <<" quién lo recorrió" << std::endl;
}


int main(){
   int n;
   float d_t = 0;
   float d_prom = 0;

    do {
        std::cout << "Ingrese el número de Conductores de entrega (Mínimo 1): "; // Inicia el programa
        if (!(std::cin >> n)) { // Caso en el que el comando no sea un entero positivo
            std::cout << "\nComando inválido, debe ser el número de camiones a los cuáles se le hace seguimiento: \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            n = -1; // Forzar que el bucle continúe

        } else if (n <= 1) {  // Caso en el que el comando no sea mayor a 1 elemento
            std::cout << "\n No se puede hacer seguimiento a 0 camiones, por favor ingrese otra vez el número de camiones que desea hacer seguimiento: \n";
        }

    } while (n <= 1);

    float *camiones = new float [n]; // Crea un arreglo de camiones

    d_conductores(camiones, n);

    d_my = o_rd_conductores(camiones , n, indiceMayorDistancia, d_t, d_prom);
    mostrarResultado(camiones , n, indiceMayorDistancia, d_t, d_prom, d_my);

    delete[] camiones;

    return 0;

}
=======
/*Ejercicio 2.2: Rastreador de Distancias para Conductores de Entregas
Objetivo: Usar arreglos para almacenar datos y realizar cálculos.
Descripción: Imagina que estás construyendo una herramienta de seguimiento de entregas para una flota de conductores. 
Crea un programa donde cada conductor registre la distancia que ha recorrido en un día específico. 
Almacena los datos para 10 conductores (usa un arreglo de flotantes para representar las distancias diarias). 
Calcula la distancia promedio recorrida por todos los conductores y muestra el conductor con la distancia máxima, 
además de la distancia total recorrida por todos los conductores.
*/

#include <iostream>
#include <math.h>

int indiceMayorDistancia;
float d_my  = 0;

void d_conductores(float camiones[], int n){

   for (int i = 0; i < n; i++) {
    std::cout <<"Ingrese la distancia del camión " << i + 1 << ": ";
    std::cin >> camiones[i];
   }
}

float o_rd_conductores(float camiones[], int n, int& indiceMayorDistancia, float& d_t, float& d_prom ){
  for (int i = 0; i < n; i++) {
    d_t += camiones[i];
    if (camiones[i] > d_my) {
      d_my = camiones[i];
      indiceMayorDistancia = i;
       }
    }

  d_prom = d_t / n;

  return d_my;
}

void mostrarResultado(float camiones[], int n, int indiceMayorMagnitud, float d_t, float d_prom, float d_my) {
    std::cout << "\n\nLa distancia total recorrida por los " << n << " es : "<< d_t << "\nLa distancia promedio de los camiones es: " << d_prom << std::endl;
    std::cout << "La distancia máxima recorrida por un camión fue: " << d_my << "\nSiendo el " << indiceMayorDistancia + 1 <<" quién lo recorrió" << std::endl;
}


int main(){
   int n;
   float d_t = 0;
   float d_prom = 0;

    do {
        std::cout << "Ingrese el número de Conductores de entrega (Mínimo 1): "; // Inicia el programa
        if (!(std::cin >> n)) { // Caso en el que el comando no sea un entero positivo
            std::cout << "\nComando inválido, debe ser el número de camiones a los cuáles se le hace seguimiento: \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            n = -1; // Forzar que el bucle continúe

        } else if (n <= 1) {  // Caso en el que el comando no sea mayor a 1 elemento
            std::cout << "\n No se puede hacer seguimiento a 0 camiones, por favor ingrese otra vez el número de camiones que desea hacer seguimiento: \n";
        }

    } while (n <= 1);

    float *camiones = new float [n]; // Crea un arreglo de camiones

    d_conductores(camiones, n);

    d_my = o_rd_conductores(camiones , n, indiceMayorDistancia, d_t, d_prom);
    mostrarResultado(camiones , n, indiceMayorDistancia, d_t, d_prom, d_my);

    delete[] camiones;

    return 0;

}
>>>>>>> e1b2cb59ede87c1d78953ac8672708c33753d7fb
