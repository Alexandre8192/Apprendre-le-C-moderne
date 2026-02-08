# Classes et Objets - Introduction à la POO

## 🎯 Objectif

Comprendre les concepts fondamentaux de la programmation orientée objet (POO) en C++ et créer vos premières classes.

## 📦 Qu'est-ce qu'une Classe ?

Une **classe** est un modèle (blueprint) qui définit les propriétés (attributs) et les comportements (méthodes) d'un objet.

Un **objet** est une instance d'une classe.

## 💡 Première Classe Simple

```cpp
#include <iostream>
#include <string>

// Définition d'une classe
class Personne {
public:
    // Attributs (propriétés)
    std::string nom;
    int age;
    
    // Méthode (comportement)
    void sePresenter() {
        std::cout << "Je m'appelle " << nom << " et j'ai " << age << " ans.\n";
    }
};

int main() {
    // Créer un objet (instance de la classe)
    Personne alice;
    alice.nom = "Alice";
    alice.age = 25;
    alice.sePresenter();  // Appel de méthode
    
    // Autre objet
    Personne bob;
    bob.nom = "Bob";
    bob.age = 30;
    bob.sePresenter();
    
    return 0;
}
```

## 🏗️ Constructeurs et Destructeurs

### Constructeur

Un **constructeur** initialise un objet lors de sa création.

```cpp
class Personne {
public:
    std::string nom;
    int age;
    
    // Constructeur
    Personne(std::string n, int a) : nom(n), age(a) {
        std::cout << "Création de " << nom << "\n";
    }
    
    void sePresenter() {
        std::cout << "Je suis " << nom << ", " << age << " ans.\n";
    }
};

int main() {
    Personne alice("Alice", 25);  // Appel du constructeur
    alice.sePresenter();
    
    return 0;
}
```

### Constructeur par défaut

```cpp
class Rectangle {
public:
    double largeur;
    double hauteur;
    
    // Constructeur par défaut
    Rectangle() : largeur(0), hauteur(0) {
        std::cout << "Rectangle créé avec dimensions 0x0\n";
    }
    
    // Constructeur avec paramètres
    Rectangle(double l, double h) : largeur(l), hauteur(h) {
        std::cout << "Rectangle créé " << l << "x" << h << "\n";
    }
    
    double aire() {
        return largeur * hauteur;
    }
};

int main() {
    Rectangle r1;              // Utilise constructeur par défaut
    Rectangle r2(5.0, 3.0);    // Utilise constructeur paramétré
    
    std::cout << "Aire r2: " << r2.aire() << "\n";
    
    return 0;
}
```

### Destructeur

Un **destructeur** nettoie les ressources quand l'objet est détruit.

```cpp
class Fichier {
public:
    std::string nom;
    
    // Constructeur
    Fichier(std::string n) : nom(n) {
        std::cout << "📂 Ouverture de " << nom << "\n";
    }
    
    // Destructeur (commence par ~)
    ~Fichier() {
        std::cout << "🔒 Fermeture de " << nom << "\n";
    }
};

int main() {
    {
        Fichier f("data.txt");
        // Utilisation du fichier...
    }  // Le destructeur est appelé automatiquement ici !
    
    std::cout << "Fin du programme\n";
    return 0;
}
```

## 🔒 Encapsulation : public, private, protected

L'**encapsulation** protège les données d'une classe.

```cpp
class CompteBancaire {
private:
    // Attributs privés (inaccessibles de l'extérieur)
    double solde;
    std::string titulaire;

public:
    // Constructeur
    CompteBancaire(std::string nom, double montantInitial) 
        : titulaire(nom), solde(montantInitial) {}
    
    // Méthodes publiques (interface)
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            std::cout << "Dépôt de " << montant << "€\n";
        }
    }
    
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            std::cout << "Retrait de " << montant << "€\n";
        } else {
            std::cout << "Retrait impossible!\n";
        }
    }
    
    // Getter (accesseur)
    double obtenirSolde() const {
        return solde;
    }
    
    void afficherInfo() const {
        std::cout << "Compte de " << titulaire 
                  << " : " << solde << "€\n";
    }
};

int main() {
    CompteBancaire compte("Alice", 1000.0);
    
    // compte.solde = 999999;  // ERREUR : solde est privé !
    
    compte.deposer(500);
    compte.retirer(200);
    compte.afficherInfo();
    
    return 0;
}
```

### Modificateurs d'accès

| Modificateur | Accès |
|--------------|-------|
| `public` | Accessible partout |
| `private` | Accessible uniquement dans la classe |
| `protected` | Accessible dans la classe et ses dérivées |

## ✨ Méthodes const

