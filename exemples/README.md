# Exemples de Code C++ Moderne

[⬅️ Retour au README principal](../README.md) | [📘 Chapitres](../chapitres/) | [🧪 Exercices](../exercices/) | [🛠️ Compilation](../COMPILATION.md)

Ce dossier contient des exemples pratiques de code C++ moderne commentés et fonctionnels.

## 📁 Liste des exemples

### Exemples de base

| Fichier | Description | Concepts |
|---------|-------------|----------|
| [`01-hello-world.cpp`](01-hello-world.cpp) | Premier programme | std::println (C++23 si dispo), std::cout |
| [`02-variables-types.cpp`](02-variables-types.cpp) | Variables et types | auto, types de base, string |
| [`03-boucles.cpp`](03-boucles.cpp) | Structures de boucles | for, range-based for, while |
| [`04-fonctions.cpp`](04-fonctions.cpp) | Fonctions diverses | templates, constexpr, récursivité |

### Exemples avancés

| Fichier | Description | Concepts |
|---------|-------------|----------|
| [`05-smart-pointers.cpp`](05-smart-pointers.cpp) | Gestion mémoire moderne | unique_ptr, shared_ptr, RAII |
| [`06-lambdas.cpp`](06-lambdas.cpp) | Expressions lambda | Captures, lambdas génériques, STL |
| [`07-gestion-etudiants.cpp`](07-gestion-etudiants.cpp) | Application complète | Classes, smart pointers, lambdas, STL |
| [`08-poo-polymorphisme.cpp`](08-poo-polymorphisme.cpp) | POO et héritage | Classes, héritage, polymorphisme, virtual |
| [`09-conteneurs-stl.cpp`](09-conteneurs-stl.cpp) | Conteneurs STL | vector, map, set, unordered_map |
| [`10-algorithmes-stl.cpp`](10-algorithmes-stl.cpp) | Algorithmes STL | sort, find_if, copy_if, accumulate |
| [`11-fichiers-io.cpp`](11-fichiers-io.cpp) | I/O modernes | fstream, filesystem, CSV |
| [`12-concepts.cpp`](12-concepts.cpp) | Concepts C++20 | requires, concepts, contraintes |
| [`13-ranges.cpp`](13-ranges.cpp) | Ranges C++20 | views, pipelines, ranges::sort |

## 🔨 Compilation

### Compiler un exemple spécifique

```bash
# Exemple simple
g++ -std=c++20 02-variables-types.cpp -o variables
./variables

# Avec warnings
g++ -std=c++20 -Wall -Wextra -Wpedantic 05-smart-pointers.cpp -o smart
./smart
```

### Compiler tous les exemples

```bash
# Linux/macOS
for file in *.cpp; do
    g++ -std=c++20 -Wall -Wextra -Wpedantic "$file" -o "${file%.cpp}"
done

# Nettoyer les exécutables
rm -f 01-hello-world 02-variables-types 03-boucles 04-fonctions \
      05-smart-pointers 06-lambdas 07-gestion-etudiants 08-poo-polymorphisme \
      09-conteneurs-stl 10-algorithmes-stl 11-fichiers-io 12-concepts 13-ranges
```

## 📚 Ordre d'apprentissage recommandé

1. **Débutant** : Exemples 01 à 04
2. **Intermédiaire** : Exemples 05 à 06
3. **Avancé** : Exemples 07 à 13

## 💡 Conseils

- Lisez le code avant de l'exécuter
- Modifiez les exemples pour expérimenter
- Compilez avec warnings : `-Wall -Wextra -Wpedantic`
- Testez différents scénarios

## 🔗 Ressources

- Théorie : [`/chapitres`](../chapitres/)
- Exercices : [`/exercices`](../exercices/)
- Style : [`/bonnes-pratiques`](../bonnes-pratiques/)

## 🚀 Prochaine étape

Après un exemple, tentez l'exercice correspondant dans [`/exercices`](../exercices/).
