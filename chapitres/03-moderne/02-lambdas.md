# Lambda Expressions - Fonctions Anonymes

## 🎯 Objectif

Maîtriser les expressions lambda (C++11/14/20) pour écrire du code concis et expressif.

## 📖 Qu'est-ce qu'une Lambda ?

Une lambda est une **fonction anonyme** que vous pouvez définir directement dans votre code.

### Syntaxe de base

```cpp
[capture](paramètres) -> type_retour {
    // Corps de la lambda
    return valeur;
}
```

## 💡 Lambda Simple

```cpp
#include <iostream>

int main() {
    // Lambda sans paramètres
    auto saluer = []() {
        std::cout << "Bonjour!\n";
    };
    
    saluer();  // Appel de la lambda
    
    // Lambda avec paramètres
    auto addition = [](int a, int b) {
        return a + b;
    };
    
    std::cout << "5 + 3 = " << addition(5, 3) << "\n";
    
    return 0;
}
```

## 🔒 Captures

Les captures permettent d'accéder aux variables du scope englobant.

### Capture par valeur [=]

```cpp
int multiplicateur = 10;

auto multiplier = [multiplicateur](int x) {
    return x * multiplicateur;  // Copie de multiplicateur
};

std::cout << multiplier(5) << "\n";  // 50
multiplicateur = 20;  // N'affecte pas la lambda
std::cout << multiplier(5) << "\n";  // Toujours 50
```

### Capture par référence [&]

```cpp
int compteur = 0;

auto incrementer = [&compteur]() {
    compteur++;  // Modifie la variable originale
};

incrementer();
incrementer();
std::cout << compteur << "\n";  // 2
```

### Captures multiples

```cpp
int a = 10, b = 20;

// Capturer tout par valeur
auto lambda1 = [=]() { return a + b; };

// Capturer tout par référence
auto lambda2 = [&]() { a++; b++; };

// Capturer a par valeur, b par référence
auto lambda3 = [a, &b]() { b = a * 2; };

// Capturer tout par valeur sauf b par référence
auto lambda4 = [=, &b]() { b = a + 10; };
```

## ✨ Lambda Générique (C++14)

```cpp
// Lambda qui fonctionne avec n'importe quel type
auto afficher = [](const auto& valeur) {
    std::cout << valeur << "\n";
};

afficher(42);          // int
afficher(3.14);        // double
afficher("Hello");     // const char*
afficher(std::string{"World"});  // std::string
```

## 🎯 Utilisation avec les Algorithmes

Les lambdas sont parfaites avec les algorithmes de la STL.

### std::for_each

```cpp
#include <algorithm>
#include <vector>

std::vector<int> nombres = {1, 2, 3, 4, 5};

std::for_each(nombres.begin(), nombres.end(), [](int n) {
    std::cout << n * 2 << " ";
});
// Affiche : 2 4 6 8 10
```

### std::transform

```cpp
std::vector<int> source = {1, 2, 3, 4, 5};
std::vector<int> resultat(source.size());

std::transform(source.begin(), source.end(), resultat.begin(),
    [](int n) { return n * n; });
// resultat = {1, 4, 9, 16, 25}
```

### std::sort

```cpp
std::vector<int> nombres = {5, 2, 8, 1, 9};

// Tri décroissant
std::sort(nombres.begin(), nombres.end(), [](int a, int b) {
    return a > b;
});
// nombres = {9, 8, 5, 2, 1}
```

### std::find_if

```cpp
std::vector<int> nombres = {1, 2, 3, 4, 5, 6};

auto it = std::find_if(nombres.begin(), nombres.end(), [](int n) {
    return n > 3;
});

if (it != nombres.end()) {
    std::cout << "Premier nombre > 3 : " << *it << "\n";  // 4
}
```

### std::count_if

