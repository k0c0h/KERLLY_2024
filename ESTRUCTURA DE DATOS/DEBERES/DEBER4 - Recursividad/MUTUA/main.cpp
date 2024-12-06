#include <iostream>
#include "SumaDigitos.h"

using namespace std;

int main() {
    int numero;
    cout << "Introduce un numero que contenga de 1 a mas digitos: ";
    cin >> numero;

    SumaDigitos suma;
    cout << "La suma de los digitos de " << numero << " es: " << suma.sumar(numero) << endl;

    return 0;
}
