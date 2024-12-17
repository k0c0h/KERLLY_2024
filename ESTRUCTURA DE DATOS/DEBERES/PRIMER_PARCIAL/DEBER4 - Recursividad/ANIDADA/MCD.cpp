#include "MCD.h"

int MCD::mcd(int a, int b) {
    return gcd(a, b);  // Inicia la recursividad anidada
}

int MCD::gcd(int a, int b) {
    if (b == 0) {
        return a;  // Caso base: el MCD de a y 0 es a
    } else {
        return gcd(b, a % b);  // Recursividad anidada: se llama a la función de nuevo
    }
}
