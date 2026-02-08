#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

// Classe représentant un étudiant
class Etudiant {
public:
    Etudiant(std::string nom, int age, double moyenne)
        : nom_(std::move(nom)), age_(age), moyenne_(moyenne) {}
    
    const std::string& getNom() const { return nom_; }
    int getAge() const { return age_; }
    double getMoyenne() const { return moyenne_; }
    
    void afficher() const {
        std::cout << "Nom: " << nom_ 
                  << ", Age: " << age_ 
                  << ", Moyenne: " << moyenne_ << "\n";
    }

private:
    std::string nom_;
    int age_;
    double moyenne_;
};

// Classe gestionnaire d'étudiants
class GestionnaireEtudiants {
public:
    void ajouterEtudiant(std::unique_ptr<Etudiant> etudiant) {
        etudiants_.push_back(std::move(etudiant));
    }
    
    void afficherTous() const {
        std::cout << "\n=== Liste des étudiants ===\n";
        for (const auto& etudiant : etudiants_) {
            etudiant->afficher();
        }
    }
    
    void trierParMoyenne() {
        std::sort(etudiants_.begin(), etudiants_.end(),
            [](const auto& a, const auto& b) {
                return a->getMoyenne() > b->getMoyenne();
            });
    }
    
    void trierParNom() {
        std::sort(etudiants_.begin(), etudiants_.end(),
            [](const auto& a, const auto& b) {
                return a->getNom() < b->getNom();
            });
    }
    
    double calculerMoyenneGenerale() const {
        if (etudiants_.empty()) return 0.0;
        
        double somme = 0.0;
        for (const auto& etudiant : etudiants_) {
            somme += etudiant->getMoyenne();
        }
        return somme / etudiants_.size();
    }
    
    void afficherStatistiques() const {
        if (etudiants_.empty()) {
            std::cout << "Aucun étudiant.\n";
            return;
        }
        
        auto moyenneGenerale = calculerMoyenneGenerale();
        
        auto meilleur = std::max_element(etudiants_.begin(), etudiants_.end(),
            [](const auto& a, const auto& b) {
                return a->getMoyenne() < b->getMoyenne();
            });
        
        std::cout << "\n=== Statistiques ===\n";
        std::cout << "Nombre d'étudiants: " << etudiants_.size() << "\n";
        std::cout << "Moyenne générale: " << moyenneGenerale << "\n";
        std::cout << "Meilleur étudiant: " << (*meilleur)->getNom() 
                  << " (" << (*meilleur)->getMoyenne() << ")\n";
    }

private:
    std::vector<std::unique_ptr<Etudiant>> etudiants_;
};

int main() {
    // Créer un gestionnaire
    GestionnaireEtudiants gestionnaire;
    
    // Ajouter des étudiants avec smart pointers
    gestionnaire.ajouterEtudiant(
        std::make_unique<Etudiant>("Alice Dupont", 20, 15.5)
    );
    gestionnaire.ajouterEtudiant(
        std::make_unique<Etudiant>("Bob Martin", 21, 12.3)
    );
    gestionnaire.ajouterEtudiant(
        std::make_unique<Etudiant>("Charlie Durand", 19, 17.8)
    );
    gestionnaire.ajouterEtudiant(
        std::make_unique<Etudiant>("Diana Lambert", 20, 14.2)
    );
    
    // Afficher tous les étudiants
    gestionnaire.afficherTous();
    
    // Afficher les statistiques
    gestionnaire.afficherStatistiques();
    
    // Trier par moyenne
    std::cout << "\n=== Triés par moyenne (décroissant) ===\n";
    gestionnaire.trierParMoyenne();
    gestionnaire.afficherTous();
    
    // Trier par nom
    std::cout << "\n=== Triés par nom (alphabétique) ===\n";
    gestionnaire.trierParNom();
    gestionnaire.afficherTous();
    
    // Gestion automatique de la mémoire avec smart pointers !
    return 0;
}

/*
 * Ce programme démontre :
 * - Classes et encapsulation
 * - Smart pointers (unique_ptr)
 * - Conteneurs STL (vector)
 * - Lambda expressions
 * - Algorithmes STL (sort, max_element)
 * - Move semantics
 * - Const-correctness
 */

/*
   * Compilation et exécution :
   * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 07-gestion-etudiants.cpp -o gestion
   * ./gestion
*/
