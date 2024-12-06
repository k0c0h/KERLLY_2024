#include <iostream>
#include "Fibonacci.h"

using namespace std;

int main() {
    int N;
    cout << "Introduce un numero: ";
    cin >> N;

    Fibonacci fib;
    cout << "El numero de Fibonacci en la posicion " << N << " es: " << fib.compute(N) << endl;

    return 0;
}
