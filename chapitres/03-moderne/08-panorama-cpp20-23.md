# Panorama C++20/23 : Fonctionnalités Avancées

## 🎯 Objectif

Découvrir les fonctionnalités avancées de C++20/23 (couverture détaillée dans versions futures du cours).

## 🔍 Concepts (C++20)

Les concepts ajoutent des **contraintes** sur les templates et améliorent la lisibilité.

```cpp
#include <type_traits>

template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
T add(T a, T b) {
    return a + b;
}
```

### Concepts standards

- `std::integral`
- `std::floating_point`
- `std::ranges::range`

## 🌊 Ranges (C++20)

Les ranges permettent de créer des **pipelines** d'opérations.

```cpp
#include <ranges>
#include <vector>

std::vector<int> valeurs = {1, 2, 3, 4, 5, 6};

auto resultat = valeurs
    | std::views::filter([](int v) { return v % 2 == 0; })
    | std::views::transform([](int v) { return v * 10; })
    | std::views::take(2);
```

### Avantages

- Code plus lisible
- Évaluation paresseuse (lazy)
- Composition d'opérations

## 📦 Modules (C++20)

### Problèmes des headers classiques

- Recompilation coûteuse
- Ordre d'inclusion fragile
- Conflits de macros

### Solution : modules

```cpp
export module mon_module;

export int addition(int a, int b) {
    return a + b;
}
```

```cpp
import mon_module;

int main() {
    return addition(2, 3);
}
```

## ⚡ Coroutines (C++20)

Les coroutines simplifient l'asynchronisme (promesses, générateurs, pipelines).

```cpp
// Exemple conceptuel : générateur de valeurs
// co_yield permet de produire des valeurs sans bloquer
```

## 🆕 C++23

### std::expected

Alternative aux exceptions pour la gestion d'erreurs.

```cpp
#include <expected>

std::expected<int, std::string> lireValeur();
```

### std::print

Remplacement moderne de `printf`/`std::cout` pour les sorties formatées.

```cpp
#include <print>

std::print("{} + {} = {}\n", 2, 3, 5);
```

### Autres ajouts

- deducing `this`
- `if consteval`
- améliorations des ranges

## 🗺️ Parcours d'apprentissage

1. Maîtriser d'abord C++11/14/17/20 (contenu actuel du cours).
2. Pratiquer avec des projets réels.
3. Explorer concepts/ranges/modules quand les bases sont solides.
4. Attendre la version 2.0 du cours pour les détails avancés.

## 📚 Ressources

- [cppreference.com](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [CppCon Talks](https://www.youtube.com/user/CppCon)

---

✅ **À retenir :** C++20/23 apporte des outils puissants, mais ils deviennent vraiment utiles une fois les bases maîtrisées.
