# Héritage et Polymorphisme

## 🎯 Objectif

Maîtriser l'héritage et le polymorphisme, deux piliers de la programmation orientée objet.

## 🌳 Qu'est-ce que l'Héritage ?

L'**héritage** permet de créer une nouvelle classe basée sur une classe existante, héritant de ses attributs et méthodes.

```cpp
// Classe de base (parent)
class Animal {
protected:
    std::string nom_;
    int age_;

public:
    Animal(std::string nom, int age) : nom_(nom), age_(age) {}
    
    void manger() {
        std::cout << nom_ << " mange.\n";
    }
    
    void dormir() {
        std::cout << nom_ << " dort.\n";
    }
};

// Classe dérivée (enfant)
class Chien : public Animal {
private:
    std::string race_;

public:
    Chien(std::string nom, int age, std::string race)
        : Animal(nom, age), race_(race) {}
    
    void aboyer() {
        std::cout << nom_ << " aboie: Woof!\n";
    }
};

int main() {
    Chien rex("Rex", 3, "Berger Allemand");
    rex.manger();   // Méthode héritée
    rex.dormir();   // Méthode héritée
    rex.aboyer();   // Méthode propre
    
    return 0;
}
```

## 🔑 Types d'Héritage

### Héritage public (le plus courant)

```cpp
class Base {
public:
    int valeurPublique;
protected:
    int valeurProtegee;
private:
    int valeurPrivee;
};

// Héritage public : public reste public, protected reste protected
class Derivee : public Base {
    void methode() {
        valeurPublique = 1;    // ✅ OK
        valeurProtegee = 2;    // ✅ OK
        // valeurPrivee = 3;   // ❌ ERREUR : private non accessible
    }
};
```

## 🎭 Polymorphisme et Fonctions Virtuelles

Le **polymorphisme** permet d'utiliser un objet dérivé comme s'il était de type base.

### Sans virtual (comportement statique)

```cpp
class Forme {
public:
    void dessiner() {
        std::cout << "Dessine une forme\n";
    }
};

class Cercle : public Forme {
public:
    void dessiner() {
        std::cout << "Dessine un cercle\n";
    }
};

int main() {
    Cercle c;
    Forme* ptr = &c;
    ptr->dessiner();  // Affiche "Dessine une forme" (pas ce qu'on veut!)
    
    return 0;
}
```

### Avec virtual (polymorphisme dynamique)

```cpp
class Forme {
public:
    virtual void dessiner() {  // ← Mot-clé virtual
        std::cout << "Dessine une forme\n";
    }
    
    virtual ~Forme() {}  // Destructeur virtuel important!
};

class Cercle : public Forme {
public:
    void dessiner() override {  // ← override recommandé (C++11)
        std::cout << "Dessine un cercle ⭕\n";
    }
};

class Rectangle : public Forme {
public:
    void dessiner() override {
        std::cout << "Dessine un rectangle ▭\n";
    }
};

int main() {
    Cercle c;
    Rectangle r;
    
    Forme* formes[] = {&c, &r};
    
    for (auto forme : formes) {
        forme->dessiner();  // Appelle la bonne méthode!
    }
    
    return 0;
}
```

## 🔷 Classes Abstraites et Interfaces

Une **classe abstraite** contient au moins une **fonction virtuelle pure** et ne peut pas être instanciée.

```cpp
class Drawable {  // Interface (classe abstraite)
public:
    // Fonction virtuelle pure
    virtual void draw() = 0;  // = 0 signifie "pure"
    
    virtual ~Drawable() {}
};

class Button : public Drawable {
public:
    void draw() override {
        std::cout << "🔘 Dessine un bouton\n";
    }
};

class Image : public Drawable {
public:
    void draw() override {
        std::cout << "🖼️ Dessine une image\n";
    }
};

int main() {
    // Drawable d;  // ❌ ERREUR : classe abstraite
    
    Button btn;
    Image img;
    
    Drawable* elements[] = {&btn, &img};
    
    for (auto elem : elements) {
        elem->draw();
    }
    
    return 0;
}
```

## 💡 Exemple Complet : Système de Formes

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Classe abstraite de base
class Forme {
protected:
    std::string couleur_;

public:
    Forme(std::string couleur) : couleur_(couleur) {}
    
    virtual ~Forme() {}
    
    // Méthodes virtuelles pures
    virtual double aire() const = 0;
    virtual double perimetre() const = 0;
    virtual void afficher() const = 0;
    
    // Méthode virtuelle avec implémentation
    virtual void changerCouleur(std::string c) {
        couleur_ = c;
    }
};

class Cercle : public Forme {
private:
    double rayon_;
    static constexpr double PI = 3.14159265359;

public:
    Cercle(double rayon, std::string couleur = "rouge")
        : Forme(couleur), rayon_(rayon) {}
    
    double aire() const override {
        return PI * rayon_ * rayon_;
    }
    
    double perimetre() const override {
        return 2 * PI * rayon_;
    }
    
    void afficher() const override {
        std::cout << "⭕ Cercle " << couleur_ 
                  << " (rayon: " << rayon_ << ")\n";
    }
};

class Rectangle : public Forme {
private:
    double largeur_, hauteur_;

public:
    Rectangle(double l, double h, std::string couleur = "bleu")
        : Forme(couleur), largeur_(l), hauteur_(h) {}
    
    double aire() const override {
        return largeur_ * hauteur_;
    }
    
