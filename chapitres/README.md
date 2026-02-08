# Chapitres de Cours C++ Moderne

Bienvenue dans les chapitres de cours pour apprendre le C++23/26 !

## 📚 Plan du cours

### 🚀 Chapitre 1 : Introduction

**Objectif** : Mettre en place votre environnement et écrire votre premier programme.

- [1.1 - Installation et Configuration](01-introduction/01-installation.md)
  - Choix du compilateur (GCC, Clang, MSVC)
  - Installation des outils
  - Configuration de l'éditeur/IDE
  - Vérification de l'installation

- [1.2 - Premier Programme](01-introduction/02-premier-programme.md)
  - Hello, World!
  - Structure d'un programme C++
  - Compilation et exécution
  - Premier exercice

**Durée estimée** : 1-2 heures

---

### 🔤 Chapitre 2 : Les Bases du C++

**Objectif** : Maîtriser les fondamentaux du langage.

- [2.1 - Variables et Types de Données](02-bases/01-variables.md)
  - Types de base (int, double, char, bool)
  - Déduction de type avec `auto`
  - Déclaration et initialisation
  - Variables constantes (`const`, `constexpr`)
  - Type `string`

- [2.2 - Opérateurs et Expressions](02-bases/02-operateurs.md)
  - Opérateurs arithmétiques
  - Opérateurs de comparaison
  - Opérateurs logiques
  - Opérateur ternaire
  - Priorité des opérateurs

- [2.3 - Structures de Contrôle](02-bases/03-structures-controle.md)
  - if / else
  - switch
  - Boucle while
  - Boucle do-while
  - Boucle for
  - Range-based for (C++11)
  - break et continue

- [2.4 - Fonctions](02-bases/04-fonctions.md)
  - Déclaration et définition
  - Paramètres et valeurs de retour
  - Passage par valeur vs référence
  - Valeurs par défaut
  - Surcharge de fonctions
  - Récursivité
  - Templates de fonctions

- **✨ [2.5 - Classes et Objets](02-bases/05-classes-objets.md)** NOUVEAU
  - Définition de classes
  - Constructeurs et destructeurs
  - Encapsulation (public, private, protected)
  - Getters et setters
  - Méthodes const et static
  - RAII

- **✨ [2.6 - Héritage et Polymorphisme](02-bases/06-heritage-polymorphisme.md)** NOUVEAU
  - Héritage de classes
  - Fonctions virtuelles
  - Polymorphisme
  - Classes abstraites
  - override et final
  - Destructeurs virtuels

**Durée estimée** : 10-14 heures
  - Templates de fonctions

**Durée estimée** : 6-8 heures

---

### ✨ Chapitre 3 : C++ Moderne (C++11/14/17/20/23)

**Objectif** : Découvrir les fonctionnalités modernes du C++.

- [3.1 - Smart Pointers](03-moderne/01-smart-pointers.md)
  - Problèmes des pointeurs bruts
  - `unique_ptr` - Propriété exclusive
  - `shared_ptr` - Propriété partagée
  - `weak_ptr` - Références faibles
  - RAII (Resource Acquisition Is Initialization)
  - Bonnes pratiques de gestion mémoire

- [3.2 - Lambda Expressions](03-moderne/02-lambdas.md)
  - Syntaxe des lambdas
  - Captures (par valeur, par référence)
  - Lambdas génériques (C++14)
  - Utilisation avec les algorithmes STL
  - Lambdas récursives (C++23)

- **✨ [3.3 - Conteneurs STL](03-moderne/03-conteneurs.md)** NOUVEAU
  - vector, array, deque
  - map, unordered_map
  - set, unordered_set
  - list
  - Choix du bon conteneur

- **✨ [3.4 - Gestion des Erreurs](03-moderne/04-exceptions-optional.md)** NOUVEAU
  - Exceptions (try/catch/throw)
  - Types d'exceptions standard
  - Exceptions personnalisées
  - std::optional (C++17)
  - Quand utiliser exceptions vs optional

- 🚧 **À venir** :
  - 3.5 - Algorithmes STL
  - 3.6 - Concepts (C++20)
  - 3.7 - Ranges (C++20)
  - 3.8 - std::format (C++20)
  - 3.9 - Coroutines (C++20)
  - 3.10 - Modules (C++20)

**Durée estimée** : 12-16 heures

---

### 🏆 Chapitre 4 : Bonnes Pratiques

**Objectif** : Écrire du code C++ professionnel et maintenable.

- [4.1 - Guide des Bonnes Pratiques](../bonnes-pratiques/README.md)
  - Style de code et nommage
  - Gestion de la mémoire moderne
  - Types et variables
  - Fonctions
  - Gestion des erreurs
  - Performance et optimisation
  - Checklist qualité

