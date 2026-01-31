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

// Tests are always included but disabled for main app via DOCTEST_CONFIG_DISABLE
#include "doctest/doctest.h"

TEST_CASE("factorial function") {
    SUBCASE("factorial of 0 is 1") {
        CHECK(factorial(0) == 1);
    }
    SUBCASE("factorial of 1 is 1") {
        CHECK(factorial(1) == 1);
    }
    SUBCASE("factorial of small numbers") {
        CHECK(factorial(2) == 2);
        CHECK(factorial(3) == 6);
        CHECK(factorial(4) == 24);
        CHECK(factorial(5) == 120);
    }
    SUBCASE("factorial of larger numbers") {
        CHECK(factorial(10) == 3628800);
        CHECK(factorial(12) == 479001600);
    }
    SUBCASE("factorial of negative numbers returns 0") {
        CHECK(factorial(-1) == 0);
        CHECK(factorial(-5) == 0);
    }
}
