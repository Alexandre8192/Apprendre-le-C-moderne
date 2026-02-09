#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
enum class Statut {
    AFaire,
    EnCours,
    Terminee
};
enum class Priorite {
    Basse = 1,
    Moyenne = 2,
    Haute = 3
};
struct Tache {
    int id;
    std::string description;
    Statut statut;
    Priorite priorite;
    std::string dateEcheance; // Format ISO : YYYY-MM-DD
};
std::string versTexte(Statut statut) {
    switch (statut) {
        case Statut::AFaire:
            return "A_FAIRE";
        case Statut::EnCours:
            return "EN_COURS";
        case Statut::Terminee:
            return "TERMINEE";
    }
    return "A_FAIRE";
}
std::string versTexte(Priorite priorite) {
    switch (priorite) {
        case Priorite::Basse:
            return "BASSE";
        case Priorite::Moyenne:
            return "MOYENNE";
        case Priorite::Haute:
            return "HAUTE";
    }
    return "MOYENNE";
}
std::optional<Statut> statutDepuisTexte(const std::string& texte) {
    if (texte == "A_FAIRE") {
        return Statut::AFaire;
    }
    if (texte == "EN_COURS") {
        return Statut::EnCours;
    }
    if (texte == "TERMINEE") {
        return Statut::Terminee;
    }
    return std::nullopt;
}
std::optional<Priorite> prioriteDepuisTexte(const std::string& texte) {
    if (texte == "BASSE") {
        return Priorite::Basse;
    }
    if (texte == "MOYENNE") {
        return Priorite::Moyenne;
    }
    if (texte == "HAUTE") {
        return Priorite::Haute;
    }
    return std::nullopt;
}

class GestionnaireTaches {
public:
    void ajouterTache(const std::string& description,
                      Priorite priorite,
                      const std::string& dateEcheance) {
        taches_.push_back({prochainId_++, description, Statut::AFaire, priorite, dateEcheance});
    }

    bool supprimerTache(int id) {
        auto fin = std::remove_if(taches_.begin(), taches_.end(),
                                  [id](const auto& t) { return t.id == id; });
        if (fin == taches_.end()) {
            return false;
        }
        taches_.erase(fin, taches_.end());
        return true;
    }
    bool changerStatut(int id, Statut statut) {
        auto it = trouverTache(id);
        if (it == taches_.end()) {
            return false;
        }
        it->statut = statut;
        return true;
    }
    void listerTaches() const {
        if (taches_.empty()) {
            std::cout << "\nAucune tâche pour le moment.\n";
            return;
        }

        std::cout << "\n=== Liste des tâches ===\n";
        for (const auto& tache : taches_) {
            afficherTache(tache);
        }
    }
    void trierParPriorite() {
        std::sort(taches_.begin(), taches_.end(), [](const auto& a, const auto& b) {
            return static_cast<int>(a.priorite) > static_cast<int>(b.priorite);
        });
    }
    void trierParDate() {
        std::sort(taches_.begin(), taches_.end(), [](const auto& a, const auto& b) {
            return a.dateEcheance < b.dateEcheance;
        });
    }
    std::vector<Tache> rechercherMotCle(const std::string& motCle) const {
        std::vector<Tache> resultat;
        std::copy_if(taches_.begin(), taches_.end(), std::back_inserter(resultat),
                     [&motCle](const auto& t) {
                         return t.description.find(motCle) != std::string::npos;
                     });
        return resultat;
    }
    std::vector<Tache> filtrerParStatut(Statut statut) const {
        std::vector<Tache> resultat;
        std::copy_if(taches_.begin(), taches_.end(), std::back_inserter(resultat),
                     [statut](const auto& t) { return t.statut == statut; });
        return resultat;
    }
    bool sauvegarderCSV(const std::filesystem::path& fichier) const {
        std::ofstream sortie(fichier);
        if (!sortie) {
            return false;
        }

        for (const auto& tache : taches_) {
            sortie << tache.id << ';'
                   << std::quoted(tache.description) << ';'
                   << versTexte(tache.statut) << ';'
                   << versTexte(tache.priorite) << ';'
                   << tache.dateEcheance << '\n';
        }
        return true;
    }

    bool chargerCSV(const std::filesystem::path& fichier) {
        if (!std::filesystem::exists(fichier)) {
            return false;
        }

        std::ifstream entree(fichier);
        if (!entree) {
            return false;
        }

        taches_.clear();
        prochainId_ = 1;

        std::string ligne;
        while (std::getline(entree, ligne)) {
            if (ligne.empty()) {
                continue;
            }

            std::stringstream buffer(ligne);
            std::string idStr;
            std::string description;
            std::string statutStr;
            std::string prioriteStr;
            std::string dateStr;

            if (!std::getline(buffer, idStr, ';') ||
                !std::getline(buffer, description, ';') ||
                !std::getline(buffer, statutStr, ';') ||
                !std::getline(buffer, prioriteStr, ';') ||
                !std::getline(buffer, dateStr)) {
                continue;
            }

            int id = 0;
            try {
                id = std::stoi(idStr);
            } catch (const std::exception&) {
                continue;
            }

            std::stringstream descStream(description);
            std::string descriptionDecodee;
            descStream >> std::quoted(descriptionDecodee);

            auto statut = statutDepuisTexte(statutStr);
            auto priorite = prioriteDepuisTexte(prioriteStr);
            if (!statut || !priorite) {
                continue;
            }

            taches_.push_back({id, descriptionDecodee, *statut, *priorite, dateStr});
            prochainId_ = std::max(prochainId_, id + 1);
        }
        return true;
    }

