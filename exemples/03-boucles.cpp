#include <iostream>
#include <vector>

int main() {
    // Boucle for classique
    std::cout << "Nombres de 0 à 9:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";
    
    // Boucle for basée sur plage (range-based for)
    std::vector<int> nombres = {1, 2, 3, 4, 5};
    
    std::cout << "Éléments du vecteur:\n";
    for (const auto& nombre : nombres) {
        std::cout << nombre << " ";
    }
    std::cout << "\n\n";
    
    // Modification des éléments
    std::cout << "Doubler chaque élément:\n";
    for (auto& nombre : nombres) {
        nombre *= 2;
    }
    
    for (const auto& nombre : nombres) {
        std::cout << nombre << " ";
    }
    std::cout << "\n\n";
    
    // Boucle while
    std::cout << "Countdown:\n";
    int compte = 5;
    while (compte > 0) {
        std::cout << compte << "... ";
        --compte;
    }
    std::cout << "Décollage! 🚀\n";
    
    return 0;
}

/*
   * Compilation et exécution :
   * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 03-boucles.cpp -o boucles
   * ./boucles
*/
