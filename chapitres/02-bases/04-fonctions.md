# Fonctions en C++

## 🎯 Objectif

Apprendre à créer et utiliser des fonctions pour organiser et réutiliser votre code.

## 📦 Qu'est-ce qu'une fonction ?

Une fonction est un bloc de code réutilisable qui effectue une tâche spécifique.

### Syntaxe de base

```cpp
type_retour nom_fonction(paramètres) {
    // Corps de la fonction
    return valeur;  // Si type_retour != void
}
```

## 💡 Exemples simples

### Fonction sans paramètre ni retour

```cpp
void direBonjour() {
    std::cout << "Bonjour!\n";
}

int main() {
    direBonjour();  // Appel de la fonction
    return 0;
}
```

### Fonction avec paramètres

```cpp
void saluer(std::string nom) {
    std::cout << "Bonjour, " << nom << "!\n";
}

int main() {
    saluer("Alice");
    saluer("Bob");
    return 0;
}
```

### Fonction avec retour

```cpp
int additionner(int a, int b) {
    return a + b;
}

int main() {
    int resultat = additionner(5, 3);
    std::cout << "5 + 3 = " << resultat << "\n";  // 8
    return 0;
}
```

## 🔧 Passage de paramètres

### Passage par valeur (copie)

```cpp
void modifier(int x) {
    x = 100;  // Ne modifie que la copie locale
}

int main() {
    int nombre = 5;
    modifier(nombre);
    std::cout << nombre << "\n";  // Affiche toujours 5
    return 0;
}
```

### Passage par référence (C++11)

```cpp
void modifier(int& x) {
    x = 100;  // Modifie la variable originale
}

int main() {
    int nombre = 5;
    modifier(nombre);
    std::cout << nombre << "\n";  // Affiche 100
    return 0;
}
```

### Passage par référence constante

Efficace pour les gros objets, empêche la modification :

```cpp
void afficher(const std::string& texte) {
    std::cout << texte << "\n";
    // texte = "autre";  // ERREUR : ne peut pas modifier
}
```

## ✨ Fonctionnalités modernes

### Valeurs par défaut

```cpp
void afficherMessage(std::string message = "Hello", int fois = 1) {
    for (int i = 0; i < fois; i++) {
        std::cout << message << "\n";
    }
}

int main() {
    afficherMessage();                  // "Hello" 1 fois
    afficherMessage("Bonjour");         // "Bonjour" 1 fois
    afficherMessage("Hi", 3);           // "Hi" 3 fois
    return 0;
}
```

### Auto return type (C++14)

```cpp
auto multiplier(int a, int b) {
    return a * b;  // Type déduit automatiquement (int)
}

auto calculer(double x) {
    return x * 2.5;  // Type déduit : double
}
```

### Trailing return type (C++11)

```cpp
auto additionner(int a, int b) -> int {
    return a + b;
}
```

### constexpr functions (C++11/14/20)

Fonctions évaluées à la compilation :

```cpp
constexpr int carre(int n) {
    return n * n;
}

int main() {
    constexpr int resultat = carre(5);  // Calculé à la compilation
    // Équivalent à : constexpr int resultat = 25;
    return 0;
}
```

## 🎭 Surcharge de fonctions (Overloading)

Plusieurs fonctions avec le même nom mais des paramètres différents :

```cpp
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

double maximum(double a, double b) {
    return (a > b) ? a : b;
}

int maximum(int a, int b, int c) {
    return maximum(maximum(a, b), c);
}

int main() {
    std::cout << maximum(5, 10) << "\n";        // Appelle int version
    std::cout << maximum(5.5, 3.2) << "\n";     // Appelle double version
    std::cout << maximum(1, 5, 3) << "\n";      // Appelle version à 3 params
    return 0;
}
```

## 🔄 Récursivité

Une fonction qui s'appelle elle-même :

```cpp
// Factorielle : n! = n × (n-1) × ... × 1
int factorielle(int n) {
    if (n <= 1) {
        return 1;  // Cas de base
    }
    return n * factorielle(n - 1);  // Appel récursif
}

int main() {
    std::cout << "5! = " << factorielle(5) << "\n";  // 120
    return 0;
}
```

## 📋 Templates de fonctions (C++11)

Fonctions génériques pour tout type :

```cpp
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maximum(5, 10) << "\n";          // int
    std::cout << maximum(5.5, 3.2) << "\n";       // double
    std::cout << maximum('a', 'z') << "\n";       // char
    return 0;
}
```

## 💡 Exemple complet : Calculatrice modulaire

```cpp
#include <iostream>
#include <cmath>

double addition(double a, double b) { return a + b; }
double soustraction(double a, double b) { return a - b; }
double multiplication(double a, double b) { return a * b; }
double division(double a, double b) { 
    return (b != 0) ? a / b : 0.0;
}

void afficherMenu() {
    std::cout << "\n=== Calculatrice ===\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Soustraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "0. Quitter\n";
    std::cout << "Choix : ";
}

int main() {
    double a, b, resultat;
    int choix;
    
    do {
        afficherMenu();
        std::cin >> choix;
        
        if (choix >= 1 && choix <= 4) {
            std::cout << "Entrez deux nombres : ";
            std::cin >> a >> b;
            
            switch (choix) {
                case 1: resultat = addition(a, b); break;
                case 2: resultat = soustraction(a, b); break;
                case 3: resultat = multiplication(a, b); break;
                case 4: resultat = division(a, b); break;
            }
            
            std::cout << "Résultat : " << resultat << "\n";
        }
    } while (choix != 0);
    
    std::cout << "Au revoir!\n";
    return 0;
}
```

## 🎯 Exercices

### Exercice 1
Écrivez une fonction `estPair` qui retourne `true` si un nombre est pair.

### Exercice 2
Créez une fonction `puissance(base, exposant)` qui calcule base^exposant.

### Exercice 3
Écrivez une fonction récursive `fibonacci(n)` qui calcule le n-ième nombre de Fibonacci.

<details>
<summary>Solution Exercice 2</summary>

```cpp
double puissance(double base, int exposant) {
    double resultat = 1.0;
    for (int i = 0; i < exposant; i++) {
        resultat *= base;
    }
    return resultat;
}

// Version récursive
double puissanceRec(double base, int exposant) {
    if (exposant == 0) return 1.0;
    return base * puissanceRec(base, exposant - 1);
}
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Classes et Objets](05-classes-objets.md)
