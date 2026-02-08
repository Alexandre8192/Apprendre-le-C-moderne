# Variables et Types de Données

## 🎯 Objectif

Comprendre les variables et les différents types de données en C++ moderne.

## 📦 Qu'est-ce qu'une variable ?

Une variable est un espace mémoire nommé qui stocke une valeur. En C++, chaque variable a un **type** qui détermine :
- La taille en mémoire
- Les opérations possibles
- La plage de valeurs acceptées

## 🔢 Types de base (Built-in types)

### Types entiers

```cpp
int age = 25;              // Entier signé (généralement 32 bits)
unsigned int score = 100;  // Entier non signé
long population = 8000000; // Entier long
short petitNombre = 42;    // Entier court

// C++23 : types de taille fixe (recommandé)
#include <cstdint>
int32_t x = 42;            // Exactement 32 bits
uint64_t grand = 1000000;  // 64 bits non signé
```

### Types à virgule flottante

```cpp
float pi = 3.14f;          // Précision simple (32 bits)
double precis = 3.14159;   // Précision double (64 bits, recommandé)
long double tresPrecis = 3.14159265358979L;
```

### Types de caractères

```cpp
char lettre = 'A';         // Un caractère ASCII (8 bits)
char8_t utf8 = u8'€';      // C++20 : UTF-8
char16_t utf16 = u'€';     // UTF-16
char32_t utf32 = U'€';     // UTF-32
```

### Type booléen

```cpp
bool estVrai = true;
bool estFaux = false;
```

## ✨ Déduction de type avec `auto` (C++11/14)

Le compilateur peut déduire automatiquement le type :

```cpp
auto nombre = 42;           // int
auto prix = 19.99;          // double
auto nom = "Alice";         // const char*
auto message = std::string{"Hello"};  // std::string

// C++20 : auto dans les paramètres de fonction
auto addition(auto a, auto b) {
    return a + b;
}
```

## 📝 Déclaration et initialisation

### ❌ Mauvaise pratique
```cpp
int x;  // Non initialisé - valeur indéfinie !
```

### ✅ Bonnes pratiques

```cpp
int x = 42;                 // Initialisation par copie
int y(42);                  // Initialisation par constructeur
int z{42};                  // Initialisation uniforme (C++11, recommandé)
auto w = 42;                // Déduction de type

// Initialisation uniforme évite les conversions dangereuses
int a{3.14};  // Erreur : perte de précision
int b(3.14);  // Accepté mais mauvais : b vaut 3
```

## 🔒 Variables constantes

```cpp
const int MAX = 100;        // Constante à la compilation
constexpr int TAILLE = 50;  // C++11 : évalué à la compilation

// C++20 : consteval force l'évaluation à la compilation
consteval int carre(int n) {
    return n * n;
}
constexpr int resultat = carre(5);  // 25
```

## 📊 Type string (chaînes de caractères)

```cpp
#include <string>

std::string nom = "Alice";
std::string prenom{"Bob"};  // Initialisation uniforme

// Concaténation
std::string complet = nom + " et " + prenom;

// Méthodes utiles
int longueur = nom.length();
bool vide = nom.empty();
nom.append(" Dupont");
```

## 💡 Exemple complet

```cpp
#include <iostream>
#include <string>

int main() {
    // Variables de différents types
    auto nom = std::string{"Alice"};
    auto age = 25;
    auto taille = 1.65;
    const auto ville = "Paris";
    
    // Affichage
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Age : " << age << " ans\n";
    std::cout << "Taille : " << taille << " m\n";
    std::cout << "Ville : " << ville << "\n";
    
    return 0;
}
```

## 🎯 Exercices

### Exercice 1
Créez un programme qui déclare des variables pour stocker :
- Votre nom (string)
- Votre âge (int)
- Votre taille en mètres (double)
- Si vous aimez le C++ (bool)

Affichez toutes ces informations.

### Exercice 2
Sans exécuter le code, déterminez le type de chaque variable :
```cpp
auto a = 42;
auto b = 42.0;
auto c = 42.0f;
auto d = "Hello";
auto e = std::string{"Hello"};
```

<details>
<summary>Solution Exercice 1</summary>

```cpp
#include <iostream>
#include <string>

int main() {
    auto nom = std::string{"Alice"};
    auto age = 25;
    auto taille = 1.65;
    auto aimeCpp = true;
    
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Age : " << age << "\n";
    std::cout << "Taille : " << taille << " m\n";
    std::cout << "Aime C++ : " << (aimeCpp ? "Oui" : "Non") << "\n";
    
    return 0;
}
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Opérateurs](02-operateurs.md)
