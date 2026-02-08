# Opérateurs et Expressions

## 🎯 Objectif

Maîtriser les opérateurs pour manipuler les données en C++.

## ➕ Opérateurs arithmétiques

```cpp
int a = 10, b = 3;

int somme = a + b;        // Addition : 13
int difference = a - b;   // Soustraction : 7
int produit = a * b;      // Multiplication : 30
int quotient = a / b;     // Division entière : 3
int reste = a % b;        // Modulo (reste) : 1

// Division avec flottants
double division = 10.0 / 3.0;  // 3.333...
```

### Opérateurs d'incrémentation et de décrémentation

```cpp
int x = 5;
x++;    // Post-incrémentation : x vaut maintenant 6
++x;    // Pré-incrémentation : x vaut maintenant 7
x--;    // Post-décrémentation : x vaut maintenant 6
--x;    // Pré-décrémentation : x vaut maintenant 5

// Différence entre pré et post
int a = 5;
int b = a++;  // b = 5, a = 6 (post : utilise puis incrémente)
int c = ++a;  // c = 7, a = 7 (pré : incrémente puis utilise)
```

## 📊 Opérateurs de comparaison

```cpp
int x = 10, y = 20;

bool egal = (x == y);          // Égal : false
bool different = (x != y);     // Différent : true
bool inferieur = (x < y);      // Inférieur : true
bool infEgal = (x <= y);       // Inférieur ou égal : true
bool superieur = (x > y);      // Supérieur : false
bool supEgal = (x >= y);       // Supérieur ou égal : false

// C++20 : Opérateur de comparaison à trois voies (spaceship)
#include <compare>
auto resultat = x <=> y;  // std::strong_ordering::less
```

## 🔗 Opérateurs logiques

```cpp
bool a = true, b = false;

bool et = a && b;      // ET logique : false
bool ou = a || b;      // OU logique : true
bool non = !a;         // NON logique : false

// Court-circuit : la seconde condition n'est évaluée que si nécessaire
if (x != 0 && 100/x > 5) {  // Évite la division par zéro
    // ...
}
```

## 🔧 Opérateurs d'assignation

```cpp
int x = 10;

x += 5;   // Équivalent à : x = x + 5;   // x = 15
x -= 3;   // Équivalent à : x = x - 3;   // x = 12
x *= 2;   // Équivalent à : x = x * 2;   // x = 24
x /= 4;   // Équivalent à : x = x / 4;   // x = 6
x %= 4;   // Équivalent à : x = x % 4;   // x = 2
```

## 🎭 Opérateur ternaire

```cpp
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max = 20

// Équivalent à :
int max;
if (a > b) {
    max = a;
} else {
    max = b;
}
```

## 🔢 Opérateurs bit à bit

```cpp
int a = 5;   // 0101 en binaire
int b = 3;   // 0011 en binaire

int et = a & b;    // ET : 0001 (1)
int ou = a | b;    // OU : 0111 (7)
int xor = a ^ b;   // XOR : 0110 (6)
int non = ~a;      // NON : ...11111010 (-6)
int gauche = a << 1;  // Décalage gauche : 1010 (10)
int droite = a >> 1;  // Décalage droite : 0010 (2)
```

## 📏 Priorité des opérateurs

De la plus haute à la plus basse priorité :

1. `()` Parenthèses
2. `++` `--` `!` `~` (unaires)
3. `*` `/` `%`
4. `+` `-`
5. `<<` `>>`
6. `<` `<=` `>` `>=`
7. `==` `!=`
8. `&` (ET bit à bit)
9. `^` (XOR)
10. `|` (OU bit à bit)
11. `&&` (ET logique)
12. `||` (OU logique)
13. `? :` (ternaire)
14. `=` `+=` `-=` etc.

**Conseil :** Utilisez des parenthèses pour clarifier vos intentions !

```cpp
int resultat = 2 + 3 * 4;      // 14 (multiplication d'abord)
int resultat2 = (2 + 3) * 4;   // 20 (addition d'abord)
```

## 💡 Exemple complet : Calculatrice simple

```cpp
#include <iostream>

int main() {
    double a, b;
    char operateur;
    
    std::cout << "Entrez une expression (ex: 5 + 3) : ";
    std::cin >> a >> operateur >> b;
    
    double resultat;
    
    switch (operateur) {
        case '+':
            resultat = a + b;
            break;
        case '-':
            resultat = a - b;
            break;
        case '*':
            resultat = a * b;
            break;
        case '/':
            if (b != 0) {
                resultat = a / b;
            } else {
                std::cout << "Erreur : division par zéro!\n";
                return 1;
            }
            break;
        default:
            std::cout << "Opérateur non reconnu!\n";
            return 1;
    }
    
    std::cout << "Résultat : " << resultat << "\n";
    return 0;
}
```

## 🎯 Exercices

### Exercice 1
Écrivez un programme qui :
1. Demande deux nombres à l'utilisateur
2. Affiche leur somme, différence, produit et quotient

### Exercice 2
Créez un programme qui détermine si un nombre est pair ou impair (utilisez l'opérateur modulo).

### Exercice 3
Écrivez une expression qui vérifie si un nombre `x` est dans l'intervalle [10, 20] (inclus).

<details>
<summary>Solution Exercice 3</summary>

```cpp
bool dansIntervalle = (x >= 10 && x <= 20);
// Ou avec C++20 :
bool dansIntervalle = (x >= 10) && (x <= 20);
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Structures de contrôle](03-structures-controle.md)
