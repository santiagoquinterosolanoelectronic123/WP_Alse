#include <iostream>
#include <vector>
#include <random>  // Para generar números aleatorios
#include <limits>  // Para numeric_limits
#include <ios>     // Para streamsize

class Profit_predict {
public:
    int maxProfit(std::vector<int>& prices, int& buyDay, int& sellDay) {
        buyDay = 0; // Inicializa el día de compra en 0
        sellDay = 0; // Inicializa el día de venta en 0
        int maxProfit = 0; // Inicia la variable maxProfit en 0

        int minPrice = prices[0]; // Inicia el valor minPrice con el precio del primer día
        int currentBuyDay = 0;    // Inicia el valor de currentBuyDat (Día de compra actual inicializado) en 0

        for (int i = 1; i < prices.size(); i++) { // Actualiza el valor minPrice si el siguiente valor en el mercado es menor que el valor actual de minprice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                currentBuyDay = i; // Actualiza el día de compra (con el valor de la posición)
            }

            int currentProfit = prices[i] - minPrice; // Actualiza maxProfit si el precio de venta da más ganancia (es mayor) que maxProfit
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
                sellDay = i + 1; // Día de venta (Para visualización en la terminal)
                buyDay = currentBuyDay + 1; // Día de compra (Para visualización en la terminal)
            }
        }

        return maxProfit;
    }
};

int main() {
    Profit_predict user_profit; // Crea el objeto user_profit
    int n; // Crea la variable entera n que representa los días
    int buyDay = 0; // Crea la variable entera buyDay
    int sellDay = 0; // Crea la variable entera sellDay

    do {  // Bucle para confirmar entrada correcta
        std::cout << "Ingrese el número de días a considerar para la máxima ganancia: " << std::endl;
        if (!(std::cin >> n)) { // Detecta entrada no numérica (letras, símbolos, etc.)
            std::cout << "\nComando inválido, por favor ingrese un número entero positivo mayor o igual a 2, que representa el número de días" << std::endl;
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
            n = -1; // Fuerza el bucle a continuar
        } else if (n < 2) { // Entrada numérica pero inválida (menor a 2)
            std::cout << "\nComando inválido, por favor ingrese un número entero positivo mayor o igual a 2, que representa el número de días" << std::endl;
            n = -1; // Fuerza el bucle a continuar
        }
    } while (n < 2);

    std::vector<int> prices(n); // Genera un vector de precios con tamaño respectivo del número de días ingresado por el usuario.
    std::random_device rd;  // Seed para random
    std::mt19937 gen(rd()); // Generador de números aleatorios
    std::uniform_int_distribution<int> dis(0, 9); // Distribución uniforme de 0 a 9

    std::cout << "\nPrecios generados para los " << n << " días (simulando mercado):" << std::endl;
    for (int i = 0; i < n; i++) {
        prices[i] = dis(gen);  // Asigna un número random al día correspondiente en el que se encuentra
        std::cout << "Día " << i + 1 << ": " << prices[i] << std::endl; // Visualización para el usuario en la terminal
    }

    int profit = user_profit.maxProfit(prices, buyDay, sellDay);
    if (profit > 0) {
        std::cout << "\nLa máxima ganancia según los valores del mercado es: " << profit
                  << ". Comprando en el día " << buyDay << " y vendiendo en el día " << sellDay << std::endl;
    } else {
        std::cout << "\nNo se puede obtener ganancia con estos valores del mercado." << std::endl;
    }

    return 0;
}