Une méthode `const` ne modifie pas l'état de l'objet :

```cpp
class Point {
private:
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    
    // Méthode const : ne modifie pas l'objet
    double distance() const {
        return std::sqrt(x * x + y * y);
    }
    
    void afficher() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
    
    // Méthode non-const : modifie l'objet
    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};
```

## 🎨 Getters et Setters

**Bonne pratique** : Utiliser des getters/setters pour accéder aux attributs privés.

```cpp
class Etudiant {
private:
    std::string nom_;
    double moyenne_;

public:
    Etudiant(std::string nom, double moyenne) 
        : nom_(nom), moyenne_(moyenne) {}
    
    // Getter
    std::string getNom() const {
        return nom_;
    }
    
    double getMoyenne() const {
        return moyenne_;
    }
    
    // Setter avec validation
    void setMoyenne(double m) {
        if (m >= 0 && m <= 20) {
            moyenne_ = m;
        } else {
            std::cout << "Moyenne invalide!\n";
        }
    }
};
```

## 🔧 Méthodes statiques

Les méthodes **statiques** appartiennent à la classe, pas aux objets :

```cpp
class Mathematiques {
public:
    // Méthode statique
    static double carre(double x) {
        return x * x;
    }
    
    static constexpr double PI = 3.14159265359;
};

int main() {
    // Appel sans créer d'objet
    double resultat = Mathematiques::carre(5);
    std::cout << "5² = " << resultat << "\n";
    std::cout << "π = " << Mathematiques::PI << "\n";
    
    return 0;
}
```

## 💡 Exemple Complet : Classe Voiture

```cpp
#include <iostream>
#include <string>

class Voiture {
private:
    std::string marque_;
    std::string modele_;
    int annee_;
    double kilometrage_;

public:
    // Constructeur
    Voiture(std::string marque, std::string modele, int annee)
        : marque_(marque), modele_(modele), annee_(annee), kilometrage_(0) {
        std::cout << "🚗 Nouvelle voiture créée: " 
                  << marque_ << " " << modele_ << "\n";
    }
    
    // Destructeur
    ~Voiture() {
        std::cout << "🔧 Voiture détruite: " << marque_ << " " << modele_ << "\n";
    }
    
    // Méthodes
    void conduire(double km) {
        if (km > 0) {
            kilometrage_ += km;
            std::cout << "Conduite de " << km << " km\n";
        }
    }
    
    void afficherInfo() const {
        std::cout << "\n=== Informations Voiture ===\n";
        std::cout << "Marque: " << marque_ << "\n";
        std::cout << "Modèle: " << modele_ << "\n";
        std::cout << "Année: " << annee_ << "\n";
        std::cout << "Kilométrage: " << kilometrage_ << " km\n";
    }
    
    // Getters
    double getKilometrage() const { return kilometrage_; }
    std::string getMarque() const { return marque_; }
};

int main() {
    Voiture maCar("Toyota", "Corolla", 2023);
    
    maCar.conduire(150.5);
    maCar.conduire(80.0);
    maCar.afficherInfo();
    
    return 0;
}
// Le destructeur est appelé automatiquement ici
```

## 🎯 Exercices

### Exercice 1
Créez une classe `Livre` avec :
- Attributs privés : titre, auteur, nombrePages
- Constructeur
- Getters
- Méthode `afficher()`

### Exercice 2
Créez une classe `CompteurClics` avec :
- Attribut privé : nombre de clics
- Méthode `cliquer()` qui incrémente
- Méthode `obtenirClics()` qui retourne le compteur
- Méthode `reinitialiser()`

### Exercice 3
Créez une classe `Cercle` avec :
- Attribut privé : rayon
- Méthodes pour calculer l'aire et le périmètre
- Méthode statique constexpr pour PI

<details>
<summary>Solution Exercice 1</summary>

```cpp
#include <iostream>
#include <string>

class Livre {
private:
    std::string titre_;
    std::string auteur_;
    int nombrePages_;

public:
    Livre(std::string titre, std::string auteur, int pages)
        : titre_(titre), auteur_(auteur), nombrePages_(pages) {}
    
    std::string getTitre() const { return titre_; }
    std::string getAuteur() const { return auteur_; }
    int getNombrePages() const { return nombrePages_; }
    
    void afficher() const {
        std::cout << "📚 " << titre_ << " par " << auteur_ 
                  << " (" << nombrePages_ << " pages)\n";
    }
};

int main() {
    Livre livre("Le Petit Prince", "Antoine de Saint-Exupéry", 96);
    livre.afficher();
    return 0;
}
```
</details>

## 📚 Prochaine étape

Passez au chapitre suivant : [Héritage et Polymorphisme](05-heritage.md)
