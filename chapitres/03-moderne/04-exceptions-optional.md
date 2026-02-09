# Gestion des Erreurs - Exceptions et std::optional

## 🎯 Objectif

Apprendre à gérer les erreurs de manière robuste avec les exceptions et les types modernes comme `std::optional`.

## ⚠️ Pourquoi Gérer les Erreurs ?

Sans gestion d'erreurs appropriée, un programme peut :
- Crasher de manière inattendue
- Produire des résultats incorrects
- Perdre des données
- Créer des vulnérabilités de sécurité

## 🎭 Exceptions - try/catch

Les **exceptions** permettent de séparer le code normal du code de gestion d'erreurs.

### Syntaxe de base

```cpp
#include <iostream>
#include <stdexcept>

int diviser(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division par zéro!");
    }
    return a / b;
}

int main() {
    try {
        int resultat = diviser(10, 2);
        std::cout << "Résultat: " << resultat << "\n";
        
        resultat = diviser(10, 0);  // Lance une exception
        std::cout << "Ceci ne s'affichera pas\n";
        
    } catch (const std::runtime_error& e) {
        std::cout << "Erreur: " << e.what() << "\n";
    }
    
    std::cout << "Programme continue...\n";
    return 0;
}
```

### Types d'Exceptions Standard

```cpp
#include <stdexcept>

// Exception de base
std::exception

// Exceptions logiques
std::logic_error
  ├── std::invalid_argument    // Argument invalide
  ├── std::domain_error        // Erreur de domaine mathématique
  ├── std::length_error        // Longueur excessive
  └── std::out_of_range        // Hors limites

// Exceptions d'exécution
std::runtime_error
  ├── std::range_error         // Erreur de plage
  ├── std::overflow_error      // Débordement arithmétique
  └── std::underflow_error     // Sous-dépassement arithmétique
```

### Exemple avec différents types

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

void validerAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("L'âge ne peut pas être négatif");
    }
    if (age > 150) {
        throw std::out_of_range("L'âge est irréaliste");
    }
}

int main() {
    try {
        validerAge(-5);
    } catch (const std::invalid_argument& e) {
        std::cout << "Argument invalide: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Hors limites: " << e.what() << "\n";
    }
    
    return 0;
}
```

## 🔄 Capturer Plusieurs Exceptions

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

void fonctionRisquee(int choix) {
    if (choix == 1) {
        throw std::invalid_argument("Argument invalide");
    } else if (choix == 2) {
        throw std::runtime_error("Erreur d'exécution");
    } else if (choix == 3) {
        throw std::out_of_range("Hors limites");
    }
}

int main() {
    try {
        fonctionRisquee(2);
        
    } catch (const std::invalid_argument& e) {
        std::cout << "1. Argument invalide: " << e.what() << "\n";
        
    } catch (const std::out_of_range& e) {
        std::cout << "2. Hors limites: " << e.what() << "\n";
        
    } catch (const std::runtime_error& e) {
        std::cout << "3. Erreur runtime: " << e.what() << "\n";
        
    } catch (const std::exception& e) {
        // Capture toutes les exceptions standard
        std::cout << "4. Autre exception: " << e.what() << "\n";
        
    } catch (...) {
        // Capture TOUT (à éviter généralement)
        std::cout << "5. Exception inconnue\n";
    }
    
    return 0;
}
```

## 📦 Créer ses Propres Exceptions

```cpp
#include <iostream>
#include <exception>
#include <string>

// Exception personnalisée
class ErreurCompte : public std::exception {
private:
    std::string message_;

public:
    explicit ErreurCompte(const std::string& msg) : message_(msg) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

class CompteBancaire {
private:
    double solde_;

public:
    CompteBancaire(double solde) : solde_(solde) {}
    
    void retirer(double montant) {
        if (montant < 0) {
            throw std::invalid_argument("Montant négatif");
        }
        if (montant > solde_) {
            throw ErreurCompte("Solde insuffisant");
        }
        solde_ -= montant;
    }
    
    double getSolde() const { return solde_; }
};

int main() {
    CompteBancaire compte(100.0);
    
    try {
        compte.retirer(150.0);
    } catch (const ErreurCompte& e) {
        std::cout << "Erreur compte: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Argument invalide: " << e.what() << "\n";
    }
    
    return 0;
}
```

## 📍 RAII et Gestion Automatique

Les exceptions fonctionnent bien avec RAII (Resource Acquisition Is Initialization) :

```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>

void traiterFichier(const std::string& nom) {
    std::ifstream fichier(nom);  // RAII : ouverture automatique
    
    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier");
    }
    
    // Traitement...
    
    // Pas besoin de fermer : destructeur le fait automatiquement
    // Même en cas d'exception !
}

int main() {
    try {
        traiterFichier("data.txt");
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << "\n";
    }
    
    return 0;
}
```

## 🎁 std::optional - Valeurs Optionnelles (C++17)

`std::optional` représente une valeur qui peut exister ou non, **sans utiliser d'exception**.

