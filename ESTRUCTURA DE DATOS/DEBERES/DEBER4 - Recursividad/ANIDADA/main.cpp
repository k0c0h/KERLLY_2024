#include <iostream>
#include "MCD.h"

using namespace std;

int main() {
    int a, b;
    cout << "Introduce el primer numero: ";
    cin >> a;

    cout << "Introduce el segundo numero: ";
    cin >> b;

    MCD mcdCalculator;
    cout << "El maximo comUn divisor de " << a << " y " << b << " es: " << mcdCalculator.mcd(a, b) << endl;

    return 0;
}
