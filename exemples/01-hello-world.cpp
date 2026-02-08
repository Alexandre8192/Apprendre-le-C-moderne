#include <iostream>
#include <print>  // C++23

int main() {
    // Utilisation de std::println (C++23)
    std::println("Hello, World!");
    std::println("Bienvenue dans le C++ moderne!");
    
    // Alternative C++20
    std::cout << "Hello avec cout\n";
    
    return 0;
}

/*
   * Compilation et exécution :
   * Requiert C++23 (std::println).
   * g++ -std=c++23 -Wall -Wextra -Wpedantic -O2 01-hello-world.cpp -o hello
   * ./hello
*/
