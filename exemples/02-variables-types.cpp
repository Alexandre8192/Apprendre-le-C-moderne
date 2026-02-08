#include <iostream>
#include <string>

int main() {
    // Déclaration et initialisation avec auto
    auto nom = std::string{"Alice"};
    auto age = 25;
    auto taille = 1.65;
    auto estEtudiant = true;
    
    // Affichage
    std::cout << "=== Informations ===" << "\n";
    std::cout << "Nom: " << nom << "\n";
    std::cout << "Âge: " << age << " ans\n";
    std::cout << "Taille: " << taille << " m\n";
    std::cout << "Étudiant: " << (estEtudiant ? "Oui" : "Non") << "\n";
    
    // Calcul IMC (Indice de Masse Corporelle)
    auto poids = 60.0;
    auto imc = poids / (taille * taille);
    std::cout << "IMC: " << imc << "\n";
    
    return 0;
}

/*
 * Compilation:
 * g++ -std=c++20 02-variables-types.cpp -o variables
 * ./variables
 */
