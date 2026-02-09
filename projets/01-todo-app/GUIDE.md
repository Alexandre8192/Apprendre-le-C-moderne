# Guide Pas à Pas : Todo App Console

Ce guide propose une progression en **checkpoints** pour construire le projet.

## ✅ Checkpoint 1 : Modèle de données

- Créer une structure `Tache`
- Champs conseillés :
  - `id` (int)
  - `description` (string)
  - `statut` (enum)
  - `priorite` (enum)
  - `date` (string)

**Pièges à éviter :**
- Ne pas prévoir d'identifiant unique
- Utiliser des strings non normalisées pour le statut

---

## ✅ Checkpoint 2 : Gestionnaire de tâches

- Créer une classe `GestionnaireTaches`
- Stocker les tâches dans `std::vector<Tache>`
- Méthodes de base :
  - ajouter
  - supprimer
  - lister
  - modifier le statut

**Astuce :** utilisez le remove-erase idiom pour supprimer.

---

## ✅ Checkpoint 3 : Tri et recherche

- Tri par priorité (descendant)
- Tri par date (string ISO)
- Recherche par mot-clé
- Filtrage par statut

**Astuce :** `std::sort`, `std::find_if`, `std::copy_if`.

---

## ✅ Checkpoint 4 : Sauvegarde et chargement

- Choisir un format simple : CSV ou JSON
- Sauvegarder dans un fichier local
- Charger les tâches au démarrage
- Gérer les erreurs (fichier absent, ligne invalide)

**Astuce :** `std::filesystem::exists` et `std::ifstream`.

---

## ✅ Checkpoint 5 : Menu interactif

- Afficher un menu clair
- Lire les choix utilisateur
- Valider les entrées
- Boucler jusqu'à quitter

**Piège :** mélanger `std::cin` et `std::getline` sans vider le buffer.

---

## ✅ Checkpoint 6 : Finitions

- Messages utilisateur soignés
- Ajout d'exemples de tâches par défaut
- Mise en forme de l'affichage

---

## 🎯 Conseils pour réussir

- Avancez par petites étapes
- Compilez souvent
- Ajoutez des tests manuels
- Relisez votre code avec un œil critique

Bon courage ! 💪
