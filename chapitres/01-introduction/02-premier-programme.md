# Votre premier programme C++

## 🎯 Objectif

Écrire, compiler et exécuter votre premier programme C++.

## 📝 Hello, World!

Créons le programme classique "Hello, World!" en version moderne :

```cpp
#include <iostream>
#include <print>  // C++23

int main() {
    std::println("Hello, World!");
    return 0;
}
```

### Explication ligne par ligne

```cpp
#include <iostream>  // Inclut la bibliothèque d'entrée/sortie
#include <print>     // Inclut la nouvelle bibliothèque print (C++23)
```
- Les directives `#include` permettent d'utiliser des fonctionnalités de la bibliothèque standard.

```cpp
int main() {
    // Code ici
    return 0;
}
```
- `main()` est le point d'entrée de votre programme.
- `int` signifie que la fonction retourne un entier.
- `return 0;` indique que le programme s'est terminé avec succès.

```cpp
std::println("Hello, World!");
```
- `std::println` (C++23) affiche du texte suivi d'un retour à la ligne.
- Alternative C++20 : `std::cout << "Hello, World!\n";`

## 🔨 Compilation

### Méthode simple (un seul fichier)

```bash
g++ -std=c++23 hello.cpp -o hello
./hello
```

### Méthode avec flags de compilation recommandés

```bash
g++ -std=c++23 -Wall -Wextra -O2 hello.cpp -o hello
./hello
```

**Explications des flags :**
- `-std=c++23` : Utilise le standard C++23
- `-Wall -Wextra` : Active les avertissements (warnings)
- `-O2` : Optimise le code

## 💡 Version avec variable

```cpp
#include <iostream>
#include <string>

int main() {
    std::string nom = "Alice";
    std::cout << "Bonjour, " << nom << "!\n";
    return 0;
}
```

## 🎯 Exercice

Modifiez le programme pour :
1. Demander votre nom à l'utilisateur
2. Afficher un message personnalisé

**Indice :** Utilisez `std::cin` pour lire l'entrée utilisateur.

<details>
<summary>Solution</summary>

```cpp
#include <iostream>
#include <string>

int main() {
    std::string nom;
    std::cout << "Entrez votre nom : ";
    std::cin >> nom;
    std::cout << "Bonjour, " << nom << "!\n";
    return 0;
}
```
</details>

## 📚 Prochaine étape

Passez au [Chapitre 2 : Les bases du C++](../02-bases/01-variables.md)