    double perimetre() const override {
        return 2 * (largeur_ + hauteur_);
    }
    
    void afficher() const override {
        std::cout << "▭ Rectangle " << couleur_ 
                  << " (" << largeur_ << "x" << hauteur_ << ")\n";
    }
};

class Triangle : public Forme {
private:
    double base_, hauteur_;

public:
    Triangle(double b, double h, std::string couleur = "vert")
        : Forme(couleur), base_(b), hauteur_(h) {}
    
    double aire() const override {
        return (base_ * hauteur_) / 2;
    }
    
    double perimetre() const override {
        // Simplifié pour triangle isocèle
        return base_ + 2 * std::sqrt((base_/2)*(base_/2) + hauteur_*hauteur_);
    }
    
    void afficher() const override {
        std::cout << "🔺 Triangle " << couleur_ 
                  << " (base: " << base_ << ", h: " << hauteur_ << ")\n";
    }
};

int main() {
    // Utilisation de smart pointers
    std::vector<std::unique_ptr<Forme>> formes;
    
    formes.push_back(std::make_unique<Cercle>(5.0, "rouge"));
    formes.push_back(std::make_unique<Rectangle>(4.0, 6.0, "bleu"));
    formes.push_back(std::make_unique<Triangle>(5.0, 3.0, "vert"));
    
    std::cout << "=== Collection de Formes ===\n\n";
    
    double aireTotal = 0;
    
    for (const auto& forme : formes) {
        forme->afficher();
        std::cout << "  Aire: " << forme->aire() << "\n";
        std::cout << "  Périmètre: " << forme->perimetre() << "\n\n";
        
        aireTotal += forme->aire();
    }
    
    std::cout << "Aire totale: " << aireTotal << "\n";
    
    return 0;
}
```

## 🔧 Règles Importantes

### 1. Destructeur virtuel

**Toujours** déclarer le destructeur virtuel dans les classes de base :

```cpp
class Base {
public:
    virtual ~Base() {}  // ✅ Important!
};

class Derivee : public Base {
private:
    int* data;
public:
    Derivee() : data(new int[100]) {}
    ~Derivee() { delete[] data; }
};

int main() {
    Base* ptr = new Derivee();
    delete ptr;  // Appelle le bon destructeur grâce à virtual
    return 0;
}
```

### 2. override et final (C++11)

```cpp
class Base {
public:
    virtual void methode() {}
};

class Derivee : public Base {
public:
    void methode() override {}  // ✅ Vérifie qu'on override bien
};

class Finale : public Base {
public:
    void methode() override final {}  // Ne peut plus être override
};
```

### 3. Appeler le constructeur de base

```cpp
class Vehicule {
protected:
    int vitesseMax_;
public:
    Vehicule(int v) : vitesseMax_(v) {}
};

class Voiture : public Vehicule {
private:
    int nombrePortes_;
public:
    // ✅ Appeler le constructeur de base
    Voiture(int v, int p) : Vehicule(v), nombrePortes_(p) {}
};
```

## 🎯 Exercices

### Exercice 1
Créez une hiérarchie `Employe` (classe de base) avec les dérivées :
- `EmployeHoraire` (salaire horaire)
- `EmployeSalarie` (salaire mensuel)

Chaque classe doit avoir une méthode `calculerPaie()`.

### Exercice 2
Créez une interface `Serializable` avec une méthode virtuelle pure `toJSON()`.
Implémentez-la dans une classe `Produit`.

### Exercice 3
Créez une hiérarchie d'animaux avec :
- Classe de base `Animal`
- Dérivées : `Chien`, `Chat`, `Oiseau`
- Méthode virtuelle `faireDuBruit()`

<details>
<summary>Solution Exercice 3</summary>

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal {
protected:
    std::string nom_;
public:
    Animal(std::string nom) : nom_(nom) {}
    virtual ~Animal() {}
    
    virtual void faireDuBruit() const = 0;
    
    std::string getNom() const { return nom_; }
};

class Chien : public Animal {
public:
    Chien(std::string nom) : Animal(nom) {}
    
    void faireDuBruit() const override {
        std::cout << nom_ << " dit: Woof! 🐕\n";
    }
};

class Chat : public Animal {
public:
    Chat(std::string nom) : Animal(nom) {}
    
    void faireDuBruit() const override {
        std::cout << nom_ << " dit: Miaou! 🐈\n";
    }
};

class Oiseau : public Animal {
public:
    Oiseau(std::string nom) : Animal(nom) {}
    
    void faireDuBruit() const override {
        std::cout << nom_ << " dit: Cui cui! 🐦\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animaux;
    
    animaux.push_back(std::make_unique<Chien>("Rex"));
    animaux.push_back(std::make_unique<Chat>("Minou"));
    animaux.push_back(std::make_unique<Oiseau>("Tweety"));
    
    for (const auto& animal : animaux) {
        animal->faireDuBruit();
    }
    
    return 0;
}
```
</details>

## 📚 Points Clés

✅ **Héritage** : réutilisation du code via "est-un" relation  
✅ **virtual** : permet le polymorphisme dynamique  
✅ **override** : vérifie qu'on override correctement  
✅ **Classes abstraites** : au moins une fonction virtuelle pure  
✅ **Destructeur virtuel** : essentiel pour les hiérarchies  

## 📚 Prochaine étape

Passez au [Chapitre 3 : Smart Pointers](../03-moderne/01-smart-pointers.md)
