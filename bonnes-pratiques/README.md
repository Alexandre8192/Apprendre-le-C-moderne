# Guide des Bonnes Pratiques C++ Moderne

[⬅️ Retour au README principal](../README.md) | [📘 Chapitres](../chapitres/) | [💻 Exemples](../exemples/) | [🧪 Exercices](../exercices/)

## 🎯 Objectif

Ce guide présente les meilleures pratiques pour écrire du code C++ moderne, sûr, et maintenable.

## 📋 Table des matières

1. [Style de Code](#style-de-code)
2. [Gestion de la Mémoire](#gestion-de-la-mémoire)
3. [Types et Variables](#types-et-variables)
4. [Fonctions](#fonctions)
5. [Gestion des Erreurs](#gestion-des-erreurs)
6. [Performance](#performance)
7. [Compilation et Flags](#compilation-et-flags)
8. [Organisation du Code](#organisation-du-code)
9. [Documentation](#documentation)
10. [Tests](#tests)

---

## Style de Code

### ✅ Nommage

```cpp
// ✅ BON : Noms descriptifs
int nombreEtudiants = 25;
std::string nomUtilisateur = "Alice";

// ❌ MAUVAIS : Noms cryptiques
int n = 25;
std::string s = "Alice";

// Convention : snake_case ou camelCase (soyez cohérent)
int nombre_etudiants;  // snake_case
int nombreEtudiants;   // camelCase

// Classes : PascalCase
class GestionnaireUtilisateurs { };

// Constantes : MAJUSCULES ou kPascalCase
const int MAX_TAILLE = 100;
constexpr int kMaxTaille = 100;
```

### ✅ Formatage

```cpp
// ✅ BON : Code bien formaté
if (condition) {
    faire_quelque_chose();
    faire_autre_chose();
}

// ❌ MAUVAIS : Code mal formaté
if(condition){faire_quelque_chose();faire_autre_chose();}
```

**Outil recommandé :** `clang-format` pour formater automatiquement

---

## Gestion de la Mémoire

### ✅ Utiliser les Smart Pointers

```cpp
// ✅ BON : Smart pointers
auto ptr = std::make_unique<int>(42);
auto shared = std::make_shared<int>(42);

// ❌ MAUVAIS : Pointeurs bruts avec new/delete
int* ptr = new int(42);
delete ptr;  // Risque d'oubli !
```

### ✅ RAII (Resource Acquisition Is Initialization)

```cpp
// ✅ BON : RAII
class Fichier {
public:
    Fichier(const std::string& nom) : fichier_(nom) {
        if (!fichier_.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir le fichier");
        }
    }
    
    ~Fichier() {
        // Fermeture automatique
    }

private:
    std::fstream fichier_;
};

// ❌ MAUVAIS : Gestion manuelle
FILE* f = fopen("file.txt", "r");
// ... code qui peut lancer une exception
fclose(f);  // Peut ne jamais être appelé !
```

### ✅ Éviter les fuites mémoire

```cpp
// ✅ BON : Conteneurs standards
std::vector<int> nombres = {1, 2, 3, 4, 5};
// Libération automatique

// ✅ BON : String au lieu de char*
std::string texte = "Hello";
// Pas de gestion manuelle

// ❌ MAUVAIS : Allocation manuelle
int* array = new int[100];
// ... risque d'oubli de delete[] !
```

---

## Types et Variables

### ✅ Initialisation uniforme

```cpp
// ✅ BON : Initialisation uniforme (C++11)
int x{42};
double pi{3.14159};
std::vector<int> nombres{1, 2, 3, 4, 5};

// ❌ Peut causer des problèmes
int a(3.14);  // a = 3, perte de données silencieuse
int b{3.14};  // ERREUR de compilation (bon !)
```

### ✅ Utiliser auto quand approprié

```cpp
// ✅ BON : Type évident grâce à auto
auto nom = std::string{"Alice"};
auto nombres = std::vector<int>{1, 2, 3};

// ✅ BON : Évite la répétition
auto ptr = std::make_unique<MaClasse>();
// Au lieu de : std::unique_ptr<MaClasse> ptr = std::make_unique<MaClasse>();

// ❌ Moins clair sans contexte
auto x = 42;  // int
auto y = 42.0;  // double - attention !
```

### ✅ Const-correctness

```cpp
// ✅ BON : Utiliser const autant que possible
const int MAX = 100;
constexpr double PI = 3.14159;

void afficher(const std::string& texte) {  // Paramètre constant
    std::cout << texte << "\n";
}

// Méthodes const
class Point {
public:
    int getX() const { return x_; }  // Ne modifie pas l'objet
    void setX(int x) { x_ = x; }     // Modifie l'objet

private:
    int x_;
};
```

### ✅ Éviter les variables globales

```cpp
// ❌ MAUVAIS : Variables globales
int compteur = 0;  // État global, difficile à maintenir

// ✅ BON : Variables locales ou membres de classe
class Compteur {
public:
    void incrementer() { ++valeur_; }
    int obtenir() const { return valeur_; }

private:
    int valeur_ = 0;
};
```

---

## Fonctions

### ✅ Fonctions courtes et focalisées

```cpp
// ✅ BON : Fonction fait une seule chose
bool estPair(int n) {
    return n % 2 == 0;
}

// ❌ MAUVAIS : Fonction fait trop de choses
void traitementComplexe() {
    // 200 lignes de code...
}
```

### ✅ Paramètres par référence const

```cpp
// ✅ BON : Efficace, pas de copie
void traiter(const std::vector<int>& donnees) {
    for (const auto& element : donnees) {
        // ...
    }
}

// ❌ MAUVAIS : Copie inutile
void traiter(std::vector<int> donnees) {  // Copie tout le vecteur !
    // ...
}
```

### ✅ Retourner par valeur (RVO/NRVO)

```cpp
// ✅ BON : Le compilateur optimise (RVO)
std::vector<int> creerVecteur() {
    std::vector<int> resultat;
    // ... remplir le vecteur
    return resultat;  // Pas de copie grâce à RVO !
}

// ❌ Pas nécessaire
void creerVecteur(std::vector<int>& out) {  // Style C ancien
    // ...
}
```

---

## Gestion des Erreurs

### ✅ Utiliser les exceptions pour les erreurs exceptionnelles

```cpp
// ✅ BON : Exception pour erreur grave
class Fichier {
public:
    Fichier(const std::string& nom) {
        if (!ouvrir(nom)) {
            throw std::runtime_error("Impossible d'ouvrir le fichier");
        }
    }
};

// ✅ BON : Code de retour pour conditions normales
std::optional<int> trouverElement(const std::vector<int>& v, int valeur) {
    auto it = std::find(v.begin(), v.end(), valeur);
    if (it != v.end()) {
        return *it;
    }
    return std::nullopt;  // Pas trouvé (condition normale)
}
```

### ✅ std::optional pour valeurs absentes (C++17)

```cpp
// ✅ BON : std::optional
std::optional<std::string> trouverUtilisateur(int id) {
    if (existe(id)) {
        return obtenirNom(id);
    }
    return std::nullopt;
}

// Utilisation
if (auto nom = trouverUtilisateur(42)) {
    std::cout << "Trouvé: " << *nom << "\n";
} else {
    std::cout << "Non trouvé\n";
}
```

---

## Performance

### ✅ Move semantics

```cpp
// ✅ BON : Utiliser std::move pour les transferts
std::vector<int> source = {1, 2, 3, 4, 5};
std::vector<int> destination = std::move(source);
// source est maintenant vide, pas de copie coûteuse !

// ✅ BON : Retour par valeur avec move
std::unique_ptr<MaClasse> creer() {
    auto obj = std::make_unique<MaClasse>();
    return obj;  // Move automatique
}
```

### ✅ Range-based for avec const&

```cpp
std::vector<std::string> mots = {"hello", "world"};

// ✅ BON : Pas de copie
for (const auto& mot : mots) {
    std::cout << mot << "\n";
}

// ❌ MAUVAIS : Copie chaque string
for (auto mot : mots) {  // Copie !
    std::cout << mot << "\n";
}
```

### ✅ Reserve pour les vecteurs

```cpp
// ✅ BON : Réserver la mémoire à l'avance
std::vector<int> nombres;
nombres.reserve(1000);  // Évite les réallocations
for (int i = 0; i < 1000; ++i) {
    nombres.push_back(i);
}

// ❌ Réallocations multiples
std::vector<int> nombres;
for (int i = 0; i < 1000; ++i) {
    nombres.push_back(i);  // Peut réallouer plusieurs fois
}
```

---

## Compilation et Flags

### ✅ Compiler avec tous les warnings

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -O2 fichier.cpp
```

### ✅ Utiliser les sanitizers en développement

**AddressSanitizer (fuites mémoire, use-after-free)**

```bash
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address fichier.cpp
```

**UndefinedBehaviorSanitizer**

```bash
g++ -std=c++20 -Wall -Wextra -g -fsanitize=undefined fichier.cpp
```

---

## Organisation du Code

### ✅ Séparation headers/implémentation (projets moyens/grands)

Structure recommandée :

```
mon_projet/
├── include/
│   └── gestionnaire.hpp
├── src/
│   └── gestionnaire.cpp
└── main.cpp
```

### ✅ Nommage des fichiers

- Choisir un style unique : `snake_case` ou `PascalCase`.
- Éviter les mélanges dans un même projet.

---

## Documentation

### ✅ Commentaires pertinents

```cpp
// ✅ BON : expliquer le \"pourquoi\"
if (solde < montant) {
    // Empêche un dépassement de découvert
    throw std::runtime_error(\"Solde insuffisant\");
}

// ❌ MAUVAIS : répète le \"quoi\"
solde -= montant;  // Décrémente solde
```

### ✅ Documentation Doxygen (optionnel)

```cpp
/// Calcule la moyenne d'une liste de notes.
/// @param notes Liste des notes (0-20).
/// @return La moyenne, ou 0.0 si liste vide.
double moyenne(const std::vector<double>& notes);
```

---

## Tests

### ✅ Écrire des tests unitaires

Frameworks populaires : **Google Test**, **Catch2**, **doctest**.

```cpp
// Exemple rapide avec doctest
TEST_CASE(\"addition\") {
    CHECK(2 + 2 == 4);
}
```

---

## 📚 Ressources

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/)
- [cppreference.com](https://en.cppreference.com/)

---

## ✅ Checklist rapide

Avant de committer votre code, vérifiez :

- [ ] Noms de variables descriptifs
- [ ] Pas de pointeurs bruts avec new/delete
- [ ] Utilisation de const autant que possible
- [ ] Smart pointers pour la gestion mémoire
- [ ] Fonctions courtes et focalisées
- [ ] Gestion appropriée des erreurs
- [ ] Code formaté (clang-format)
- [ ] Pas d'avertissements de compilation
- [ ] Tests écrits et passants

**Compilez toujours avec warnings activés :**
```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -O2 fichier.cpp
```

---

## 🚀 Prochaine étape

Appliquez ces bonnes pratiques dans vos exercices : [`/exercices`](../exercices/).