**Durée estimée** : 3-4 heures

---

## 🎯 Comment suivre ce cours ?

### 1. Approche linéaire (Recommandée pour débutants)

Suivez les chapitres dans l'ordre :
```
Chapitre 1 → Chapitre 2 → Chapitre 3 → Chapitre 4
```

### 2. Approche modulaire (Pour ceux qui connaissent les bases)

Sautez directement aux chapitres qui vous intéressent :
- Connaissez déjà le C++ classique ? → Chapitre 3
- Besoin d'améliorer votre code ? → Chapitre 4

### 3. Approche pratique (Learning by doing)

Alternez entre théorie et pratique :
1. Lisez un chapitre
2. Étudiez les exemples correspondants dans [`/exemples`](../exemples/)
3. Faites les exercices dans [`/exercices`](../exercices/)
4. Répétez avec le chapitre suivant

## 📖 Conventions utilisées

Dans les exemples de code :

```cpp
// ✅ BON : Recommandé
auto nombre = 42;

// ❌ MAUVAIS : À éviter
int* ptr = new int;  // Fuite mémoire potentielle
```

**Symboles** :
- 💡 Conseil ou astuce
- ⚠️ Attention / Piège courant
- 🚀 Fonctionnalité moderne (C++11+)
- 🔧 Outil ou commande

## 🔗 Liens utiles

### Pour chaque chapitre
- **Exemples** : Code fonctionnel dans `/exemples`
- **Exercices** : Pratique dans `/exercices`
- **Compilation** : Guide dans [`/COMPILATION.md`](../COMPILATION.md)

### Ressources externes
- [cppreference.com](https://en.cppreference.com/) - Référence complète
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - Best practices
- [Compiler Explorer](https://godbolt.org/) - Tester en ligne
- [Quick Bench](https://quick-bench.com/) - Benchmarking

## 📊 Progression suggérée

```
┌─────────────────┐
│  Chapitre 1     │  Installation + Hello World
│  (1-2h)         │
└────────┬────────┘
         ↓
┌─────────────────┐
│  Chapitre 2     │  Bases du C++
│  (6-8h)         │  Variables, opérateurs, boucles, fonctions
└────────┬────────┘
         ↓
┌─────────────────┐
│  Exercices      │  Pratiquer les bases
│  Débutants      │  (8 exercices)
└────────┬────────┘
         ↓
┌─────────────────┐
│  Chapitre 3     │  C++ Moderne
│  (8-10h)        │  Smart pointers, lambdas, etc.
└────────┬────────┘
         ↓
┌─────────────────┐
│  Exercices      │  Pratiquer les concepts modernes
│  Intermédiaires │  (10 exercices)
└────────┬────────┘
         ↓
┌─────────────────┐
│  Chapitre 4     │  Bonnes pratiques
│  (3-4h)         │  Code professionnel
└────────┬────────┘
         ↓
┌─────────────────┐
│  🎓 Projet      │  Appliquer toutes les connaissances
│  Personnel      │  Créer votre propre application
└─────────────────┘
```

## ✅ Évaluation de vos compétences

Après chaque chapitre, vous devriez être capable de :

### Après Chapitre 1
- [ ] Installer et configurer un environnement C++
- [ ] Compiler et exécuter un programme simple
- [ ] Comprendre la structure basique d'un programme C++

### Après Chapitre 2
- [ ] Déclarer et utiliser des variables
- [ ] Utiliser les opérateurs et expressions
- [ ] Écrire des structures de contrôle (if, for, while)
- [ ] Créer et utiliser des fonctions
- [ ] Résoudre les exercices débutants

### Après Chapitre 3
- [ ] Gérer la mémoire avec smart pointers
- [ ] Utiliser les lambda expressions
- [ ] Appliquer les concepts modernes C++20/23
- [ ] Résoudre les exercices intermédiaires

### Après Chapitre 4
- [ ] Écrire du code maintenable et professionnel
- [ ] Suivre les bonnes pratiques C++
- [ ] Optimiser le code pour la performance
- [ ] Créer des projets complets

## 🎓 Certification (Auto-évaluation)

Vous pouvez vous considérer comme ayant terminé ce cours si vous :
1. ✅ Avez lu et compris tous les chapitres
2. ✅ Avez étudié tous les exemples
3. ✅ Avez résolu tous les exercices débutants
4. ✅ Avez résolu au moins 5 exercices intermédiaires
5. ✅ Avez créé un projet personnel utilisant C++20/23

---

**Bon apprentissage ! 📚🚀**
