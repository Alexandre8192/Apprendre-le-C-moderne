# Ranges C++20 - Pipelines de Donnees

## 🎯 Objectif

Maîtriser les **ranges** pour composer des traitements de collections lisibles et expressifs.

## ❓ Pourquoi les ranges ?

Les ranges permettent de chaîner des opérations sans multiplier les boucles manuelles.

Avantages:
- Code plus déclaratif
- Composition simple (`filter`, `transform`, `take`, ...)
- Évaluation paresseuse (lazy)

## 🧱 Vues de base (`std::views`)

```cpp
#include <ranges>
#include <vector>

std::vector<int> valeurs = {1, 2, 3, 4, 5, 6};

auto pipeline = valeurs
    | std::views::filter([](int v) { return v % 2 == 0; })
    | std::views::transform([](int v) { return v * 10; })
    | std::views::take(2);
```

## 🔧 Algorithmes `std::ranges`

Les algorithmes ranges évitent souvent de manipuler explicitement `begin()/end()`.

```cpp
#include <algorithm>
#include <ranges>
#include <vector>

std::vector<int> notes = {12, 18, 10, 15};
std::ranges::sort(notes);  // tri croissant

auto it = std::ranges::find(notes, 15);
bool present = (it != notes.end());
```

## 🔁 Matérialiser une vue

Une vue est souvent "à la demande". Pour stocker le résultat:

```cpp
#include <vector>

std::vector<int> resultat;
for (int v : pipeline) {
    resultat.push_back(v);
}
```

## 💡 Exemple complet

```cpp
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> valeurs = {9, 2, 8, 1, 10, 3, 4, 7, 6, 5};

    auto vue = valeurs
        | std::views::filter([](int v) { return v % 2 == 0; })
        | std::views::transform([](int v) { return v * v; });

    std::vector<int> resultat;
    for (int v : vue) {
        resultat.push_back(v);
    }

    std::ranges::sort(resultat, std::greater<>{});

    std::cout << "Resultat: ";
    for (int v : resultat | std::views::take(3)) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}
```

## ✅ Bonnes pratiques

- Gardez des pipelines courts et lisibles
- Nommez les transformations si elles deviennent complexes
- Évitez de conserver une vue plus longtemps que sa source
- Testez vos pipelines sur des petits jeux de données

## 🎯 Exercices

1. Filtrez une liste de températures pour ne garder que les valeurs positives.
2. Transformez une liste de prix HT en prix TTC.
3. Chaînez `filter + transform + take` sur une liste de scores.

## 📚 Prochaine étape

Passez au chapitre suivant : [Guide des Bonnes Pratiques](../../bonnes-pratiques/README.md)
