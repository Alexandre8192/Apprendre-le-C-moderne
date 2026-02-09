# Entrées/Sorties et Fichiers en C++ Moderne

## 🎯 Objectif

Maîtriser la lecture/écriture de fichiers et l'utilisation de `std::filesystem`.

## 📂 Flux de fichiers (fstream)

### Lecture de fichiers

- `std::ifstream` ouvre un fichier en lecture.
- Lecture ligne par ligne via `std::getline`.
- Lecture formatée avec l'opérateur `>>`.
- Toujours vérifier l'ouverture et les erreurs.

```cpp
#include <fstream>
#include <iostream>
#include <string>

std::ifstream entree("donnees.txt");
if (!entree) {
    std::cerr << "Impossible d'ouvrir le fichier\n";
    return;
}

std::string ligne;
while (std::getline(entree, ligne)) {
    std::cout << "Ligne: " << ligne << "\n";
}
```

Lecture de données formatées :

```cpp
int age = 0;
std::string nom;
while (entree >> nom >> age) {
    std::cout << nom << " a " << age << " ans\n";
}
```

### Écriture de fichiers

- `std::ofstream` ouvre en écriture.
- Mode append avec `std::ios::app`.
- Écriture formatée comme dans `std::cout`.

```cpp
#include <fstream>

std::ofstream sortie("journal.txt");
if (!sortie) {
    return;
}

sortie << "Message de log" << '\n';
```

Mode append :

```cpp
std::ofstream sortie("journal.txt", std::ios::app);
if (sortie) {
    sortie << "Nouvelle entrée" << '\n';
}
```

### Lecture/Écriture (std::fstream)

`std::fstream` permet de lire et écrire avec le même flux.

```cpp
#include <fstream>

std::fstream flux("config.txt", std::ios::in | std::ios::out);
if (flux) {
    flux << "clé=valeur\n";
}
```

### RAII et gestion automatique

Les flux ferment automatiquement les fichiers lorsqu'ils sortent de portée.

```cpp
void ecrireFichier() {
    std::ofstream sortie("auto.txt");
    sortie << "RAII ferme le fichier automatiquement";
}  // fermeture automatique ici
```

## 📁 std::filesystem (C++17)

### Manipulation de chemins

`std::filesystem::path` facilite la manipulation des chemins.

```cpp
#include <filesystem>

std::filesystem::path dossier = "data";
std::filesystem::path fichier = dossier / "config.json";

auto extension = fichier.extension();
auto nomFichier = fichier.filename();
```

### Opérations sur fichiers/dossiers

```cpp
using namespace std::filesystem;

path fichier = "data/config.json";
if (exists(fichier) && is_regular_file(fichier)) {
    auto taille = file_size(fichier);
    auto date = last_write_time(fichier);
}

create_directory("backup");
remove("ancien.txt");
```

### Parcours de répertoires

```cpp
for (const auto& entree : std::filesystem::directory_iterator("data")) {
    std::cout << entree.path() << "\n";
}

for (const auto& entree : std::filesystem::recursive_directory_iterator("data")) {
    std::cout << entree.path() << "\n";
}
```

## 🎨 std::format (C++20)

### Formatage moderne

`std::format` propose une syntaxe similaire à Python.

```cpp
#include <format>
#include <iostream>

std::string nom = "Alice";
int score = 42;

std::cout << std::format("{} a obtenu {} points", nom, score) << '\n';
```

Formatage de nombres :

```cpp
double pi = 3.14159;
std::cout << std::format("{:.2f}", pi) << '\n';
std::cout << std::format("{:>8.2f}", pi) << '\n';
```

## 💡 Exemples complets

1. **Lecture et analyse d'un fichier CSV**
   - Lire ligne par ligne avec `std::getline`
   - Parser avec `std::stringstream`
   - Calculer des statistiques avec `std::accumulate`

2. **Sauvegarde/chargement de configuration**
   - Écrire un fichier `config.ini`
   - Lire et valider les clés attendues
   - Gérer l'absence de fichier avec un fallback

3. **Parcours récursif de dossier avec filtrage**
   - Parcourir un dossier avec `recursive_directory_iterator`
   - Garder uniquement les fichiers `.txt`
   - Afficher la taille totale

## 🎯 Exercices

1. **Journal texte** : écrire un programme qui ajoute des lignes horodatées dans un fichier.
2. **CSV de notes** : charger un CSV d'étudiants, calculer la moyenne globale.
3. **Explorateur de dossier** : lister les fichiers `.cpp` et afficher leur taille.

---

✅ **À retenir :** combinez les flux (`fstream`) et `std::filesystem` pour un code robuste et moderne.

## 📚 Prochaine étape

Passez au chapitre suivant : [Move Semantics](07-move-semantics.md)
