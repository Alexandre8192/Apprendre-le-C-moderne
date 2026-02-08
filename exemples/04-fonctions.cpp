#include <iostream>

// Fonction simple
void afficherMessage() {
    std::cout << "Bonjour depuis une fonction!\n";
}

// Fonction avec paramètres
int addition(int a, int b) {
    return a + b;
}

// Fonction avec auto (C++14)
auto multiplication(double a, double b) {
    return a * b;
}

// Fonction constexpr (évaluation à la compilation)
constexpr int carre(int n) {
    return n * n;
}

// Fonction template
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Fonction récursive
int factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}

int main() {
    // Appel de fonction simple
    afficherMessage();
    
    // Fonction avec retour
    std::cout << "5 + 3 = " << addition(5, 3) << "\n";
    std::cout << "4.5 × 2.0 = " << multiplication(4.5, 2.0) << "\n";
    
    // Constexpr - calculé à la compilation
    constexpr auto resultat = carre(5);
    std::cout << "Carré de 5 = " << resultat << "\n";
    
    // Template
    std::cout << "Maximum(10, 20) = " << maximum(10, 20) << "\n";
    std::cout << "Maximum(3.14, 2.71) = " << maximum(3.14, 2.71) << "\n";
    
    // Récursivité
    std::cout << "5! = " << factorielle(5) << "\n";
    
    return 0;
}

/*
   * Compilation et exécution :
   * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 04-fonctions.cpp -o fonctions
   * ./fonctions
*/
