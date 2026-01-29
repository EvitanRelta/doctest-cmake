#include "factorial.h"

uint64_t factorial(int n) {
    if (n < 0) {
        return 0; // Undefined for negative numbers, return 0
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    uint64_t result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
