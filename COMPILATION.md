# Guide de Compilation et d'Utilisation

## 🎯 Objectif

Guide pratique pour compiler et exécuter les exemples et exercices de ce cours.

---

## ✅ Compilateurs recommandés et versions minimales

- **GCC 11+** pour un support C++20 complet
- **Clang 14+** pour un support C++20 complet
- **MSVC 2022+** pour C++20/23

### Vérifier la version

```bash
g++ --version
clang++ --version
```

```powershell
cl
```

---

## 🧰 IDEs et éditeurs recommandés

- **Visual Studio Code** + extensions C/C++
- **CLion**
- **Visual Studio 2022**
- **Compilation en ligne** : [Compiler Explorer](https://godbolt.org/), [Wandbox](https://wandbox.org/)

---

## 🛠️ Compilation de Base

### GCC (Linux/macOS/Windows avec MSYS2)

```bash
# Compilation simple
g++ -std=c++23 fichier.cpp -o programme

# Avec warnings
g++ -std=c++23 -Wall -Wextra fichier.cpp -o programme

# Avec optimisation
g++ -std=c++23 -Wall -Wextra -O2 fichier.cpp -o programme

# Exécution
./programme
```

### Clang (Linux/macOS/Windows)

```bash
# Compilation
clang++ -std=c++23 -Wall -Wextra fichier.cpp -o programme

# Exécution
./programme
```

### MSVC (Windows avec Visual Studio)

```bash
# Compilation
cl /std:c++latest /EHsc fichier.cpp

# Exécution
fichier.exe
```

---

## 📦 Compilation avec plusieurs fichiers

### Méthode manuelle

```bash
# Compiler chaque fichier en objet
g++ -std=c++23 -c main.cpp -o main.o
g++ -std=c++23 -c utils.cpp -o utils.o

# Linker les objets
g++ main.o utils.o -o programme
```

### Méthode simplifiée

```bash
# Tout en une commande
g++ -std=c++23 main.cpp utils.cpp -o programme
```

---

## 🔧 Flags de Compilation Recommandés

### Flags Essentiels

```bash
-std=c++23        # Standard C++23
-Wall             # Active la plupart des warnings
-Wextra           # Warnings supplémentaires
-Wpedantic        # Respecte strictement le standard
-O2               # Optimisation niveau 2 (production)
-g                # Informations de debug
```

### Exemple complet

```bash
# Pour le développement
g++ -std=c++23 -Wall -Wextra -Wpedantic -g fichier.cpp -o programme

# Pour la production
g++ -std=c++23 -Wall -Wextra -O3 -DNDEBUG fichier.cpp -o programme
```

---

## 🏗️ Utilisation de CMake

CMake est l'outil de build moderne recommandé pour les projets C++.

### Structure d'un projet simple

```
mon_projet/
├── CMakeLists.txt
├── src/
│   └── main.cpp
└── include/
    └── utils.h
```

### CMakeLists.txt basique

```cmake
cmake_minimum_required(VERSION 3.20)
project(MonProjet VERSION 1.0)

# Spécifier C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Créer l'exécutable
add_executable(programme src/main.cpp)

# Ajouter les warnings
target_compile_options(programme PRIVATE
    -Wall -Wextra -Wpedantic
)
```

### Compilation avec CMake

```bash
# Créer le dossier build
mkdir build
cd build

# Générer les fichiers de build
cmake ..

# Compiler
cmake --build .

# Ou avec make
make

# Exécuter
./programme
```

### CMakeLists.txt pour projet multi-fichiers

```cmake
cmake_minimum_required(VERSION 3.20)
project(MonProjet VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver tous les fichiers sources
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Créer l'exécutable
add_executable(programme ${SOURCES})

# Inclure les headers
target_include_directories(programme PRIVATE include)

# Warnings
if(MSVC)
    target_compile_options(programme PRIVATE /W4)
else()
    target_compile_options(programme PRIVATE -Wall -Wextra -Wpedantic)
endif()
```

---

## 📚 Bibliothèques Externes

### Avec GCC/Clang

```bash
# Compiler avec une bibliothèque
g++ -std=c++23 fichier.cpp -o programme -lnombibliotheque

# Exemple avec la bibliothèque math
g++ -std=c++23 fichier.cpp -o programme -lm

# Exemple avec pthread
g++ -std=c++23 fichier.cpp -o programme -lpthread
```

### Avec CMake

```cmake
# Trouver une bibliothèque
find_package(Threads REQUIRED)

# Lier à l'exécutable
target_link_libraries(programme PRIVATE Threads::Threads)
```

---

## 🐛 Compilation en mode Debug

### Avec flags GCC/Clang

```bash
# Activer les informations de debug
g++ -std=c++23 -g -O0 fichier.cpp -o programme

# Avec sanitizers (détection d'erreurs)
g++ -std=c++23 -g -fsanitize=address -fsanitize=undefined fichier.cpp -o programme
```

### Avec CMake

```cmake
# Mode Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Mode Release
cmake -DCMAKE_BUILD_TYPE=Release ..
```

---

## 🔍 Analyser les erreurs de compilation

### Erreurs courantes et solutions

#### Erreur : "no matching function"

```
error: no matching function for call to 'fonction(int)'
```

**Cause :** Type de paramètre incorrect ou fonction non déclarée.

**Solution :** Vérifiez les types et la déclaration de la fonction.

#### Erreur : "undefined reference"

```
undefined reference to 'maFonction()'
```

**Cause :** Fonction déclarée mais pas définie, ou fichier objet non linké.

**Solution :** Assurez-vous que tous les fichiers sources sont compilés et linkés.

#### Erreur : "filesystem" non trouvé (anciens GCC)

**Cause :** `std::filesystem` nécessite parfois le lien explicite.

**Solution :**

```bash
g++ -std=c++17 fichier.cpp -lstdc++fs
```

#### Erreur : flags manquants

**Cause :** Absence de `-std=c++20` ou de warnings.

**Solution :** Ajoutez `-std=c++20 -Wall -Wextra -Wpedantic`.

#### Erreur : chemin d'include

**Cause :** Header non trouvé.

**Solution :** Utilisez `-I` pour ajouter un chemin :

```bash
g++ -Iinclude -std=c++20 fichier.cpp -o programme
```

#### Erreur : "redefinition"

```
error: redefinition of 'variable'
```

**Cause :** Même nom défini plusieurs fois.

**Solution :** Utilisez `static`, `inline`, ou des guards d'inclusion.

---

## 📊 Compilation Conditionnelle

### Macros de préprocesseur

```cpp
#ifdef DEBUG
    std::cout << "Mode debug activé\n";
#endif

#if __cplusplus >= 202002L
    // Code C++20+
    #include <format>
#else
    // Code compatible C++17
    #include <iomanip>
#endif
```

### Compilation avec macros

```bash
# Définir une macro
g++ -DDEBUG -std=c++23 fichier.cpp -o programme

# Définir une macro avec valeur
g++ -DVERSION=1.0 -std=c++23 fichier.cpp -o programme
```

---

## 🚀 Scripts de Compilation Rapide

### Bash script (Linux/macOS)

```bash
#!/bin/bash
# compile.sh

# Compiler avec C++23 et warnings
g++ -std=c++23 -Wall -Wextra -O2 "$1" -o "${1%.cpp}"

# Exécuter si compilation réussie
if [ $? -eq 0 ]; then
    echo "Compilation réussie !"
    ./"${1%.cpp}"
else
    echo "Erreur de compilation"
    exit 1
fi
```

Usage :
```bash
chmod +x compile.sh
./compile.sh mon_fichier.cpp
```

### PowerShell script (Windows)

```powershell
# compile.ps1
param($fichier)

$nom = [System.IO.Path]::GetFileNameWithoutExtension($fichier)
g++ -std=c++23 -Wall -Wextra -O2 $fichier -o "$nom.exe"

if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilation réussie !" -ForegroundColor Green
    & ".\$nom.exe"
} else {
    Write-Host "Erreur de compilation" -ForegroundColor Red
}
```

Usage :
```powershell
.\compile.ps1 mon_fichier.cpp
```

---

## 🔧 Makefile Simple

```makefile
# Makefile

CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2
TARGET = programme
SOURCES = main.cpp utils.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
```

Usage :
```bash
make           # Compiler
make clean     # Nettoyer
```

---

## 🧱 Build systems (aperçu)

### Pourquoi utiliser un build system ?

- Gérer des projets multi-fichiers
- Automatiser la compilation
- Centraliser les flags et options

### Exemple minimal de CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(MonProjet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(programme main.cpp)
```

---

## 📝 Résumé des Commandes

```bash
# Compilation simple
g++ -std=c++23 fichier.cpp -o prog

# Avec warnings
g++ -std=c++23 -Wall -Wextra fichier.cpp -o prog

# Avec optimisation
g++ -std=c++23 -Wall -Wextra -O2 fichier.cpp -o prog

# Avec debug
g++ -std=c++23 -g fichier.cpp -o prog

# Plusieurs fichiers
g++ -std=c++23 main.cpp utils.cpp -o prog

# Avec CMake
mkdir build && cd build
cmake ..
make
```

---

## 🆘 Besoin d'aide ?

Si vous rencontrez des problèmes de compilation :

1. Vérifiez la version de votre compilateur : `g++ --version`
2. Assurez-vous d'avoir C++23 : `g++ -std=c++23 --version`
3. Lisez attentivement les messages d'erreur
4. Activez tous les warnings : `-Wall -Wextra`

---

**Bon courage avec vos compilations ! 🚀**
