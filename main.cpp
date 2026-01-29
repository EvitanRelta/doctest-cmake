#include <iostream>
#include "factorial.h"

int main() {
    std::cout << "Factorial Calculator\n";
    std::cout << "====================\n";
    
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << factorial(i) << "\n";
    }
    
    return 0;
}
