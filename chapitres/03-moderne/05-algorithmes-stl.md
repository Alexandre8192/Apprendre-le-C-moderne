# Algorithmes de la STL

## 🎯 Objectif

Maîtriser les algorithmes standards pour manipuler efficacement les collections.

## 📚 Catégories d'algorithmes

### 1. Algorithmes de recherche

Les algorithmes de recherche permettent de localiser rapidement des éléments.

```cpp
#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string> noms = {"Alice", "Bob", "Chloé", "David"};

// Recherche simple
auto it = std::find(noms.begin(), noms.end(), "Bob");

// Recherche avec condition
auto it2 = std::find_if(noms.begin(), noms.end(), [](const auto& nom) {
    return nom.size() == 5;  // Trouver un prénom de 5 lettres
});
```

Pour les collections triées, utilisez :
- `std::binary_search`
- `std::lower_bound` / `std::upper_bound`

```cpp
std::vector<int> notes = {8, 10, 12, 15, 18};

bool existe = std::binary_search(notes.begin(), notes.end(), 12);
auto debutPlage = std::lower_bound(notes.begin(), notes.end(), 10);
auto finPlage = std::upper_bound(notes.begin(), notes.end(), 15);
```

### 2. Algorithmes de tri

Les algorithmes de tri organisent les données selon un critère.

```cpp
#include <algorithm>
#include <vector>

std::vector<int> valeurs = {5, 2, 9, 1, 4};
std::sort(valeurs.begin(), valeurs.end());
```

Avec un comparateur personnalisé :

```cpp
struct Produit { std::string nom; double prix; };
std::vector<Produit> produits = {{"Clavier", 49.9}, {"Écran", 199.9}};

std::sort(produits.begin(), produits.end(),
          [](const auto& a, const auto& b) { return a.prix < b.prix; });
```

Autres variantes utiles :
- `std::stable_sort` conserve l'ordre relatif.
- `std::partial_sort` trie seulement les N premiers.

### 3. Algorithmes de transformation

Ils permettent d'appliquer une opération à chaque élément.

```cpp
#include <algorithm>
#include <vector>

std::vector<int> valeurs = {1, 2, 3, 4};
std::vector<int> doubles;

std::transform(valeurs.begin(), valeurs.end(), std::back_inserter(doubles),
               [](int v) { return v * 2; });
```

Autres algorithmes pratiques :
- `std::for_each` pour exécuter une action
- `std::copy` et `std::copy_if` pour filtrer

### 4. Algorithmes d'agrégation

Ils calculent des statistiques globales.

```cpp
#include <numeric>
#include <vector>

std::vector<int> valeurs = {3, 5, 7};
int somme = std::accumulate(valeurs.begin(), valeurs.end(), 0);
```

Pour compter ou trouver des extrêmes :

```cpp
int nbPairs = std::count_if(valeurs.begin(), valeurs.end(),
                            [](int v) { return v % 2 == 0; });

auto mini = std::min_element(valeurs.begin(), valeurs.end());
auto maxi = std::max_element(valeurs.begin(), valeurs.end());
```

### 5. Algorithmes de modification

Ils modifient la structure des collections.

```cpp
std::vector<int> valeurs = {1, 2, 2, 3, 4};

// Supprimer les doublons (après tri)
std::sort(valeurs.begin(), valeurs.end());
auto nouvelleFin = std::unique(valeurs.begin(), valeurs.end());
valeurs.erase(nouvelleFin, valeurs.end());
```

Remove-erase idiom pour supprimer selon un critère :

```cpp
auto fin = std::remove_if(valeurs.begin(), valeurs.end(),
                          [](int v) { return v < 3; });
valeurs.erase(fin, valeurs.end());
```

Autres outils :
- `std::reverse` pour inverser
- `std::rotate` pour pivoter

## 💡 Exemples pratiques

### Filtrer des données client

```cpp
std::vector<int> ages = {12, 17, 21, 25, 14};
std::vector<int> majeurs;

std::copy_if(ages.begin(), ages.end(), std::back_inserter(majeurs),
             [](int age) { return age >= 18; });
```

### Trier des objets métiers

```cpp
struct Commande { std::string id; double montant; };
std::vector<Commande> commandes = {{"A1", 120}, {"B2", 45}, {"C3", 300}};

std::sort(commandes.begin(), commandes.end(),
          [](const auto& a, const auto& b) { return a.montant > b.montant; });
```

### Agréger un chiffre d'affaires

```cpp
double total = std::accumulate(commandes.begin(), commandes.end(), 0.0,
                               [](double sum, const auto& c) {
                                   return sum + c.montant;
                               });
```

## 🎯 Exercices

1. **Rechercher un élément** : créer un vector d'étudiants et trouver ceux ayant une moyenne > 15.
2. **Trier et filtrer** : trier une liste de livres par prix, puis garder uniquement ceux en stock.
3. **Statistiques** : calculer la moyenne et le maximum d'une liste de températures.

---

✅ **À retenir :** les algorithmes STL sont rapides, lisibles et réutilisables. Utilisez-les avant d'écrire des boucles manuelles.
