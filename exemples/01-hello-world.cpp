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
 * Compilation:
 * g++ -std=c++23 01-hello-world.cpp -o hello
 * 
 * Ou si std::print n'est pas disponible, utilisez:
 * g++ -std=c++20 01-hello-world.cpp -o hello
 * et remplacez std::println par std::cout
 */
