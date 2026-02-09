# Concepts C++20 - Contraindre les Templates

## 🎯 Objectif

Apprendre à utiliser les **concepts** pour écrire des templates plus lisibles, plus sûrs et avec de meilleurs messages d'erreur.

## ❓ Pourquoi les concepts ?

Avant C++20, les erreurs de templates pouvaient être longues et difficiles à comprendre.

Les concepts permettent de dire clairement:
- Quels types sont acceptés
- Quelles opérations sont requises
- Pourquoi un appel est refusé

## 🧱 Syntaxe de base

```cpp
#include <concepts>

template<typename T>
concept Entier = std::integral<T>;

template<Entier T>
T incrementer(T valeur) {
    return valeur + 1;
}
```

Version équivalente avec `requires`:

```cpp
template<typename T>
requires std::integral<T>
T decrementer(T valeur) {
    return valeur - 1;
}
```

## 📚 Concepts standards utiles

```cpp
#include <concepts>

std::integral<int>;          // vrai
std::floating_point<double>; // vrai
std::same_as<int, int>;      // vrai
std::convertible_to<int, double>; // vrai
```

## 🛠️ Créer un concept personnalisé

```cpp
#include <concepts>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T somme(T a, T b) {
    return a + b;
}
```

## 🔎 Contraindre des opérations

```cpp
#include <concepts>

template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Comparable T>
const T& minimum(const T& a, const T& b) {
    return (b < a) ? b : a;
}
```

## 💡 Exemple complet

```cpp
#include <concepts>
#include <iostream>
#include <vector>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T moyenne(const std::vector<T>& valeurs) {
    if (valeurs.empty()) {
        return T{};
    }

    T somme = T{};
    for (const auto& v : valeurs) {
        somme += v;
    }
    return somme / static_cast<T>(valeurs.size());
}

int main() {
    std::vector<int> notes = {12, 14, 16, 18};
    std::cout << "Moyenne: " << moyenne(notes) << "\n";
}
```

## ✅ Bonnes pratiques

- Utilisez d'abord les concepts standards (`std::integral`, `std::ranges::range`, etc.)
- Nommez les concepts avec des noms explicites (`Sortable`, `Hashable`, `Numeric`)
- Préférez `requires` aux astuces SFINAE complexes quand c'est possible

## 🎯 Exercices

1. Créez un concept `Addable` qui vérifie la présence de l'opérateur `+`.
2. Créez une fonction `max3` qui accepte uniquement des types comparables.
3. Créez un concept `Indexable` pour les types supportant `obj[index]`.

## 📚 Prochaine étape

Passez au chapitre suivant : [Ranges C++20](10-ranges.md)