```cpp
#include <iostream>
#include <optional>
#include <string>

std::optional<int> diviser(int a, int b) {
    if (b == 0) {
        return std::nullopt;  // Pas de valeur
    }
    return a / b;  // Valeur présente
}

int main() {
    auto resultat = diviser(10, 2);
    
    if (resultat.has_value()) {
        std::cout << "Résultat: " << resultat.value() << "\n";
        // Ou plus simplement: *resultat
    } else {
        std::cout << "Pas de résultat (division par zéro)\n";
    }
    
    // Avec valeur par défaut
    auto r2 = diviser(10, 0);
    std::cout << "Résultat: " << r2.value_or(-1) << "\n";  // -1 si nullopt
    
    return 0;
}
```

### Exemples pratiques avec optional

```cpp
#include <optional>
#include <string>
#include <map>

class Utilisateur {
public:
    std::string nom;
    std::optional<std::string> email;  // Email optionnel
    std::optional<int> age;             // Âge optionnel
};

class Database {
private:
    std::map<int, std::string> users_;

public:
    Database() {
        users_[1] = "Alice";
        users_[2] = "Bob";
    }
    
    std::optional<std::string> trouverUtilisateur(int id) {
        auto it = users_.find(id);
        if (it != users_.end()) {
            return it->second;
        }
        return std::nullopt;
    }
};

int main() {
    Database db;
    
    if (auto nom = db.trouverUtilisateur(1)) {
        std::cout << "Trouvé: " << *nom << "\n";
    } else {
        std::cout << "Utilisateur non trouvé\n";
    }
    
    return 0;
}
```

## 🆚 Exceptions vs optional

### Quand utiliser les exceptions ?

```cpp
// ✅ Erreurs exceptionnelles, inattendues
void ouvrirFichierCritique(const std::string& nom) {
    std::ifstream f(nom);
    if (!f) {
        throw std::runtime_error("Fichier critique manquant!");
    }
}

// ✅ Erreurs de programmation
void definirAge(int age) {
    if (age < 0 || age > 150) {
        throw std::invalid_argument("Âge invalide");
    }
}
```

### Quand utiliser optional ?

```cpp
// ✅ Valeur qui peut légitimement être absente
std::optional<std::string> obtenirNomUtilisateur(int id) {
    // Un utilisateur peut ne pas exister (condition normale)
    return std::nullopt;
}

// ✅ Résultat de recherche
std::optional<int> trouverIndex(const std::vector<int>& v, int valeur) {
    // Ne pas trouver est un cas normal
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == valeur) return i;
    }
    return std::nullopt;
}
```

## 💡 Exemple Complet : Parser de Configuration

```cpp
#include <iostream>
#include <optional>
#include <string>
#include <map>
#include <stdexcept>

class ConfigParser {
private:
    std::map<std::string, std::string> config_;

public:
    void charger(const std::string& contenu) {
        // Simulation de parsing
        config_["host"] = "localhost";
        config_["port"] = "8080";
        // "user" n'est pas défini
    }
    
    // Retourne optional pour valeurs optionnelles
    std::optional<std::string> obtenirOptional(const std::string& key) const {
        auto it = config_.find(key);
        if (it != config_.end()) {
            return it->second;
        }
        return std::nullopt;
    }
    
    // Lance exception pour valeurs requises
    std::string obtenirRequis(const std::string& key) const {
        auto it = config_.find(key);
        if (it == config_.end()) {
            throw std::runtime_error("Clé requise manquante: " + key);
        }
        return it->second;
    }
    
    // Avec valeur par défaut
    std::string obtenirAvecDefaut(const std::string& key, 
                                   const std::string& defaut) const {
        return obtenirOptional(key).value_or(defaut);
    }
};

int main() {
    ConfigParser config;
    config.charger("config.ini");
    
    try {
        // Valeur requise (exception si absente)
        auto host = config.obtenirRequis("host");
        std::cout << "Host: " << host << "\n";
        
        // Valeur optionnelle
        if (auto user = config.obtenirOptional("user")) {
            std::cout << "User: " << *user << "\n";
        } else {
            std::cout << "User non défini\n";
        }
        
        // Avec défaut
        auto timeout = config.obtenirAvecDefaut("timeout", "30");
        std::cout << "Timeout: " << timeout << "\n";
        
        // Ceci lance une exception
        auto missing = config.obtenirRequis("missing_key");
        
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << "\n";
    }
    
    return 0;
}
```

## ✅ Bonnes Pratiques

```cpp
// ✅ Capturer par référence const
catch (const std::exception& e) { }

// ✅ Ne jamais avaler les exceptions silencieusement
catch (const std::exception& e) {
    // Log l'erreur au minimum
    std::cerr << "Erreur: " << e.what() << "\n";
}

// ✅ Utiliser noexcept pour fonctions qui ne lancent jamais
int addition(int a, int b) noexcept {
    return a + b;
}

// ✅ Destructeurs doivent être noexcept (par défaut en C++11)
~MaClasse() noexcept {
    // Nettoyage
}

// ✅ Préférer optional pour les cas normaux d'absence
std::optional<User> findUser(int id);

// ✅ Utiliser exceptions pour les erreurs véritables
void validateInput(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("Input vide");
    }
}
```

## 🎯 Exercices

### Exercice 1
Créez une fonction `parseEntier(const std::string& s)` qui retourne `std::optional<int>`.

### Exercice 2
Créez une classe `DivisionSafe` avec gestion d'erreurs pour division et modulo.

### Exercice 3
Implémentez un système de validation d'email qui lance des exceptions appropriées.

## 📚 Prochaine étape

Passez au chapitre suivant : [Algorithmes STL](05-algorithmes-stl.md)
