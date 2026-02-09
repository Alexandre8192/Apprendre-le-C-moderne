# Algorithmes STL - Efficaces et Expressifs

## 🎯 Objectif

Maîtriser les algorithmes standards pour écrire du code **plus lisible**, **plus sûr** et **plus performant**.

## 🧭 Pourquoi utiliser les algorithmes STL ?

Les algorithmes de la STL permettent de décrire **ce que l'on veut faire** au lieu de détailler chaque boucle manuelle.

✅ Intention plus claire
✅ Moins d'erreurs
✅ Code réutilisable et optimisé

## 📚 Catégories d'algorithmes

### 1. Recherche

Permet de localiser un élément ou un motif dans une collection.

```cpp
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> noms = {"Alice", "Bob", "Chloé", "David"};

auto it = std::find(noms.begin(), noms.end(), "Bob");
auto it2 = std::find_if(noms.begin(), noms.end(),
                        [](const auto& nom) { return nom.size() == 5; });
```

Pour les collections triées :
- `std::binary_search`
- `std::lower_bound` / `std::upper_bound`

```cpp
std::vector<int> notes = {8, 10, 12, 15, 18};

bool existe = std::binary_search(notes.begin(), notes.end(), 12);
auto debutPlage = std::lower_bound(notes.begin(), notes.end(), 10);
auto finPlage = std::upper_bound(notes.begin(), notes.end(), 15);
```

### 2. Tri

Organise les données selon un critère.

```cpp
#include <algorithm>
#include <vector>

std::vector<int> valeurs = {5, 2, 9, 1, 4};
std::sort(valeurs.begin(), valeurs.end());
```

Avec comparateur personnalisé :

```cpp
struct Produit {
    std::string nom;
    double prix;
};

std::vector<Produit> produits = {{"Clavier", 49.9}, {"Écran", 199.9}};

std::sort(produits.begin(), produits.end(),
          [](const auto& a, const auto& b) { return a.prix < b.prix; });
```

Variantes utiles :
- `std::stable_sort` (garde l'ordre relatif)
- `std::partial_sort` (trie seulement une partie)

### 3. Transformation

Applique une opération à chaque élément.

```cpp
#include <algorithm>
#include <vector>

std::vector<int> valeurs = {1, 2, 3, 4};
std::vector<int> doubles;

std::transform(valeurs.begin(), valeurs.end(), std::back_inserter(doubles),
               [](int v) { return v * 2; });
```

Autres algorithmes pratiques :
- `std::for_each`
- `std::copy` / `std::copy_if`

### 4. Agrégation

Calcule des statistiques globales.

```cpp
#include <numeric>
#include <vector>

std::vector<int> valeurs = {3, 5, 7};
int somme = std::accumulate(valeurs.begin(), valeurs.end(), 0);
```

Compter et trouver des extrêmes :

```cpp
int nbPairs = std::count_if(valeurs.begin(), valeurs.end(),
                            [](int v) { return v % 2 == 0; });

auto mini = std::min_element(valeurs.begin(), valeurs.end());
auto maxi = std::max_element(valeurs.begin(), valeurs.end());
```

### 5. Modification

Modifie le contenu ou la structure des collections.

```cpp
std::vector<int> valeurs = {1, 2, 2, 3, 4};

std::sort(valeurs.begin(), valeurs.end());
auto nouvelleFin = std::unique(valeurs.begin(), valeurs.end());
valeurs.erase(nouvelleFin, valeurs.end());
```

Remove-erase idiom :

```cpp
auto fin = std::remove_if(valeurs.begin(), valeurs.end(),
                          [](int v) { return v < 3; });
valeurs.erase(fin, valeurs.end());
```

Autres outils :
- `std::reverse`
- `std::rotate`

## 💡 Exemples pratiques

### Trouver le premier prix élevé

```cpp
std::vector<double> prix = {9.99, 14.5, 2.0, 49.0, 12.0};

auto it = std::find_if(prix.begin(), prix.end(),
                       [](double p) { return p > 20.0; });
```

### Filtrer des données client

```cpp
std::vector<int> ages = {12, 17, 21, 25, 14};
std::vector<int> majeurs;

std::copy_if(ages.begin(), ages.end(), std::back_inserter(majeurs),
             [](int age) { return age >= 18; });
```

### Agréger un chiffre d'affaires

```cpp
struct Commande {
    std::string id;
    double montant;
};

std::vector<Commande> commandes = {{"A1", 120}, {"B2", 45}, {"C3", 300}};

double total = std::accumulate(commandes.begin(), commandes.end(), 0.0,
                               [](double sum, const auto& c) {
                                   return sum + c.montant;
                               });
```

## ✅ Bon vs ❌ Mauvais

### ❌ Mauvais : boucle manuelle

```cpp
int total = 0;
for (int v : valeurs) {
    total += v;
}
```

### ✅ Bon : algorithme explicite

```cpp
int total = std::accumulate(valeurs.begin(), valeurs.end(), 0);
```

## 🎯 Exercices progressifs

1. **Recherche** : trouver le premier étudiant avec moyenne > 15.
2. **Transformation** : convertir des notes sur 20 en notes sur 100.
3. **Filtrage + tri** : garder les valeurs positives puis trier en ordre décroissant.

---

✅ **À retenir :** privilégiez les algorithmes STL avant d'écrire une boucle manuelle.

## 📚 Prochaine étape

Passez au chapitre suivant : [Entrées/Sorties et Fichiers](06-io-fichiers.md)