```cpp
std::vector<int> nombres = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int pairs = std::count_if(nombres.begin(), nombres.end(), [](int n) {
    return n % 2 == 0;
});

std::cout << "Nombres pairs : " << pairs << "\n";  // 5
```

## 🔄 Lambda Récursive (C++23)

```cpp
// Avec auto
auto factorielle = [](this auto self, int n) -> int {
    if (n <= 1) return 1;
    return n * self(n - 1);
};

std::cout << factorielle(5) << "\n";  // 120
```

## 💼 Lambda comme Callback

```cpp
#include <functional>
#include <iostream>

void traiter(int valeur, std::function<void(int)> callback) {
    callback(valeur);
}

int main() {
    traiter(42, [](int x) {
        std::cout << "Valeur reçue : " << x << "\n";
    });
    
    return 0;
}
```

## 🎨 Lambdas et std::ranges (C++20)

```cpp
#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nombres = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Pipeline avec lambdas
    auto resultat = nombres 
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; })
        | std::views::take(3);
    
    for (int n : resultat) {
        std::cout << n << " ";  // 4 16 36
    }
    
    return 0;
}
```

## 💡 Exemple Complet : Gestionnaire d'Événements

```cpp
#include <iostream>
#include <vector>
#include <functional>
#include <string>

class Bouton {
public:
    using Callback = std::function<void()>;
    
    void onClick(Callback callback) {
        callbacks_.push_back(callback);
    }
    
    void cliquer() {
        std::cout << "Bouton cliqué!\n";
        for (const auto& callback : callbacks_) {
            callback();
        }
    }

private:
    std::vector<Callback> callbacks_;
};

int main() {
    Bouton bouton;
    
    int compteur = 0;
    
    // Ajouter des handlers
    bouton.onClick([&compteur]() {
        compteur++;
        std::cout << "Compteur : " << compteur << "\n";
    });
    
    bouton.onClick([]() {
        std::cout << "Notification envoyée!\n";
    });
    
    // Simuler des clics
    bouton.cliquer();
    bouton.cliquer();
    
    return 0;
}
```

## 🎯 Bonnes Pratiques

### ✅ Préférer auto pour le type

```cpp
// ✅ BON
auto lambda = [](int x) { return x * 2; };

// ❌ Verbeux
std::function<int(int)> lambda = [](int x) { return x * 2; };
```

### ✅ Capturer seulement ce qui est nécessaire

```cpp
int a = 10, b = 20, c = 30;

// ✅ BON : Capture explicite
auto lambda = [a, b]() { return a + b; };

// ❌ Capture tout (moins clair)
auto lambda = [=]() { return a + b; };
```

### ✅ Attention aux captures par référence

```cpp
// ❌ DANGEREUX : Référence invalide
auto creerLambda() {
    int valeur = 42;
    return [&valeur]() { return valeur; };  // valeur n'existe plus !
}

// ✅ BON : Capture par valeur
auto creerLambda() {
    int valeur = 42;
    return [valeur]() { return valeur; };  // Copie sûre
}
```

### ✅ Utiliser const pour les lambdas qui ne modifient pas

```cpp
auto lambda = [](const auto& x) {  // const ref évite la copie
    std::cout << x << "\n";
};
```

## 🎯 Exercices

### Exercice 1
Écrivez une lambda qui prend un vecteur et retourne la somme de ses éléments.

### Exercice 2
Créez une lambda qui trie un vecteur de strings par longueur (du plus court au plus long).

### Exercice 3
Utilisez `std::accumulate` avec une lambda pour calculer le produit des éléments d'un vecteur.

<details>
<summary>Solution Exercice 1</summary>

```cpp
#include <vector>
#include <numeric>

auto somme = [](const std::vector<int>& v) {
    return std::accumulate(v.begin(), v.end(), 0);
};

// Utilisation
std::vector<int> nombres = {1, 2, 3, 4, 5};
std::cout << somme(nombres) << "\n";  // 15
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Conteneurs STL](03-conteneurs.md)
