/*#include "IsPositive.h"
#include "IsNegative.h"

bool IsPositive::value(int N) {
    if (N == 0) return false;
    return N > 0;
}
*/
#include "IsPositive.h"
#include "IsNegative.h"

bool IsPositive::value(int N) {
    if (N == 0) return false;  
    return N > 0 ? true : IsNegative().value(N - 1); 
}

