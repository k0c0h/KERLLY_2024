/*#include "IsNegative.h"
#include "IsPositive.h"

bool IsNegative::value(int N) {
    if (N == 0) return false;
    return N < 0;
}
*/
#include "IsNegative.h"
#include "IsPositive.h"

bool IsNegative::value(int N) {
    if (N == 0) return false; 
    return N < 0 ? true : IsPositive().value(N + 1); 
}

