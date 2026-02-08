# Algorithmes STL - Efficaces et Expressifs

## 🎯 Objectif

Découvrir les algorithmes de la STL pour écrire du code **plus lisible**, **plus sûr** et **plus performant** en C++ moderne.

## 🧭 Pourquoi utiliser les algorithmes ?

Les algorithmes STL permettent de **décrire l'intention** plutôt que la mécanique.

✅ Moins de boucles manuelles
✅ Moins d'erreurs
✅ Code plus clair

## 🗂️ Catégories d'algorithmes

### 🔍 Recherche

Chercher un élément, un motif, ou une condition.

### 🔃 Tri

Trier des éléments selon un ordre naturel ou personnalisé.

### 🔁 Transformation

Créer un résultat à partir d'une collection existante.

### ➕ Agrégation

Calculer une somme, un total, un minimum/maximum, etc.

### 🛠️ Modification

Modifier, filtrer, supprimer des éléments.

## 🔍 Recherche

### Exemple : trouver le premier prix élevé

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<double> prix = {9.99, 14.5, 2.0, 49.0, 12.0};

    auto it = std::find_if(prix.begin(), prix.end(), [](double p) {
        return p > 20.0; // On cherche un prix > 20
    });

    if (it != prix.end()) {
        std::cout << "Premier prix > 20 : " << *it << "\n";
    }
}
```

💡 **Cas d'usage** : détecter le premier produit en promotion ou hors budget.

## 🔃 Tri

### Exemple : trier des utilisateurs par âge décroissant

```cpp
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

struct Utilisateur {
    std::string nom;
    int age;
};

int main() {
    std::vector<Utilisateur> utilisateurs = {
        {"Alice", 30}, {"Bob", 25}, {"Chloé", 40}
    };

    std::sort(utilisateurs.begin(), utilisateurs.end(),
        [](const Utilisateur& a, const Utilisateur& b) {
            return a.age > b.age; // Tri décroissant
        });

    for (const auto& u : utilisateurs) {
        std::cout << u.nom << " (" << u.age << ")\n";
    }
}
```

💡 **Cas d'usage** : afficher un classement, ordonner des résultats.

## 🔁 Transformation

### Exemple : convertir des températures

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<double> celsius = {0.0, 20.0, 37.0};
    std::vector<double> fahrenheit(celsius.size());

    std::transform(celsius.begin(), celsius.end(), fahrenheit.begin(),
        [](double c) {
            return c * 9.0 / 5.0 + 32.0; // Conversion
        });

    for (double f : fahrenheit) {
        std::cout << f << " ";
    }
}
```

💡 **Cas d'usage** : convertir, normaliser, formater des données.

## ➕ Agrégation

### Exemple : somme des ventes du jour

```cpp
#include <numeric>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> ventes = {120, 80, 200, 50};

    int total = std::accumulate(ventes.begin(), ventes.end(), 0,
        [](int acc, int v) {
            return acc + v; // Accumulation
        });

    std::cout << "Total : " << total << "\n";
}
```

💡 **Cas d'usage** : totaux, moyennes, calculs statistiques.

## 🛠️ Modification

### Exemple : supprimer les valeurs négatives

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> valeurs = {5, -3, 2, -1, 8};

    auto fin = std::remove_if(valeurs.begin(), valeurs.end(), [](int v) {
        return v < 0; // On retire les négatifs
    });

    valeurs.erase(fin, valeurs.end()); // Nettoyage final

    for (int v : valeurs) {
        std::cout << v << " ";
    }
}
```

💡 **Cas d'usage** : filtrer, nettoyer des données.

## ✅ Bon vs ❌ Mauvais

### ❌ Mauvais : boucle manuelle

```cpp
int total = 0;
for (int v : ventes) {
    total += v; // On additionne à la main
}
```

### ✅ Bon : algorithme explicite

```cpp
int total = std::accumulate(ventes.begin(), ventes.end(), 0);
```

## 🧪 Exercices progressifs

### 1️⃣ Facile : compter les éléments pairs

Créez un tableau d'entiers et utilisez `std::count_if` pour compter les nombres pairs.

### 2️⃣ Intermédiaire : normaliser des notes

À partir d'une liste de notes sur 20, transformez-les sur 100 avec `std::transform`.

### 3️⃣ Avancé : filtrer et trier

- Garder uniquement les valeurs positives.
- Trier le résultat par ordre décroissant.

💡 Utilisez `std::remove_if` + `erase` puis `std::sort`.
