# include <iostream>
#include <vector>

class PascalTriangle {
private:
    int numRows; // Número de filas
    std::vector<std::vector<int>> triangle; // Vector que almacena los valores del triángulo

    void generate_Triangle() {   // Método para generar el triángulo de pascal
        triangle.clear();
        for (int i = 0; i < numRows; i++) {
            std::vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1); // El primer y último elemento son 1
                }
                else {
                    int value = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Elemento n es igual a la suma de los elementos n-1 y n de la fila anterior
                    row.push_back(value);
                }
            }
            triangle.push_back(row);
        }
    }

public:
    PascalTriangle(int rows) : numRows(rows) { // Método constructor, recibe un número entero, que representa las filas
        if (numRows >= 0) {
            generate_Triangle();
        }
    }

    std::vector<std::vector<int>> getTriangle() const { // Método obtener el triángulo del objeto creado
        return triangle;
    }
};

int main() {
    int numRows = 0;
    std::cout << "Ingrese el número de filas deseado para el triángulo de Pascal: ";
    std::cin >> numRows;
    PascalTriangle s_triangle(numRows); // Crea el objeto llamado s_triangle de clase PascalTriangle
    std::vector<std::vector<int>> result = s_triangle.getTriangle(); // Obtiene el triángulo de Pascal con el número de filas dado por el usuario

    std::cout << "Triángulo de Páscal con " << numRows << " filas:" << std::endl;
    for (const auto& row : result) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
