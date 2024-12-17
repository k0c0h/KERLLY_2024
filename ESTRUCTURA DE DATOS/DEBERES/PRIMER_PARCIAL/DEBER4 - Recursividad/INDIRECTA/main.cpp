#include <iostream>
#include "IsPositive.h"
#include "IsNegative.h"

using namespace std;

int main() {
    int num1, num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    IsPositive posChecker;
    IsNegative negChecker;

    cout << num1 << " es positivo? " << (posChecker.value(num1) ? "Correcto" : "Errado") << endl;
    cout << num2 << " es negativo? " << (negChecker.value(num2) ? "Correcto" : "Errado") << endl;

    return 0;
}
