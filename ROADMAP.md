# 🗺️ Feuille de Route du Cours

Ce document présente l'évolution du cours et les fonctionnalités à venir.

## ✅ Contenu Actuel (Version 1.1)

### Chapitres Disponibles

#### Chapitre 1 : Introduction (2 leçons)
- ✅ Installation et configuration
- ✅ Premier programme C++

#### Chapitre 2 : Les Bases (6 leçons)
- ✅ Variables et types
- ✅ Opérateurs
- ✅ Structures de contrôle
- ✅ Fonctions
- ✅ Classes et objets **NOUVEAU v1.1**
- ✅ Héritage et polymorphisme **NOUVEAU v1.1**

#### Chapitre 3 : C++ Moderne (4 leçons)
- ✅ Smart pointers
- ✅ Lambda expressions
- ✅ Conteneurs STL **NOUVEAU v1.1**
- ✅ Gestion des erreurs **NOUVEAU v1.1**

#### Chapitre 4 : Bonnes Pratiques (1 guide)
- ✅ Guide complet des bonnes pratiques

### Exemples de Code (9 programmes)
1. ✅ Hello World
2. ✅ Variables et types
3. ✅ Boucles
4. ✅ Fonctions
5. ✅ Smart pointers
6. ✅ Lambdas
7. ✅ Gestion d'étudiants
8. ✅ POO et polymorphisme **NOUVEAU v1.1**
9. ✅ Conteneurs STL **NOUVEAU v1.1**

### Exercices (20 exercices)
- ✅ 8 exercices débutants
- ✅ 12 exercices intermédiaires **+2 en v1.1**

---

## 🚀 Prochaines Priorités (Version 1.2)

### Contenu Essentiel Manquant

#### 1. Entrées/Sorties et Fichiers (Priorité HAUTE)
```cpp
// À couvrir
- Lecture/écriture de fichiers (fstream)
- Manipulation de chemins (filesystem C++17)
- Sérialisation simple
- std::format (C++20)
```

#### 2. Algorithmes STL (Priorité HAUTE)
```cpp
// À couvrir
- sort, find, count, accumulate
- transform, filter (avec lambdas)
- binary_search, lower_bound
- Algorithmes numériques
```

#### 3. Move Semantics (Priorité MOYENNE)
```cpp
// À couvrir
- Lvalue vs rvalue
- std::move et std::forward
- Rule of Five
- Move constructors
```

#### 4. Templates Avancés (Priorité MOYENNE)
```cpp
// À couvenir
- Templates de classes
- Spécialisation de templates
- Variadic templates
- SFINAE basique
```

---

## 🌟 Fonctionnalités C++20/23 Avancées (Version 1.3+)

### Concepts (C++20)
```cpp
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
T add(T a, T b) { return a + b; }
```

### Ranges (C++20)
```cpp
auto result = numbers 
    | std::views::filter([](int n) { return n % 2 == 0; })
    | std::views::transform([](int n) { return n * n; });
```

### Modules (C++20)
```cpp
// math.cppm
export module math;
export int add(int a, int b) { return a + b; }

// main.cpp
import math;
```

### Coroutines (C++20)
```cpp
generator<int> fibonacci() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        auto next = a + b;
        a = b;
        b = next;
    }
}
```

---

## 📚 Contenu Complémentaire (Version 2.0+)

### Sujets Avancés

#### Multithreading et Concurrence
- `std::thread`
- Mutex et synchronisation
- `std::async` et futures
- Atomic operations

#### Structures de Données Modernes
- `std::variant` (C++17)
- `std::any` (C++17)
- `std::span` (C++20)
- `std::expected` (C++23)

#### Debugging et Profiling
- Utilisation de GDB
- Valgrind pour la mémoire
- AddressSanitizer
- Techniques de debugging

#### Tests Unitaires
- Google Test
- Catch2
- Doctest
- TDD en C++

#### Build Systems
- CMake avancé
- Conan pour les dépendances
- vcpkg

---

## 📋 Plan de Développement

### Version 1.2 (Prochaine)
**Focus : I/O et Algorithmes**
- [ ] Chapitre sur entrées/sorties
- [ ] Chapitre sur algorithmes STL
- [ ] 3 nouveaux exemples
- [ ] 5 nouveaux exercices
- [ ] Guide de debugging

**Durée estimée** : 2-3 semaines

### Version 1.3
**Focus : C++20 Features**
- [ ] Chapitre sur Concepts
- [ ] Chapitre sur Ranges
- [ ] Chapitre sur Move Semantics
- [ ] 2 nouveaux exemples
- [ ] 3 nouveaux exercices

**Durée estimée** : 3-4 semaines

### Version 1.4
**Focus : Templates et Généricité**
- [ ] Chapitre sur templates avancés
- [ ] Chapitre sur métaprogrammation de base
- [ ] 2 nouveaux exemples
- [ ] 3 nouveaux exercices

**Durée estimée** : 2-3 semaines

### Version 2.0
**Focus : Sujets Avancés**
- [ ] Chapitre sur multithreading
- [ ] Chapitre sur modules (C++20)
- [ ] Chapitre sur coroutines (C++20)
- [ ] Guide de tests unitaires
- [ ] 5 nouveaux exemples
- [ ] 10 nouveaux exercices

**Durée estimée** : 6-8 semaines

---

## 🎯 Objectifs à Long Terme

### Couverture Complète
- **100+ leçons** couvrant tout le C++ moderne
- **50+ exemples** de code fonctionnel
- **100+ exercices** avec solutions
- **Projets complets** (mini-applications)

### Qualité et Accessibilité
- Vidéos explicatives (optionnel)
- Diagrammes et schémas
- Quiz interactifs
- Projets guidés pas-à-pas

### Communauté
- Forum de questions/réponses
- Contributions de la communauté
- Corrections et améliorations continues

---

## 💡 Comment Contribuer ?

### Suggérer du Contenu
- Ouvrir une issue sur GitHub
- Proposer des sujets manquants
- Demander des clarifications

### Contribuer du Code
- Ajouter des exemples
- Proposer des exercices
- Améliorer la documentation

### Rapporter des Erreurs
- Signaler les bugs dans les exemples
- Corriger les fautes de frappe
- Améliorer les explications

---

## 📊 Statistiques du Cours

### Version Actuelle (1.1)
- **14 leçons** complètes
- **9 exemples** de code
- **20 exercices** progressifs
- **~80 pages** de documentation
- **Temps d'apprentissage** : 25-35 heures

### Objectif Version 2.0
- **40+ leçons**
- **30+ exemples**
- **50+ exercices**
- **200+ pages** de documentation
- **Temps d'apprentissage** : 80-100 heures

---

**Dernière mise à jour** : 2026-02-08  
**Version actuelle** : 1.1  
**Prochaine version** : 1.2 (I/O et Algorithmes)
