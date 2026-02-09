# Projet Fil Rouge : Todo App Console

## 🎯 Objectifs pédagogiques

Ce mini-projet vous aide à :
- Consolider la **POO** (classes, encapsulation, méthodes)
- Manipuler la **STL** (vector, algorithmes, tri)
- Gérer des **fichiers** (sauvegarde/chargement CSV ou JSON)
- Écrire un **menu console interactif**

## ✅ Fonctionnalités attendues

- Ajouter, modifier et supprimer des tâches
- Marquer une tâche comme faite / en cours
- Trier par **priorité** ou **date**
- Rechercher / filtrer des tâches
- Sauvegarder et charger les données depuis un fichier

## 🧭 Étapes de construction suggérées

1. **Modéliser une tâche** (`Tache`)
2. **Créer un gestionnaire** (`GestionnaireTaches`)
3. **Ajouter les fonctions de sauvegarde/chargement**
4. **Créer un menu interactif**
5. **Ajouter tri et recherche**
6. **Polir l'expérience utilisateur** (messages, validations)

## 📄 Fichiers fournis

- [`todo.cpp`](todo.cpp) : solution complète commentée
- [`GUIDE.md`](GUIDE.md) : guide pas à pas pour construire le projet

## ▶️ Compilation

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 todo.cpp -o todo
./todo
```

## 🚀 Prochaine étape

Une fois ce projet terminé, essayez d'ajouter :
- Une **priorité automatique** selon l'urgence
- Des **catégories** de tâches
- Une **interface JSON** (via une bibliothèque)
