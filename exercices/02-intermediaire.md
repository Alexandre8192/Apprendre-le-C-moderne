# Exercices - Niveau Intermédiaire

## 📝 Instructions

Ces exercices nécessitent une meilleure compréhension du C++ moderne. Utilisez les fonctionnalités C++20/23 quand c'est approprié.

## 🎯 Exercice 1 : Gestionnaire de Contacts

Créez une classe `Contact` avec :
- nom, téléphone, email
- Constructeurs appropriés
- Méthodes pour afficher les informations

Créez ensuite un `GestionnaireContacts` qui peut :
- Ajouter un contact
- Rechercher un contact par nom
- Afficher tous les contacts
- Supprimer un contact

**Fichier :** `exercice01_contacts.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez `std::vector<Contact>` pour stocker les contacts.
</details>

---

## 🎯 Exercice 2 : Tri avec Lambda

Créez un programme qui trie un vecteur de structures `Personne` (nom, âge) selon différents critères en utilisant des lambdas.

Le programme doit pouvoir trier par :
1. Nom (ordre alphabétique)
2. Âge (croissant ou décroissant)

**Fichier :** `exercice02_tri_lambda.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez `std::sort` avec différentes lambdas comme comparateurs.
</details>

---

## 🎯 Exercice 3 : Smart Pointers - Liste Chaînée

Implémentez une liste chaînée simple utilisant `std::unique_ptr` :

```cpp
class Node {
    int valeur;
    std::unique_ptr<Node> suivant;
};

class ListeChainee {
    // Méthodes: ajouter, supprimer, afficher, trouver
};
```

**Fichier :** `exercice03_liste_chainee.cpp`

---

## 🎯 Exercice 4 : Gestion de Fichiers avec RAII

Créez une classe `GestionnaireFichier` qui :
- Ouvre un fichier dans le constructeur
- Ferme automatiquement dans le destructeur (RAII)
- Permet de lire et écrire des lignes

**Fichier :** `exercice04_fichier_raii.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez `std::fstream` et implémentez le principe RAII (Resource Acquisition Is Initialization).
</details>

---

## 🎯 Exercice 5 : Template de Pile (Stack)

Implémentez une pile générique (template) avec les opérations :
- `push(T value)` : Ajouter un élément
- `pop()` : Retirer le dernier élément
- `top()` : Voir le dernier élément sans le retirer
- `empty()` : Vérifier si vide
- `size()` : Obtenir la taille

**Fichier :** `exercice05_pile_template.cpp`

```cpp
template<typename T>
class Pile {
    // À implémenter
};
```

---

## 🎯 Exercice 6 : Jeu du Pendu

Créez un jeu du pendu en console :
- Un mot est choisi aléatoirement dans une liste
- Le joueur devine lettre par lettre
- Il a un nombre limité d'essais
- Affichage du mot avec les lettres trouvées

**Fichier :** `exercice06_pendu.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez `std::string`, `std::vector`, et des fonctions pour l'affichage.
</details>

---

## 🎯 Exercice 7 : Calculatrice avec Historique

Améliorez une calculatrice pour :
- Effectuer des opérations de base
- Garder un historique des opérations
- Permettre d'annuler (undo) la dernière opération
- Afficher l'historique

**Fichier :** `exercice07_calculatrice_historique.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez un `std::vector` ou `std::stack` pour l'historique.
</details>

---

## 🎯 Exercice 8 : Algorithmes avec Ranges (C++20)

Utilisez les ranges de C++20 pour :
1. Filtrer les nombres pairs d'un vecteur
2. Transformer chaque nombre (×2)
3. Trier le résultat
4. Prendre les 5 premiers éléments

Tout cela en une seule expression pipeline !

**Fichier :** `exercice08_ranges.cpp`

```cpp
#include <ranges>
#include <algorithm>

// Exemple de pipeline :
// auto resultat = nombres 
//     | std::views::filter(...)
//     | std::views::transform(...)
//     | ...
```

---

## 🎯 Exercice 9 : Mini Base de Données

Créez une mini base de données de produits avec :
- Structure `Produit` (id, nom, prix, quantité)
- Fonctions pour ajouter, supprimer, modifier, rechercher
- Sauvegarde/chargement depuis un fichier
- Utilisation de smart pointers

**Fichier :** `exercice09_base_donnees.cpp`

---

## 🎯 Exercice 10 : Chronomètre et Timer

Créez un chronomètre en utilisant `<chrono>` (C++11/20) :
- Démarrer/arrêter le chronomètre
- Afficher le temps écoulé
- Enregistrer des "laps" (temps intermédiaires)

**Fichier :** `exercice10_chronometre.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez `std::chrono::steady_clock` et `std::chrono::duration`.
</details>

---

## 📂 Solutions

Les solutions complètes sont disponibles dans [solutions/intermediaire/](solutions/intermediaire/).

## 🚀 Prochain niveau

Félicitations ! Vous pouvez maintenant explorer les sujets avancés comme les concepts, les coroutines, et les modules C++20/23.
