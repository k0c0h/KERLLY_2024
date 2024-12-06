#include <iostream>
#include "Caminos.h"

using namespace std;

int main() {
    int n;
    cout << "Introduce el tamanio de la malla (n x n): ";
    cin >> n;

    Caminos caminos;
    cout << "La cantidad de caminos unicos en una malla " << n << "x" << n << " es: " << caminos.calcularCaminos(n) << endl;

    return 0;
}
