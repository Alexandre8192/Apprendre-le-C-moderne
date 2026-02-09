# Conteneurs STL - Standard Template Library

## 🎯 Objectif

Maîtriser les conteneurs de la bibliothèque standard C++ pour stocker et manipuler des collections de données.

## 📦 Qu'est-ce qu'un Conteneur ?

Un **conteneur** est une structure de données qui stocke une collection d'objets.

## 📊 std::vector - Tableau Dynamique

Le conteneur le plus utilisé, équivalent à un tableau redimensionnable.

```cpp
#include <iostream>
#include <vector>

int main() {
    // Création
    std::vector<int> nombres;
    std::vector<int> scores = {10, 20, 30};
    std::vector<std::string> noms{"Alice", "Bob", "Charlie"};
    
    // Ajout d'éléments
    nombres.push_back(42);
    nombres.push_back(17);
    nombres.push_back(99);
    
    // Accès aux éléments
    std::cout << "Premier: " << nombres[0] << "\n";
    std::cout << "Dernier: " << nombres.back() << "\n";
    
    // Taille
    std::cout << "Taille: " << nombres.size() << "\n";
    
    // Parcours
    for (int n : nombres) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    return 0;
}
```

### Méthodes importantes de vector

```cpp
std::vector<int> v = {1, 2, 3};

// Ajout
v.push_back(4);           // Ajoute à la fin
v.emplace_back(5);        // Construit directement (plus efficace)
v.insert(v.begin(), 0);   // Insère au début

// Suppression
v.pop_back();             // Retire le dernier
v.erase(v.begin());       // Retire le premier
v.clear();                // Vide tout

// Capacité
v.size();                 // Nombre d'éléments
v.capacity();             // Capacité allouée
v.empty();                // Teste si vide
v.reserve(100);           // Réserve de l'espace

// Accès
v[0];                     // Accès non sécurisé
v.at(0);                  // Accès avec vérification
v.front();                // Premier élément
v.back();                 // Dernier élément
```

## 🗺️ std::map - Dictionnaire (Clé-Valeur)

Structure associative qui mappe des clés uniques à des valeurs.

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    // Création
    std::map<std::string, int> ages;
    
    // Ajout d'éléments
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 22;
    
    // Accès
    std::cout << "Âge d'Alice: " << ages["Alice"] << "\n";
    
    // Vérifier l'existence
    if (ages.find("Bob") != ages.end()) {
        std::cout << "Bob existe!\n";
    }
    
    // Parcours
    for (const auto& [nom, age] : ages) {  // C++17 structured binding
        std::cout << nom << " a " << age << " ans\n";
    }
    
    // Suppression
    ages.erase("Bob");
    
    return 0;
}
```

### map vs unordered_map

```cpp
#include <map>
#include <unordered_map>

// map : trié par clé, recherche O(log n)
std::map<std::string, int> ordonne;

// unordered_map : non trié, recherche O(1) en moyenne
std::unordered_map<std::string, int> nonOrdonne;
```

## 🔢 std::set - Ensemble d'Éléments Uniques

Collection d'éléments uniques, automatiquement triés.

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> nombres;
    
    // Ajout
    nombres.insert(5);
    nombres.insert(2);
    nombres.insert(8);
    nombres.insert(2);  // Ignoré (déjà présent)
    
    // Parcours (ordre trié automatiquement)
    for (int n : nombres) {
        std::cout << n << " ";  // Affiche: 2 5 8
    }
    std::cout << "\n";
    
    // Recherche
    if (nombres.count(5) > 0) {
        std::cout << "5 est présent\n";
    }
    
    // Suppression
    nombres.erase(2);
    
    return 0;
}
```

## 📋 std::array - Tableau de Taille Fixe (C++11)

Tableau de taille fixe connue à la compilation.

```cpp
#include <array>

int main() {
    // Déclaration
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    // Accès
    arr[0] = 10;
    arr.at(1) = 20;  // Avec vérification
    
    // Taille (constexpr)
    constexpr size_t taille = arr.size();
    
    // Parcours
    for (int n : arr) {
        std::cout << n << " ";
    }
    
    return 0;
}
```

## 🔄 std::deque - Double-Ended Queue

Permet l'ajout/suppression efficace aux deux extrémités.

```cpp
#include <deque>

int main() {
    std::deque<int> d;
    
    // Ajout
    d.push_back(3);    // À la fin
    d.push_front(1);   // Au début
    d.push_back(4);
    d.push_front(0);
    // Résultat: 0 1 3 4
    
    // Suppression
    d.pop_front();     // Retire le premier
    d.pop_back();      // Retire le dernier
    
    return 0;
}
```

## 📚 std::list - Liste Doublement Chaînée

Insertion/suppression rapide partout, mais accès lent.

```cpp
#include <list>

int main() {
    std::list<int> liste = {1, 2, 3, 4, 5};
    
    // Insertion
    auto it = liste.begin();
    ++it;  // Pointe vers 2
    liste.insert(it, 99);  // Insère 99 avant 2
    // Résultat: 1 99 2 3 4 5
    
    // Suppression
    liste.remove(3);  // Retire toutes les occurrences de 3
    
    return 0;
}
```

