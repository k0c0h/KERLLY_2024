#include "Factorial.h"

int Factorial::value(int N) {
    return factorial(N, 1);
}

int Factorial::factorial(int N, int result) {
    if (N == 0) 
        return result;
    return factorial(N - 1, N * result); 
}
