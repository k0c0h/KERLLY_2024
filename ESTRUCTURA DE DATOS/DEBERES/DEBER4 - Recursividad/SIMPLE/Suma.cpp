#include "Suma.h"

int Suma::compute(int N) {
    return sum(N);  
}

int Suma::sum(int N) {
    if (N == 0) {
        return 0;  
    }
    return N + sum(N - 1);
}
