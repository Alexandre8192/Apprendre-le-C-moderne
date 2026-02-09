# Move Semantics et Rvalue References

## 🎯 Objectif

Comprendre comment C++11 optimise les transferts de ressources.

## 📦 Le problème : copies coûteuses

Avant C++11, les copies pouvaient être très coûteuses.

```cpp
#include <vector>

std::vector<int> creerGrosVecteur() {
    std::vector<int> v(1'000'000, 42);
    return v;  // Copie potentiellement lourde (avant C++11)
}
```

## 🚀 Solution : Move Semantics

### Lvalue vs Rvalue

- **Lvalue** : objet qui a un nom et une adresse persistante.
- **Rvalue** : objet temporaire, destiné à être consommé.

```cpp
int a = 10;         // a est une lvalue
int b = a;          // copie
int c = a + 5;      // a + 5 est une rvalue
```

### std::move

`std::move` ne déplace rien tout seul : il **convertit** une lvalue en rvalue.

```cpp
#include <utility>
#include <vector>

std::vector<int> source = {1, 2, 3};
std::vector<int> cible = std::move(source); // transfert des ressources
```

✅ Quand l'utiliser :
- Quand vous savez que l'objet ne sera plus utilisé.
- Pour optimiser un transfert de ressources.

❌ Quand NE PAS l'utiliser :
- Sur un objet que vous voulez encore lire.
- Sur une variable globale partagée.

## 🔧 Move constructor et move assignment

### Syntaxe

```cpp
class Buffer {
public:
    Buffer(size_t taille)
        : taille_(taille), data_(new int[taille]) {}

    ~Buffer() { delete[] data_; }

    Buffer(const Buffer& other)
        : taille_(other.taille_), data_(new int[other.taille_]) {
        std::copy(other.data_, other.data_ + other.taille_, data_);
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data_;
            taille_ = other.taille_;
            data_ = new int[taille_];
            std::copy(other.data_, other.data_ + other.taille_, data_);
        }
        return *this;
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept
        : taille_(other.taille_), data_(other.data_) {
        other.taille_ = 0;
        other.data_ = nullptr;
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            taille_ = other.taille_;
            data_ = other.data_;
            other.taille_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

private:
    size_t taille_ = 0;
    int* data_ = nullptr;
};
```

## 🏆 Rule of Five

Les 5 fonctions spéciales :
1. Destructeur
2. Copy constructor
3. Copy assignment
4. Move constructor
5. Move assignment

Quand les définir :
- **Rule of Zero** : utiliser des types RAII (ex : `std::vector`) et ne rien définir.
- **Rule of Five** : lorsque vous gérez une ressource manuellement.

## 💡 Exemples pratiques

1. **Classe String simplifiée avec move**
   - Implémenter une classe `String` qui déplace son buffer.
2. **Retour de gros objets sans copie**
   - Retourner un `std::vector` ou `std::string` par valeur.
3. **std::move avec conteneurs**
   - Déplacer un `std::vector` dans une fonction pour éviter la copie.

## ⚠️ Pièges courants

- `std::move` ne garantit pas un move : il permet le move si disponible.
- Un objet déplacé reste **valide** mais dans un état indéterminé.
- Ne pas utiliser un objet après `std::move` (sauf réassignation).

## 🎯 Exercices

1. Implémenter le move constructor et move assignment pour une classe `Buffer`.
2. Optimiser un programme qui copie inutilement un `std::vector`.
3. Modifier une fonction pour accepter un paramètre par valeur + `std::move`.

---

✅ **À retenir :** les move semantics réduisent les copies et améliorent les performances.