## 📊 Tableau Comparatif des Conteneurs

| Conteneur | Usage | Accès | Insertion | Recherche |
|-----------|-------|-------|-----------|-----------|
| `vector` | Général, tableau dynamique | O(1) | O(1) fin, O(n) milieu | O(n) |
| `deque` | Queue double | O(1) | O(1) aux extrémités | O(n) |
| `list` | Liste chaînée | O(n) | O(1) partout | O(n) |
| `array` | Taille fixe | O(1) | N/A | O(n) |
| `map` | Clé-valeur trié | O(log n) | O(log n) | O(log n) |
| `unordered_map` | Clé-valeur hash | O(1) | O(1) | O(1) |
| `set` | Ensemble trié | O(log n) | O(log n) | O(log n) |
| `unordered_set` | Ensemble hash | O(1) | O(1) | O(1) |

## 💡 Exemple Complet : Annuaire

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>

struct Contact {
    std::string nom;
    std::string telephone;
    std::string email;
};

class Annuaire {
private:
    std::map<std::string, Contact> contacts_;

public:
    void ajouterContact(const Contact& c) {
        contacts_[c.nom] = c;
        std::cout << "✓ Contact ajouté: " << c.nom << "\n";
    }
    
    void rechercherContact(const std::string& nom) const {
        auto it = contacts_.find(nom);
        if (it != contacts_.end()) {
            const auto& c = it->second;
            std::cout << "\n📇 Contact trouvé:\n";
            std::cout << "  Nom: " << c.nom << "\n";
            std::cout << "  Tél: " << c.telephone << "\n";
            std::cout << "  Email: " << c.email << "\n";
        } else {
            std::cout << "❌ Contact non trouvé\n";
        }
    }
    
    void afficherTous() const {
        std::cout << "\n=== Tous les contacts ===\n";
        for (const auto& [nom, contact] : contacts_) {
            std::cout << contact.nom << " - " << contact.telephone << "\n";
        }
    }
    
    void supprimerContact(const std::string& nom) {
        if (contacts_.erase(nom) > 0) {
            std::cout << "✓ Contact supprimé: " << nom << "\n";
        } else {
            std::cout << "❌ Contact non trouvé\n";
        }
    }
};

int main() {
    Annuaire annuaire;
    
    annuaire.ajouterContact({"Alice Dupont", "01-23-45-67-89", "alice@mail.com"});
    annuaire.ajouterContact({"Bob Martin", "01-98-76-54-32", "bob@mail.com"});
    annuaire.ajouterContact({"Charlie Durand", "01-11-22-33-44", "charlie@mail.com"});
    
    annuaire.afficherTous();
    annuaire.rechercherContact("Alice Dupont");
    annuaire.supprimerContact("Bob Martin");
    annuaire.afficherTous();
    
    return 0;
}
```

## 🎯 Quel Conteneur Choisir ?

```cpp
// Besoin d'un tableau dynamique ? → vector
std::vector<int> nombres;

// Besoin d'une correspondance clé-valeur ? → map ou unordered_map
std::map<std::string, int> ages;  // Si ordre important
std::unordered_map<std::string, int> cache;  // Si performance importante

// Besoin d'éléments uniques ? → set ou unordered_set
std::set<int> identifiants;

// Besoin d'une file (FIFO) ? → queue
std::queue<Task> taches;

// Besoin d'une pile (LIFO) ? → stack
std::stack<int> pile;

// Taille fixe connue ? → array
std::array<int, 10> scores;
```

## ✅ Bonnes Pratiques

```cpp
// ✅ Réserver de l'espace pour vector
std::vector<int> v;
v.reserve(1000);  // Évite les réallocations

// ✅ Utiliser emplace au lieu de push
v.emplace_back(42);  // Construit directement
// Au lieu de: v.push_back(42);

// ✅ Utiliser const& pour parcourir
for (const auto& element : conteneur) {
    // Pas de copie
}

// ✅ Utiliser structured bindings (C++17)
for (const auto& [key, value] : map) {
    std::cout << key << ": " << value << "\n";
}

// ✅ Vérifier avant d'accéder à map
if (auto it = map.find(key); it != map.end()) {
    // Utiliser it->second
}
```

## 🎯 Exercices

### Exercice 1
Créez un programme qui compte la fréquence de chaque mot dans un texte (utilisez `unordered_map`).

### Exercice 2
Implémentez une file d'attente de tâches (tasks) avec priorités (utilisez `priority_queue`).

### Exercice 3
Créez une classe `Bibliotheque` qui stocke des livres et permet de :
- Ajouter un livre
- Rechercher par titre
- Afficher tous les livres triés par auteur

<details>
<summary>Solution Exercice 1</summary>

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

int main() {
    std::string texte = "le chat mange le poisson le chat dort";
    std::unordered_map<std::string, int> frequences;
    
    std::istringstream iss(texte);
    std::string mot;
    
    while (iss >> mot) {
        frequences[mot]++;
    }
    
    std::cout << "Fréquences des mots:\n";
    for (const auto& [mot, freq] : frequences) {
        std::cout << mot << ": " << freq << "\n";
    }
    
    return 0;
}
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Gestion des Erreurs](04-exceptions-optional.md)
