#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nombres = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Lambda simple
    std::cout << "=== Lambda de base ===\n";
    auto afficher = [](int n) {
        std::cout << n << " ";
    };
    
    std::for_each(nombres.begin(), nombres.end(), afficher);
    std::cout << "\n\n";
    
    // Lambda avec capture
    std::cout << "=== Lambda avec capture ===\n";
    int multiplicateur = 2;
    
    auto multiplier = [multiplicateur](int n) {
        return n * multiplicateur;
    };
    
    for (int n : nombres) {
        std::cout << multiplier(n) << " ";
    }
    std::cout << "\n\n";
    
    // Lambda avec capture par référence
    std::cout << "=== Lambda modifiant une variable ===\n";
    int somme = 0;
    
    auto ajouter = [&somme](int n) {
        somme += n;
    };
    
    std::for_each(nombres.begin(), nombres.end(), ajouter);
    std::cout << "Somme totale: " << somme << "\n\n";
    
    // Lambda générique (C++14)
    std::cout << "=== Lambda générique ===\n";
    auto maximum = [](auto a, auto b) {
        return (a > b) ? a : b;
    };
    
    std::cout << "Max(10, 20) = " << maximum(10, 20) << "\n";
    std::cout << "Max(3.14, 2.71) = " << maximum(3.14, 2.71) << "\n\n";
    
    // Utilisation avec std::sort
    std::cout << "=== Tri avec lambda ===\n";
    std::vector<int> nums = {5, 2, 8, 1, 9, 3};
    
    std::cout << "Avant tri: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";
    
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;  // Tri décroissant
    });
    
    std::cout << "Après tri décroissant: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";
    
    return 0;
}

/*
 * Compilation:
 * g++ -std=c++20 06-lambdas.cpp -o lambdas
 * ./lambdas
 */