    static void afficherTache(const Tache& tache) {
        std::cout << "- [" << tache.id << "] " << std::setw(30) << std::left
                  << tache.description << " | " << std::setw(8)
                  << versTexte(tache.statut) << " | " << std::setw(7)
                  << versTexte(tache.priorite) << " | " << tache.dateEcheance << "\n";
    }

private:
    std::vector<Tache>::iterator trouverTache(int id) {
        return std::find_if(taches_.begin(), taches_.end(),
                            [id](const auto& t) { return t.id == id; });
    }

    std::vector<Tache> taches_;
    int prochainId_ = 1;
};

std::string lireLigne(const std::string& message) {
    std::cout << message;
    std::string valeur;
    std::getline(std::cin, valeur);
    return valeur;
}

std::optional<int> lireEntier(const std::string& message) {
    std::string texte = lireLigne(message);
    if (texte.empty()) {
        return std::nullopt;
    }

    try {
        return std::stoi(texte);
    } catch (const std::exception&) {
        return std::nullopt;
    }
}

Priorite demanderPriorite() {
    std::cout << "Priorité (1=Basse, 2=Moyenne, 3=Haute) : ";
    std::string valeur;
    std::getline(std::cin, valeur);

    if (valeur == "1") {
        return Priorite::Basse;
    }
    if (valeur == "3") {
        return Priorite::Haute;
    }
    return Priorite::Moyenne;
}

Statut demanderStatut() {
    std::cout << "Statut (1=A faire, 2=En cours, 3=Terminée) : ";
    std::string valeur;
    std::getline(std::cin, valeur);

    if (valeur == "2") {
        return Statut::EnCours;
    }
    if (valeur == "3") {
        return Statut::Terminee;
    }
    return Statut::AFaire;
}

void afficherMenu() {
    std::cout << "\n=== Todo App Console ===\n"
              << "1. Ajouter une tâche\n"
              << "2. Supprimer une tâche\n"
              << "3. Modifier le statut\n"
              << "4. Lister toutes les tâches\n"
              << "5. Trier par priorité\n"
              << "6. Trier par date\n"
              << "7. Rechercher par mot-clé\n"
              << "8. Filtrer par statut\n"
              << "9. Sauvegarder\n"
              << "10. Quitter\n";
}

int main() {
    const std::filesystem::path fichier = "taches.csv";
    GestionnaireTaches gestionnaire;

    if (gestionnaire.chargerCSV(fichier)) {
        std::cout << "Données chargées depuis " << fichier << ".\n";
    }

    bool actif = true;
    while (actif) {
        afficherMenu();
        auto choix = lireEntier("Votre choix : ");
        if (!choix) {
            std::cout << "Entrée invalide.\n";
            continue;
        }

        switch (*choix) {
            case 1: {
                std::string description = lireLigne("Description : ");
                std::string date = lireLigne("Date d'échéance (YYYY-MM-DD) : ");
                Priorite priorite = demanderPriorite();
                if (description.empty()) {
                    std::cout << "Description vide, tâche ignorée.\n";
                    break;
                }
                gestionnaire.ajouterTache(description, priorite, date);
                std::cout << "Tâche ajoutée !\n";
                break;
            }
            case 2: {
                auto id = lireEntier("ID de la tâche à supprimer : ");
                if (!id || !gestionnaire.supprimerTache(*id)) {
                    std::cout << "Tâche introuvable.\n";
                } else {
                    std::cout << "Tâche supprimée.\n";
                }
                break;
            }
            case 3: {
                auto id = lireEntier("ID de la tâche : ");
                if (!id) {
                    std::cout << "ID invalide.\n";
                    break;
                }
                Statut statut = demanderStatut();
                if (!gestionnaire.changerStatut(*id, statut)) {
                    std::cout << "Tâche introuvable.\n";
                } else {
                    std::cout << "Statut mis à jour.\n";
                }
                break;
            }
            case 4:
                gestionnaire.listerTaches();
                break;
            case 5:
                gestionnaire.trierParPriorite();
                std::cout << "Tâches triées par priorité.\n";
                break;
            case 6:
                gestionnaire.trierParDate();
                std::cout << "Tâches triées par date.\n";
                break;
            case 7: {
                std::string motCle = lireLigne("Mot-clé : ");
                auto resultat = gestionnaire.rechercherMotCle(motCle);
                std::cout << "\n=== Résultats de recherche ===\n";
                for (const auto& tache : resultat) {
                    GestionnaireTaches::afficherTache(tache);
                }
                if (resultat.empty()) {
                    std::cout << "Aucune tâche correspondante.\n";
                }
                break;
            }
            case 8: {
                Statut statut = demanderStatut();
                auto resultat = gestionnaire.filtrerParStatut(statut);
                std::cout << "\n=== Tâches filtrées ===\n";
                for (const auto& tache : resultat) {
                    GestionnaireTaches::afficherTache(tache);
                }
                if (resultat.empty()) {
                    std::cout << "Aucune tâche pour ce statut.\n";
                }
                break;
            }
            case 9:
                if (gestionnaire.sauvegarderCSV(fichier)) {
                    std::cout << "Sauvegarde réussie dans " << fichier << ".\n";
                } else {
                    std::cout << "Erreur lors de la sauvegarde.\n";
                }
                break;
            case 10:
                actif = false;
                break;
            default:
                std::cout << "Choix inconnu.\n";
                break;
        }
    }

    gestionnaire.sauvegarderCSV(fichier);
    std::cout << "Au revoir !\n";
    return 0;
}

/*
 * Compilation et exécution :
 * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 todo.cpp -o todo
 * ./todo
 */
