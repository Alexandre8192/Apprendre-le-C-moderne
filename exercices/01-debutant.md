# Exercices - Niveau Débutant

## 📝 Instructions

Pour chaque exercice :
1. Lisez attentivement l'énoncé
2. Essayez de résoudre le problème par vous-même
3. Compilez et testez votre code
4. Consultez la solution si nécessaire

## 🎯 Exercice 1 : Calculatrice Simple

Créez un programme qui :
- Demande deux nombres à l'utilisateur
- Demande une opération (+, -, *, /)
- Affiche le résultat

**Fichier :** `exercice01.cpp`

**Exemple d'exécution :**
```
Entrez le premier nombre: 10
Entrez le second nombre: 5
Entrez l'opération (+, -, *, /): *
Résultat: 50
```

<details>
<summary>💡 Indice</summary>

Utilisez `std::cin` pour lire les entrées et un `switch` ou des `if` pour les opérations.
</details>

---

## 🎯 Exercice 2 : Nombre Pair ou Impair

Écrivez un programme qui demande un nombre et indique s'il est pair ou impair.

**Fichier :** `exercice02.cpp`

**Exemple d'exécution :**
```
Entrez un nombre: 7
7 est impair
```

<details>
<summary>💡 Indice</summary>

Utilisez l'opérateur modulo `%`. Un nombre est pair si `n % 2 == 0`.
</details>

---

## 🎯 Exercice 3 : Table de Multiplication

Créez un programme qui affiche la table de multiplication d'un nombre donné par l'utilisateur (de 1 à 10).

**Fichier :** `exercice03.cpp`

**Exemple d'exécution :**
```
Entrez un nombre: 7
7 × 1 = 7
7 × 2 = 14
...
7 × 10 = 70
```

<details>
<summary>💡 Indice</summary>

Utilisez une boucle `for` de 1 à 10.
</details>

---

## 🎯 Exercice 4 : Somme des N premiers nombres

Écrivez un programme qui calcule la somme des N premiers entiers naturels.

**Fichier :** `exercice04.cpp`

**Exemple :**
- Pour N = 5 : 1 + 2 + 3 + 4 + 5 = 15
- Pour N = 10 : 1 + 2 + ... + 10 = 55

<details>
<summary>💡 Indice</summary>

Utilisez une boucle `for` et une variable `somme` initialisée à 0.
</details>

---

## 🎯 Exercice 5 : Factorielle

Créez une fonction qui calcule la factorielle d'un nombre.
- 5! = 5 × 4 × 3 × 2 × 1 = 120

**Fichier :** `exercice05.cpp`

Essayez deux versions :
1. Version itérative (avec une boucle)
2. Version récursive (fonction qui s'appelle elle-même)

<details>
<summary>💡 Indice</summary>

Version récursive : 
- Cas de base : si n ≤ 1, retourner 1
- Cas récursif : retourner n × factorielle(n-1)
</details>

---

## 🎯 Exercice 6 : Nombres Premiers

Écrivez une fonction `estPremier(int n)` qui retourne `true` si n est un nombre premier.

Un nombre premier est divisible uniquement par 1 et lui-même.

**Fichier :** `exercice06.cpp`

**Tests :**
- 2 → true
- 7 → true
- 10 → false
- 17 → true

<details>
<summary>💡 Indice</summary>

Testez si n est divisible par un nombre entre 2 et √n. Si oui, ce n'est pas premier.
</details>

---

## 🎯 Exercice 7 : Inverser une chaîne

Créez un programme qui inverse une chaîne de caractères.

**Fichier :** `exercice07.cpp`

**Exemple :**
```
Entrez un mot: Bonjour
Résultat: ruojnoB
```

<details>
<summary>💡 Indice</summary>

Utilisez `std::string` et parcourez-la à l'envers, ou utilisez `std::reverse` de `<algorithm>`.
</details>

---

## 🎯 Exercice 8 : Moyenne de nombres

Créez un programme qui :
1. Demande combien de nombres l'utilisateur veut entrer
2. Lit ces nombres
3. Calcule et affiche la moyenne

**Fichier :** `exercice08.cpp`

<details>
<summary>💡 Indice</summary>

Utilisez un `std::vector<double>` pour stocker les nombres.
</details>

---

## 📂 Solutions

Les solutions sont disponibles dans le dossier [solutions/](solutions/) une fois que vous avez essayé !

## 🚀 Pour aller plus loin

Une fois ces exercices terminés, passez aux exercices niveau intermédiaire !
