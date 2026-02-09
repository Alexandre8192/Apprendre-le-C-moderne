#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Etudiant {
    std::string nom;
    std::string prenom;
    double moyenne;
};

void afficherEtudiants(const std::vector<Etudiant>& etudiants, const std::string& titre) {
    std::cout << "\n=== " << titre << " ===\n";
    for (const auto& etudiant : etudiants) {
        std::cout << "- " << std::setw(12) << std::left << etudiant.nom
                  << " " << std::setw(10) << etudiant.prenom
                  << " | moyenne: " << std::fixed << std::setprecision(2)
                  << etudiant.moyenne << "\n";
    }
}

void sauvegarderCSV(const std::filesystem::path& fichier, const std::vector<Etudiant>& etudiants) {
    std::ofstream sortie(fichier);
    if (!sortie) {
        throw std::runtime_error("Impossible d'ouvrir le fichier en écriture");
    }

    for (const auto& etudiant : etudiants) {
        sortie << etudiant.nom << ',' << etudiant.prenom << ',' << etudiant.moyenne << '\n';
    }
}

std::vector<Etudiant> chargerCSV(const std::filesystem::path& fichier) {
    std::vector<Etudiant> etudiants;
    std::ifstream entree(fichier);
    if (!entree) {
        throw std::runtime_error("Fichier introuvable : " + fichier.string());
    }

    std::string ligne;
    int numeroLigne = 0;
    while (std::getline(entree, ligne)) {
        ++numeroLigne;
        if (ligne.empty()) {
            continue;
        }

        std::stringstream buffer(ligne);
        std::string nom;
        std::string prenom;
        std::string moyenneStr;

        if (!std::getline(buffer, nom, ',') ||
            !std::getline(buffer, prenom, ',') ||
            !std::getline(buffer, moyenneStr)) {
            std::cerr << "Ligne " << numeroLigne << " mal formée, ignorée.\n";
            continue;
        }

        try {
            double moyenne = std::stod(moyenneStr);
            etudiants.push_back({nom, prenom, moyenne});
        } catch (const std::exception&) {
            std::cerr << "Moyenne invalide à la ligne " << numeroLigne << ", ignorée.\n";
        }
    }

    return etudiants;
}

int main() {
    const std::filesystem::path fichier = "etudiants.csv";
    const std::filesystem::path dossierBackup = "backup";

    std::vector<Etudiant> etudiants = {
        {"Dupont", "Alice", 14.5},
        {"Martin", "Lucas", 11.8},
        {"Durand", "Eva", 17.2},
        {"Petit", "Noah", 9.4}
    };

    try {
        sauvegarderCSV(fichier, etudiants);
        std::cout << "Fichier CSV sauvegardé : " << fichier << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur de sauvegarde: " << e.what() << "\n";
        return 1;
    }

    // std::filesystem : vérifier l'existence et la taille
    if (std::filesystem::exists(fichier)) {
        auto taille = std::filesystem::file_size(fichier);
        std::cout << "Taille du fichier: " << taille << " octets\n";
    }

    // Créer un dossier de backup si nécessaire
    if (!std::filesystem::exists(dossierBackup)) {
        std::filesystem::create_directory(dossierBackup);
        std::cout << "Dossier de backup créé: " << dossierBackup << "\n";
    }

    std::vector<Etudiant> charges;
    try {
        charges = chargerCSV(fichier);
    } catch (const std::exception& e) {
        std::cerr << "Erreur de chargement: " << e.what() << "\n";
        return 1;
    }

    std::sort(charges.begin(), charges.end(),
              [](const auto& a, const auto& b) { return a.moyenne > b.moyenne; });
    afficherEtudiants(charges, "Étudiants triés par moyenne décroissante");

    return 0;
}

/*
 * Ce programme démontre :
 * - std::ofstream et std::ifstream avec RAII
 * - Parsing CSV avec std::getline et std::stringstream
 * - Gestion d'erreurs sur les fichiers
 * - std::filesystem (exists, file_size, create_directory)
 * - Tri des données avec std::sort
 */

/*
 * Compilation et exécution :
 * g++ -std=c++20 -Wall -Wextra -O2 11-fichiers-io.cpp -o fichiers_io
 * ./fichiers_io
 */
