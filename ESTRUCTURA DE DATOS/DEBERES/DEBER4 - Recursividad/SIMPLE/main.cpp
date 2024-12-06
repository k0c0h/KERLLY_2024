#include <iostream>
#include "Suma.h"

using namespace std;

int main() {
    int N;
    cout << "Introduce un numero: ";
    cin >> N;

    Suma sum; 
    cout << "Suma de los primeros " << N << " numeros es: " << sum.compute(N) << endl;

    return 0;
}
