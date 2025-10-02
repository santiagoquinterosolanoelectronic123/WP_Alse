#include <iostream>
#include <limits>  // Para numeric_limits
#include <ios>     // Para streamsize
#include <vector>  // Para vector

using namespace std;

class TwoSum_Target {
private:
    int num_t;
    vector<int> answer_g; // Use vector for automatic memory management

public:
    TwoSum_Target() : answer_g(2) {} // Initialize vector with size 2
    ~TwoSum_Target() {} // Destructor (no manual deletion needed with vector)

    void set_num_t(int num) {
        num_t = num;
    }

    int* Target(int arc_int[], int l, int num_t) {
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if (arc_int[i] + arc_int[j] == num_t) {
                    answer_g[0] = i;
                    answer_g[1] = j;
                    return answer_g.data(); // Return pointer to vector data
                }
            }
        }
        return nullptr; // Return nullptr if no solution (though problem guarantees one)
    }
};

void array_int(int ar_int[], int l) {
    for (int i = 0; i < l; i++) {
        bool validInput = false;
        do {
            cout << "Ingrese el número entero de la posición " << i << ": ";
            if (cin >> ar_int[i]) {
                validInput = true; // Entrada válida
            } else {
                cout << "Comando inválido, debe ingresar un número entero como elemento de la lista" << endl;
                cin.clear(); // Restablece el estado de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            }
        } while (!validInput);
    }
}

int main() {
    TwoSum_Target sum_1;
    int sn1 = 0;
    int l = 0;
    int* arc_int = nullptr; // Initialize to nullptr

    do {
        cout << "Ingrese el tamaño de la lista de números enteros: ";
        if (!(cin >> l)) {
            cout << "\nComando inválido, debe ser la cantidad de números que compone la lista: \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ahora funciona con las inclusiones
            l = -1; // Force loop to continue
        } else if (l <= 2) {
            cout << "\nLa lista debe ser de al menos 2 números para funcionar:\n";
        }
    } while (l <= 1);

    // Allocate array after validating l
    arc_int = new int[l];
    array_int(arc_int, l);

    cout << "Ingrese el número deseado producto de la suma de dos números de la lista ingresada: ";
    cin >> sn1;
    sum_1.set_num_t(sn1);

    int* answer = sum_1.Target(arc_int, l, sn1);
    if (answer) {
        cout << "La posición en la lista de los dos números respectivamente es " << answer[0] << " y " << answer[1] << endl;
    } else {
        cout << "No se encontró una solución." << endl; // Though problem guarantees one
    }

    // Free allocated memory
    delete[] arc_int;

    return 0;
}
