#include "Matriz.h"
#include <iostream>

int main() {
    Matriz<int> mat1(3, 3);
    Matriz<int> mat2(3, 3);

    mat1.llenarMatriz();
    mat2.llenarMatriz();

    std::cout << "Matriz 1:" << std::endl;
    mat1.mostrarMatriz();
    std::cout << std::endl;

    std::cout << "Matriz 2:" << std::endl;
    mat2.mostrarMatriz();
    std::cout << std::endl;

    int resultado = Matriz<int>::sumaRecursivaMatrices(mat1, mat2, 2, 2);
    std::cout << "Suma de matrices es: " << resultado << std::endl;

    return 0;
}
