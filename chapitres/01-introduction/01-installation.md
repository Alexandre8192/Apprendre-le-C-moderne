# Installation et Configuration

## 🎯 Objectif

Installer un environnement de développement C++ moderne pour commencer à programmer.

## 📦 Choix du compilateur

Pour utiliser les fonctionnalités C++20/23 du cours, vous avez besoin d'un compilateur récent :

### Option 1 : GCC (Linux/macOS/Windows)

**Linux (Ubuntu/Debian) :**
```bash
sudo apt update
sudo apt install build-essential g++-13
```

**macOS (avec Homebrew) :**
```bash
brew install gcc@13
```

**Windows (avec MSYS2) :**
```bash
pacman -S mingw-w64-x86_64-gcc
```

### Option 2 : Clang (Linux/macOS/Windows)

**Linux (Ubuntu/Debian) :**
```bash
sudo apt install clang-16
```

**macOS :**
Clang est inclus avec Xcode Command Line Tools :
```bash
xcode-select --install
```

### Option 3 : MSVC (Windows)

Téléchargez et installez [Visual Studio 2022](https://visualstudio.microsoft.com/) avec le workload "Développement Desktop en C++".

## 🛠️ Éditeurs et IDEs recommandés

### Visual Studio Code (Multi-plateforme)
- **Gratuit** et **léger**
- Extensions recommandées :
  - C/C++ (Microsoft)
  - C/C++ Extension Pack
  - CMake Tools

### CLion (Multi-plateforme)
- IDE professionnel de JetBrains
- Licence gratuite pour les étudiants

### Visual Studio (Windows)
- IDE complet avec excellent support C++
- Community Edition gratuite

## ✅ Vérification de l'installation

Créez un fichier `test.cpp` :

```cpp
#include <iostream>
#include <format>  // C++20

int main() {
    std::cout << std::format("C++ version: {}\n", __cplusplus);
    return 0;
}
```

Compilez et exécutez :

**Avec GCC :**
```bash
g++-13 -std=c++23 test.cpp -o test
./test
```

**Avec Clang :**
```bash
clang++-16 -std=c++23 test.cpp -o test
./test
```

**Avec MSVC :**
```bash
cl /std:c++latest test.cpp
test.exe
```

Si vous voyez un numéro de version supérieur à 202002L, vous êtes prêt ! 🎉

## 📚 Prochaine étape

Passez au chapitre suivant : [Premier programme](02-premier-programme.md)
