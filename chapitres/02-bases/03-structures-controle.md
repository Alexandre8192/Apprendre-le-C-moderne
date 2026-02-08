# Structures de Contrôle

## 🎯 Objectif

Apprendre à contrôler le flux d'exécution de vos programmes avec les structures conditionnelles et les boucles.

## 🔀 Structure conditionnelle : if / else

### Syntaxe de base

```cpp
if (condition) {
    // Code exécuté si la condition est vraie
}

if (condition) {
    // Code si vrai
} else {
    // Code si faux
}

if (condition1) {
    // Code si condition1 est vraie
} else if (condition2) {
    // Code si condition2 est vraie
} else {
    // Code si toutes les conditions sont fausses
}
```

### Exemples

```cpp
int age = 18;

if (age >= 18) {
    std::cout << "Vous êtes majeur.\n";
} else {
    std::cout << "Vous êtes mineur.\n";
}

// Conditions multiples
int note = 85;

if (note >= 90) {
    std::cout << "Excellent!\n";
} else if (note >= 70) {
    std::cout << "Bien!\n";
} else if (note >= 50) {
    std::cout << "Passable.\n";
} else {
    std::cout << "Insuffisant.\n";
}
```

## ✨ if avec initialisation (C++17)

```cpp
if (auto resultat = calculer(); resultat > 0) {
    std::cout << "Résultat positif : " << resultat << "\n";
} else {
    std::cout << "Résultat négatif ou nul : " << resultat << "\n";
}
// resultat n'est plus accessible ici
```

## 🔄 Structure switch

Utile pour tester plusieurs valeurs constantes :

```cpp
int jour = 3;

switch (jour) {
    case 1:
        std::cout << "Lundi\n";
        break;
    case 2:
        std::cout << "Mardi\n";
        break;
    case 3:
        std::cout << "Mercredi\n";
        break;
    case 4:
        std::cout << "Jeudi\n";
        break;
    case 5:
        std::cout << "Vendredi\n";
        break;
    case 6:
    case 7:
        std::cout << "Week-end!\n";
        break;
    default:
        std::cout << "Jour invalide\n";
        break;
}
```

**Important :** N'oubliez pas le `break` pour éviter le "fall-through" !

## 🔁 Boucle while

Répète tant qu'une condition est vraie :

```cpp
int compteur = 0;
while (compteur < 5) {
    std::cout << "Compteur : " << compteur << "\n";
    compteur++;
}
```

## 🔂 Boucle do-while

Exécute au moins une fois, puis répète tant que la condition est vraie :

```cpp
int nombre;
do {
    std::cout << "Entrez un nombre positif : ";
    std::cin >> nombre;
} while (nombre <= 0);
```

## 🔃 Boucle for

La boucle la plus utilisée :

```cpp
// Syntaxe classique
for (int i = 0; i < 10; i++) {
    std::cout << i << " ";
}
// Affiche : 0 1 2 3 4 5 6 7 8 9

// Parcourir à l'envers
for (int i = 10; i >= 0; i--) {
    std::cout << i << " ";
}

// Pas de 2
for (int i = 0; i < 10; i += 2) {
    std::cout << i << " ";  // 0 2 4 6 8
}
```

## ✨ Boucle for basée sur plage (C++11)

Simplifie l'itération sur des conteneurs :

```cpp
#include <vector>

std::vector<int> nombres = {1, 2, 3, 4, 5};

// Lecture seule
for (int nombre : nombres) {
    std::cout << nombre << " ";
}

// Avec référence (modification possible)
for (int& nombre : nombres) {
    nombre *= 2;  // Double chaque élément
}

// Avec const& (efficace, lecture seule)
for (const auto& nombre : nombres) {
    std::cout << nombre << " ";
}
```

## 🛑 Contrôle de boucle : break et continue

### break : Sortir de la boucle

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // Sort de la boucle quand i vaut 5
    }
    std::cout << i << " ";
}
// Affiche : 0 1 2 3 4
```

### continue : Passer à l'itération suivante

```cpp
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // Saute les nombres pairs
    }
    std::cout << i << " ";
}
// Affiche : 1 3 5 7 9
```

## 💡 Exemple complet : Table de multiplication

```cpp
#include <iostream>

int main() {
    int nombre;
    std::cout << "Entrez un nombre : ";
    std::cin >> nombre;
    
    std::cout << "\nTable de multiplication de " << nombre << " :\n";
    for (int i = 1; i <= 10; i++) {
        std::cout << nombre << " × " << i << " = " << (nombre * i) << "\n";
    }
    
    return 0;
}
```

## 🎯 Exercices

### Exercice 1 : FizzBuzz
Écrivez un programme qui affiche les nombres de 1 à 100 avec les règles suivantes :
- Si le nombre est divisible par 3, affichez "Fizz"
- Si le nombre est divisible par 5, affichez "Buzz"
- Si le nombre est divisible par 3 et 5, affichez "FizzBuzz"
- Sinon, affichez le nombre

### Exercice 2 : Calculer une somme
Écrivez un programme qui demande à l'utilisateur d'entrer des nombres jusqu'à ce qu'il entre 0, puis affiche leur somme.

### Exercice 3 : Nombre premier
Écrivez une fonction qui détermine si un nombre est premier.

<details>
<summary>Solution Exercice 1 (FizzBuzz)</summary>

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 15 == 0) {
            std::cout << "FizzBuzz\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << i << "\n";
        }
    }
    return 0;
}
```
</details>

<details>
<summary>Solution Exercice 2 (Somme)</summary>

```cpp
#include <iostream>

int main() {
    int nombre, somme = 0;
    
    std::cout << "Entrez des nombres (0 pour terminer) :\n";
    while (true) {
        std::cin >> nombre;
        if (nombre == 0) break;
        somme += nombre;
    }
    
    std::cout << "Somme totale : " << somme << "\n";
    return 0;
}
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Fonctions](04-fonctions.md)
