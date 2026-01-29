#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <cstdint>

// Computes the factorial of n
// Returns n! for n >= 0
// Note: Will overflow for n > 20 with uint64_t
uint64_t factorial(int n);

#endif // FACTORIAL_H
