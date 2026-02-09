#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Produit {
    std::string nom;
    double prix;
    int stock;
};

void afficherProduits(const std::vector<Produit>& produits, const std::string& titre) {
    std::cout << "\n=== " << titre << " ===\n";
    for (const auto& produit : produits) {
        std::cout << "- " << std::setw(15) << std::left << produit.nom
                  << " | prix: " << std::setw(6) << std::right << produit.prix
                  << " € | stock: " << produit.stock << "\n";
    }
}

int main() {
    std::vector<Produit> produits = {
        {"Clavier", 49.90, 12},
        {"Souris", 29.90, 0},
        {"Casque", 79.90, 5},
        {"Écran", 199.90, 3},
        {"Webcam", 59.90, 8},
        {"Tapis", 14.90, 25}
    };

    afficherProduits(produits, "Produits initiaux");

    // Tri par prix avec std::sort et une lambda
    std::sort(produits.begin(), produits.end(),
              [](const auto& a, const auto& b) { return a.prix < b.prix; });
    afficherProduits(produits, "Triés par prix croissant");

    // Recherche d'un produit avec std::find_if
    const std::string cible = "Écran";
    auto it = std::find_if(produits.begin(), produits.end(),
                           [&cible](const auto& p) { return p.nom == cible; });
    if (it != produits.end()) {
        std::cout << "\nProduit trouvé : " << it->nom << " (" << it->prix << " €)\n";
    } else {
        std::cout << "\nProduit \"" << cible << "\" introuvable.\n";
    }

    // Filtrage avec std::copy_if : produits en stock
    std::vector<Produit> disponibles;
    std::copy_if(produits.begin(), produits.end(), std::back_inserter(disponibles),
                 [](const auto& p) { return p.stock > 0; });
    afficherProduits(disponibles, "Produits disponibles (stock > 0)");

    // Calcul total avec std::accumulate : valeur du stock
    double valeurStock = std::accumulate(
        produits.begin(), produits.end(), 0.0,
        [](double total, const auto& p) { return total + p.prix * p.stock; });
    std::cout << "\nValeur totale du stock : " << valeurStock << " €\n";

    // Suppression conditionnelle avec remove-erase : retirer stock nul
    auto nouvelleFin = std::remove_if(produits.begin(), produits.end(),
                                      [](const auto& p) { return p.stock == 0; });
    produits.erase(nouvelleFin, produits.end());
    afficherProduits(produits, "Après suppression des produits en rupture");

    // Transformation avec std::transform : appliquer une remise de 10%
    std::vector<Produit> remises;
    remises.reserve(produits.size());
    std::transform(produits.begin(), produits.end(), std::back_inserter(remises),
                   [](const auto& p) {
                       return Produit{p.nom, p.prix * 0.9, p.stock};
                   });
    afficherProduits(remises, "Produits avec remise de 10%");

    return 0;
}

/*
 * Ce programme démontre :
 * - std::sort avec lambda pour trier
 * - std::find_if pour la recherche ciblée
 * - std::copy_if pour filtrer des éléments
 * - std::accumulate pour agréger des valeurs
 * - Remove-erase idiom pour supprimer conditionnellement
 * - std::transform pour appliquer une remise
 */

/*
 * Compilation et exécution :
 * g++ -std=c++20 -Wall -Wextra -O2 10-algorithmes-stl.cpp -o algorithmes
 * ./algorithmes
 */
