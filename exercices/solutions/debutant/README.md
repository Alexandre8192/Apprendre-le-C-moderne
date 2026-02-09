# Solutions - Niveau Debutant

Ce document propose un corrigé de référence pour les 8 exercices débutants.

## Exercice 1 - Calculatrice simple

```cpp
#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;
    char op = '+';

    std::cout << "Entrez le premier nombre: ";
    std::cin >> a;
    std::cout << "Entrez le second nombre: ";
    std::cin >> b;
    std::cout << "Entrez l'operation (+, -, *, /): ";
    std::cin >> op;

    switch (op) {
        case '+':
            std::cout << "Resultat: " << (a + b) << "\n";
            break;
        case '-':
            std::cout << "Resultat: " << (a - b) << "\n";
            break;
        case '*':
            std::cout << "Resultat: " << (a * b) << "\n";
            break;
        case '/':
            if (b == 0.0) {
                std::cout << "Erreur: division par zero.\n";
                return 1;
            }
            std::cout << "Resultat: " << (a / b) << "\n";
            break;
        default:
            std::cout << "Operation invalide.\n";
            return 1;
    }
}
```

## Exercice 2 - Pair ou impair

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Entrez un nombre: ";
    std::cin >> n;
    std::cout << n << ((n % 2 == 0) ? " est pair\n" : " est impair\n");
}
```

## Exercice 3 - Table de multiplication

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Entrez un nombre: ";
    std::cin >> n;

    for (int i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " = " << (n * i) << "\n";
    }
}
```

## Exercice 4 - Somme des N premiers nombres

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Entrez N: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "N doit etre positif.\n";
        return 1;
    }

    int somme = 0;
    for (int i = 1; i <= n; ++i) {
        somme += i;
    }

    std::cout << "Somme = " << somme << "\n";
}
```

## Exercice 5 - Factorielle (iterative + recursive)

```cpp
#include <iostream>

unsigned long long factorielleIterative(int n) {
    if (n < 0) {
        return 0;
    }

    unsigned long long resultat = 1;
    for (int i = 2; i <= n; ++i) {
        resultat *= static_cast<unsigned long long>(i);
    }
    return resultat;
}

unsigned long long factorielleRecursive(int n) {
    if (n < 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    return static_cast<unsigned long long>(n) * factorielleRecursive(n - 1);
}

int main() {
    int n = 0;
    std::cout << "Entrez n: ";
    std::cin >> n;

    std::cout << "Iterative: " << factorielleIterative(n) << "\n";
    std::cout << "Recursive: " << factorielleRecursive(n) << "\n";
}
```

## Exercice 6 - Nombre premier

```cpp
#include <cmath>
#include <iostream>

bool estPremier(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    const int borne = static_cast<int>(std::sqrt(static_cast<double>(n)));
    for (int d = 3; d <= borne; d += 2) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int n : {2, 7, 10, 17}) {
        std::cout << n << " -> " << (estPremier(n) ? "true" : "false") << "\n";
    }
}
```

## Exercice 7 - Inverser une chaine

```cpp
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string mot;
    std::cout << "Entrez un mot: ";
    std::getline(std::cin, mot);

    std::reverse(mot.begin(), mot.end());
    std::cout << "Resultat: " << mot << "\n";
}
```

## Exercice 8 - Moyenne de nombres

```cpp
#include <iostream>
#include <vector>

int main() {
    int count = 0;
    std::cout << "Combien de nombres ? ";
    std::cin >> count;

    if (count <= 0) {
        std::cout << "Nombre invalide.\n";
        return 1;
    }

    std::vector<double> valeurs;
    valeurs.reserve(static_cast<std::size_t>(count));

    for (int i = 0; i < count; ++i) {
        double v = 0.0;
        std::cout << "Valeur " << (i + 1) << ": ";
        std::cin >> v;
        valeurs.push_back(v);
    }

    double somme = 0.0;
    for (double v : valeurs) {
        somme += v;
    }

    std::cout << "Moyenne: " << (somme / static_cast<double>(valeurs.size())) << "\n";
}
```
