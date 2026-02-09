#include <iostream>

#if __has_include(<print>)
#include <print>  // C++23 (si disponible)
#define HAS_STD_PRINT 1
#else
#define HAS_STD_PRINT 0
#endif

int main() {
    // Utilisation de std::println (C++23) si supportée
#if HAS_STD_PRINT
    std::println("Hello, World!");
    std::println("Bienvenue dans le C++ moderne!");
#else
    // Fallback compatible C++20
    std::cout << "Hello, World!\n";
    std::cout << "Bienvenue dans le C++ moderne!\n";
#endif
    
    return 0;
}

/*
   * Compilation et exécution :
   * C++23 si std::print est disponible, sinon fallback C++20.
   * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 01-hello-world.cpp -o hello
   * ./hello
*/
