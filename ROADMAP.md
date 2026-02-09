# Feuille de Route du Cours

Ce document présente l'état actuel du cours et les prochaines priorités.

## Etat Actuel (Version 1.3)

### Chapitres disponibles

- Chapitre 1 - Introduction (2 leçons)
- Chapitre 2 - Bases du C++ (6 leçons)
- Chapitre 3 - C++ moderne (10 leçons)
- Chapitre 4 - Bonnes pratiques (1 guide)

Total: **19 leçons**

### Exemples de code

- 13 exemples compilables dans `exemples/`
- CI GitHub Actions:
  - compilation + exécution smoke des exemples
  - tests pédagogiques automatisés

### Exercices

- 8 exercices débutants
- 13 exercices intermédiaires
- Corrigés débutants publiés
- Corrigés intermédiaires partiels publiés

### Projet fil rouge

- `projets/01-todo-app/` (guide + implémentation complète)

---

## Priorités Prochaines (Version 1.4)

### 1. Templates avancés et généricité

- Chapitre dédié aux templates avancés
- Exercices ciblés (spécialisation, variadic, contraintes)
- Exemple concret de design générique

### 2. Qualité et tests

- Ajouter une base de tests unitaires (doctest/Catch2)
- Etendre les tests pédagogiques à plus de chapitres
- Ajouter un contrôle style (clang-format ou équivalent)

### 3. Exercices et corrigés

- Compléter les corrigés intermédiaires (tous les exercices)
- Ajouter des exercices "challenge" orientés entretien/projet

---

## Vision Moyen Terme (Version 1.4+)

### Sujets techniques

- Templates avancés
- `std::variant` / `std::any` / `std::span`
- Concurrence (`std::thread`, mutex, async)

### Outillage

- CMake multi-cibles (cours + exemples + tests)
- Profiling / debugging pratiques
- Guide "workflow contribution" plus détaillé

---

## Objectifs Long Terme

- Un parcours C++ moderne complet, progressif et maintenable
- Un dépôt où tout exemple publié compile et s'exécute en CI
- Une banque d'exercices avec corrigés utilisables en autonomie

---

## Statistiques de référence

- Leçons: **19**
- Exemples: **13**
- Exercices: **21**
- Projets: **1**

---

Dernière mise à jour: **2026-02-09**
