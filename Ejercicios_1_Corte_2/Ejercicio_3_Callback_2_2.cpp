#include <iostream>
#include <limits>  // Para numeric_limits
#include <ios>     // Para streamsize
using namespace std;

// Funciones que usa el Callback
int Suma(int n1, int n2)
{
    return n1 + n2;
}

int Multiplicación(int n1, int n2)
{
    return n1 * n2;
}

int Resta(int n1, int n2)
{
    return n1 - n2;
}

// Función que realiza la operación usando Callbacks 
void performOp(int (*callback)(int, int), int x, int y)
{
    cout << callback(x, y) << endl;
}

int main() {
    int num1, num2;
    int numOps;

    // Valida que el número de operaciones usadas sea el correcto
    do {
        cout << "Bienvenido\n¿Cuántas operaciones desea realizar? (1, 2 o 3): ";
        if (!(cin >> numOps)) {
            cout << "\nComando inválido, elija entre 1, 2 o 3 operaciones: \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            numOps = -1; // Fuerza el bucle a continuar
        } else if (numOps <= 0 || numOps > 3) {
            cout << "\nComando inválido, elija entre 1, 2 o 3 operaciones: \n";
            numOps = -1; // Fuerza el bucle a continuar si está fuera del rango
        }
    } while (numOps <= 0 || numOps > 3);

    // El usuario ingresa el 1° y 2° número 
    cout << "\nIngrese el 1° número (num1): ";
    cin >> num1;
    cout << "Ingrese el 2° número (num2): ";
    cin >> num2;

    // Arreglo que incluye las operaciones de callback
    int (*operations[])(int, int) = {Suma, Multiplicación, Resta};

    // Selector de operaciones dependiendo el número de operaciones seleccionadas 
    for (int i = 0; i < numOps; ++i) {
        char Op;
        int (*selectedOp)(int, int) = nullptr;
        bool validInput = false;

        do {
            cout << "\nElija la operación " << (i + 1) << " (s para Suma, m para Multiplicación, r para Resta): ";
            cin >> Op;

            if (Op == 's' || Op == 'S') {
                selectedOp = Suma;
                validInput = true;
            } else if (Op == 'm' || Op == 'M') {
                selectedOp = Multiplicación;
                validInput = true;
            } else if (Op == 'r' || Op == 'R') {
                selectedOp = Resta;
                validInput = true;
            } else {
                cout << "Comando inválido. Por favor use 's', 'm', o 'r' para indicar las operaciones." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            }
        } while (!validInput);

        // Realiza la operación seleccionada
        cout << "Resultado de la operación " << (i + 1) << ": ";
        performOp(selectedOp, num1, num2);
    }
    return 0;
}
