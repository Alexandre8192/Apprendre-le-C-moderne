# Exemples de Code C++ Moderne

Ce dossier contient des exemples pratiques de code C++ moderne commentés et fonctionnels.

## 📁 Liste des exemples

### Exemples de base

| Fichier | Description | Concepts |
|---------|-------------|----------|
| [`01-hello-world.cpp`](01-hello-world.cpp) | Premier programme | std::println (C++23), std::cout |
| [`02-variables-types.cpp`](02-variables-types.cpp) | Variables et types | auto, types de base, string |
| [`03-boucles.cpp`](03-boucles.cpp) | Structures de boucles | for, range-based for, while |
| [`04-fonctions.cpp`](04-fonctions.cpp) | Fonctions diverses | templates, constexpr, récursivité |

### Exemples avancés

| Fichier | Description | Concepts |
|---------|-------------|----------|
| [`05-smart-pointers.cpp`](05-smart-pointers.cpp) | Gestion mémoire moderne | unique_ptr, shared_ptr, RAII |
| [`06-lambdas.cpp`](06-lambdas.cpp) | Expressions lambda | Captures, lambdas génériques, STL |
| [`07-gestion-etudiants.cpp`](07-gestion-etudiants.cpp) | Application complète | Classes, smart pointers, lambdas, STL |
| **[`08-poo-polymorphisme.cpp`](08-poo-polymorphisme.cpp)** ✨ NOUVEAU | POO et héritage | Classes, héritage, polymorphisme, virtual |
| **[`09-conteneurs-stl.cpp`](09-conteneurs-stl.cpp)** ✨ NOUVEAU | Conteneurs STL | vector, map, set, unordered_map |

## 🔨 Compilation

### Compiler un exemple spécifique

```bash
# Exemple simple
g++ -std=c++20 02-variables-types.cpp -o variables
./variables

# Avec warnings
g++ -std=c++20 -Wall -Wextra 05-smart-pointers.cpp -o smart
./smart
```

### Compiler tous les exemples

```bash
# Linux/macOS
for file in *.cpp; do
    g++ -std=c++20 -Wall -Wextra "$file" -o "${file%.cpp}"
done

# Nettoyer les exécutables
rm -f 01-hello-world 02-variables-types 03-boucles 04-fonctions \
      05-smart-pointers 06-lambdas 07-gestion-etudiants
```

## 📚 Ordre d'apprentissage recommandé

1. **Débutant** : Exemples 01 à 04
   - Comprenez les bases du langage
   - Maîtrisez les structures de contrôle
   - Pratiquez l'écriture de fonctions

2. **Intermédiaire** : Exemples 05 et 06
   - Apprenez la gestion moderne de la mémoire
   - Utilisez les lambdas et algorithmes STL

3. **Avancé** : Exemple 07
   - Combinez tous les concepts appris
   - Créez des applications complètes

## 💡 Conseils

- **Lisez le code** avant de l'exécuter
- **Modifiez les exemples** pour expérimenter
- **Compilez avec warnings** : `-Wall -Wextra`
- **Testez différents scénarios** pour comprendre le comportement

## 🔗 Ressources

- Pour plus de détails théoriques, consultez le dossier [`chapitres/`](../chapitres/)
- Pour pratiquer, faites les [`exercices/`](../exercices/)
- Pour le style, lisez les [`bonnes-pratiques/`](../bonnes-pratiques/)

## 🆘 Problèmes de compilation ?

Consultez le guide [`COMPILATION.md`](../COMPILATION.md) à la racine du projet.

**Versions minimales requises :**
- GCC 11+ pour C++20
- GCC 13+ pour C++23
- Clang 14+ pour C++20
- Clang 16+ pour C++23
