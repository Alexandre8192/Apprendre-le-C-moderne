#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <string>

int main() {
    std::cout << "=== Démonstration des Conteneurs STL ===\n\n";
    
    // ========== VECTOR ==========
    std::cout << "--- std::vector (tableau dynamique) ---\n";
    std::vector<int> nombres = {10, 20, 30, 40, 50};
    
    nombres.push_back(60);
    nombres.push_back(70);
    
    std::cout << "Éléments du vector: ";
    for (int n : nombres) {
        std::cout << n << " ";
    }
    std::cout << "\nTaille: " << nombres.size() << "\n";
    std::cout << "Premier: " << nombres.front() << ", Dernier: " << nombres.back() << "\n";
    
    // ========== MAP ==========
    std::cout << "\n--- std::map (dictionnaire trié) ---\n";
    std::map<std::string, int> ages;
    
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 22;
    ages["Diana"] = 28;
    
    std::cout << "Âges (triés par nom):\n";
    for (const auto& [nom, age] : ages) {
        std::cout << "  " << nom << ": " << age << " ans\n";
    }
    
    // Recherche
    std::string recherche = "Bob";
    if (ages.find(recherche) != ages.end()) {
        std::cout << "Âge de " << recherche << ": " << ages[recherche] << "\n";
    }
    
    // ========== SET ==========
    std::cout << "\n--- std::set (ensemble trié, éléments uniques) ---\n";
    std::set<int> ensemble;
    
    ensemble.insert(5);
    ensemble.insert(2);
    ensemble.insert(8);
    ensemble.insert(2);  // Ignoré (déjà présent)
    ensemble.insert(1);
    
    std::cout << "Éléments du set (triés): ";
    for (int n : ensemble) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    // ========== UNORDERED_MAP ==========
    std::cout << "\n--- std::unordered_map (hash map) ---\n";
    std::unordered_map<std::string, std::string> capitales;
    
    capitales["France"] = "Paris";
    capitales["Allemagne"] = "Berlin";
    capitales["Espagne"] = "Madrid";
    capitales["Italie"] = "Rome";
    
    std::cout << "Capitales (ordre non garanti):\n";
    for (const auto& [pays, capitale] : capitales) {
        std::cout << "  " << pays << " -> " << capitale << "\n";
    }
    
    // ========== EXEMPLE PRATIQUE ==========
    std::cout << "\n--- Exemple pratique: Compteur de mots ---\n";
    std::vector<std::string> texte = {
        "le", "chat", "mange", "le", "poisson",
        "le", "chat", "dort", "le", "chien", "aboie"
    };
    
    std::unordered_map<std::string, int> frequences;
    
    for (const auto& mot : texte) {
        frequences[mot]++;
    }
    
    std::cout << "Fréquences des mots:\n";
    for (const auto& [mot, freq] : frequences) {
        std::cout << "  '" << mot << "': " << freq << " fois\n";
    }
    
    // Trouver le mot le plus fréquent
    auto max_elem = std::max_element(
        frequences.begin(), frequences.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );
    
    std::cout << "\nMot le plus fréquent: '" << max_elem->first 
              << "' (" << max_elem->second << " fois)\n";
    
    // ========== COMPARAISON DE PERFORMANCE ==========
    std::cout << "\n--- Comparaison conceptuelle ---\n";
    std::cout << "vector:          O(1) accès, O(1) ajout en fin\n";
    std::cout << "map:             O(log n) accès/insertion, trié\n";
    std::cout << "unordered_map:   O(1) accès/insertion en moyenne\n";
    std::cout << "set:             O(log n) insertion, éléments uniques triés\n";
    
    return 0;
}

/*
 * Ce programme démontre :
 * - std::vector - tableau dynamique
 * - std::map - dictionnaire trié
 * - std::set - ensemble d'éléments uniques triés
 * - std::unordered_map - table de hachage
 * - Structured bindings (C++17)
 * - Range-based for loops
 * - Algorithmes STL (max_element)
 * - Lambdas avec algorithmes
 * 
 * Compilation:
 * g++ -std=c++20 -Wall -Wextra 09-conteneurs-stl.cpp -o conteneurs
 * ./conteneurs
 */
