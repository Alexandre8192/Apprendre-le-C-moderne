# Smart Pointers - Gestion Moderne de la Mémoire

## 🎯 Objectif

Apprendre à gérer la mémoire de manière sûre avec les smart pointers (C++11/14/17).

## ⚠️ Le problème des pointeurs classiques

```cpp
// ❌ Problèmes avec les pointeurs bruts
void mauvaisExemple() {
    int* ptr = new int(42);
    // ... code qui peut lancer une exception
    delete ptr;  // Peut ne jamais être appelé si exception !
}

// ❌ Fuite mémoire
void fuiteMemoire() {
    int* ptr = new int(42);
    // Oubli de delete !
}  // Mémoire perdue

// ❌ Double suppression
void doubleSuppression() {
    int* ptr = new int(42);
    delete ptr;
    delete ptr;  // Comportement indéfini !
}
```

## ✨ Solution : Smart Pointers

Les smart pointers gèrent automatiquement la durée de vie des objets.

## 🎯 unique_ptr - Propriété exclusive

`unique_ptr` possède **exclusivement** l'objet pointé.

```cpp
#include <memory>

void exemple_unique_ptr() {
    // Création
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    
    // Accès à la valeur
    std::cout << *ptr << "\n";  // 42
    
    // Pas besoin de delete, automatique !
}  // ptr est automatiquement détruit ici
```

### Caractéristiques de unique_ptr

```cpp
// ✅ Création recommandée (C++14)
auto ptr1 = std::make_unique<int>(42);

// ❌ Ne peut pas être copié
auto ptr2 = ptr1;  // ERREUR de compilation

// ✅ Peut être déplacé
auto ptr3 = std::move(ptr1);  // ptr1 devient nullptr
if (ptr1 == nullptr) {
    std::cout << "ptr1 est maintenant null\n";
}

// Tableau dynamique
auto array = std::make_unique<int[]>(10);
array[0] = 42;
```

### Exemple avec une classe

```cpp
#include <memory>
#include <iostream>
#include <string>

class Personne {
public:
    Personne(std::string nom) : nom_(nom) {
        std::cout << "Création de " << nom_ << "\n";
    }
    
    ~Personne() {
        std::cout << "Destruction de " << nom_ << "\n";
    }
    
    void saluer() const {
        std::cout << "Bonjour, je suis " << nom_ << "\n";
    }

private:
    std::string nom_;
};

int main() {
    auto personne = std::make_unique<Personne>("Alice");
    personne->saluer();
    // Destruction automatique à la fin du scope
    return 0;
}
```

## 🤝 shared_ptr - Propriété partagée

`shared_ptr` permet à **plusieurs** pointeurs de partager la propriété.

```cpp
#include <memory>

void exemple_shared_ptr() {
    // Création
    auto ptr1 = std::make_shared<int>(42);
    
    {
        // Copie : référence partagée
        auto ptr2 = ptr1;
        std::cout << "Compteur de références : " << ptr1.use_count() << "\n";  // 2
        std::cout << "Valeur : " << *ptr2 << "\n";  // 42
    }  // ptr2 détruit, mais l'objet existe toujours
    
    std::cout << "Compteur : " << ptr1.use_count() << "\n";  // 1
}  // ptr1 détruit, objet finalement supprimé
```

### Exemple pratique : Graphe de données

```cpp
#include <memory>
#include <vector>
#include <string>

class Noeud {
public:
    std::string nom;
    std::vector<std::shared_ptr<Noeud>> voisins;
    
    Noeud(std::string n) : nom(n) {}
};

int main() {
    auto node1 = std::make_shared<Noeud>("A");
    auto node2 = std::make_shared<Noeud>("B");
    auto node3 = std::make_shared<Noeud>("C");
    
    // Créer des connexions
    node1->voisins.push_back(node2);
    node1->voisins.push_back(node3);
    node2->voisins.push_back(node3);
    
    // Pas de fuites mémoire, tout est automatique !
    return 0;
}
```

## 👀 weak_ptr - Référence faible

`weak_ptr` observe un `shared_ptr` sans augmenter le compteur de références.

```cpp
#include <memory>

void exemple_weak_ptr() {
    auto shared = std::make_shared<int>(42);
    std::weak_ptr<int> weak = shared;
    
    std::cout << "use_count: " << shared.use_count() << "\n";  // 1 (pas 2 !)
    
    // Pour utiliser un weak_ptr, le convertir en shared_ptr
    if (auto locked = weak.lock()) {
        std::cout << "Valeur : " << *locked << "\n";
    } else {
        std::cout << "L'objet n'existe plus\n";
    }
}
```

### Résoudre les références circulaires

```cpp
#include <memory>
#include <string>

class Enfant;  // Déclaration anticipée

class Parent {
public:
    std::string nom;
    std::shared_ptr<Enfant> enfant;  // shared_ptr
    
    Parent(std::string n) : nom(n) {}
    ~Parent() { std::cout << "~Parent(" << nom << ")\n"; }
};

class Enfant {
public:
    std::string nom;
    std::weak_ptr<Parent> parent;  // weak_ptr pour éviter cycle !
    
    Enfant(std::string n) : nom(n) {}
    ~Enfant() { std::cout << "~Enfant(" << nom << ")\n"; }
};

int main() {
    auto parent = std::make_shared<Parent>("Bob");
    auto enfant = std::make_shared<Enfant>("Alice");
    
    parent->enfant = enfant;
    enfant->parent = parent;  // Pas de cycle grâce à weak_ptr
    
    // Destructeurs appelés correctement
    return 0;
}
```

## 📊 Comparaison des smart pointers

| Type | Propriété | Copie | Move | Usage |
|------|-----------|-------|------|-------|
| `unique_ptr` | Exclusive | ❌ | ✅ | Propriété unique claire |
| `shared_ptr` | Partagée | ✅ | ✅ | Propriété multiple nécessaire |
| `weak_ptr` | Observer | ✅ | ✅ | Éviter cycles, observation |

## ✅ Bonnes pratiques

```cpp
// ✅ Utiliser make_unique et make_shared
auto ptr1 = std::make_unique<int>(42);
auto ptr2 = std::make_shared<int>(42);

// ❌ Éviter new direct
std::unique_ptr<int> ptr3(new int(42));  // Moins sûr

// ✅ Préférer unique_ptr par défaut
// Passer à shared_ptr seulement si nécessaire

// ✅ Utiliser auto
auto obj = std::make_unique<MaClasse>();

// ✅ Passer par référence pour ne pas transférer propriété
void traiter(const std::unique_ptr<MaClasse>& obj) {
    obj->methode();
}

// ✅ Passer par valeur pour transférer propriété
void prendre_propriete(std::unique_ptr<MaClasse> obj) {
    // obj est maintenant propriétaire
}
```

## 💡 Exemple complet : Gestionnaire de ressources

```cpp
#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Fichier {
public:
    Fichier(std::string nom) : nom_(nom) {
        std::cout << "Ouverture de " << nom_ << "\n";
    }
    
    ~Fichier() {
        std::cout << "Fermeture de " << nom_ << "\n";
    }
    
    void lire() const {
        std::cout << "Lecture de " << nom_ << "\n";
    }

private:
    std::string nom_;
};

class GestionnaireFichiers {
public:
    void ajouter(std::unique_ptr<Fichier> fichier) {
        fichiers_.push_back(std::move(fichier));
    }
    
    void lireTous() const {
        for (const auto& fichier : fichiers_) {
            fichier->lire();
        }
    }

private:
    std::vector<std::unique_ptr<Fichier>> fichiers_;
};

int main() {
    GestionnaireFichiers gestionnaire;
    
    gestionnaire.ajouter(std::make_unique<Fichier>("data.txt"));
    gestionnaire.ajouter(std::make_unique<Fichier>("config.ini"));
    
    gestionnaire.lireTous();
    
    // Fermeture automatique de tous les fichiers
    return 0;
}
```

## 🎯 Exercices

### Exercice 1
Convertissez ce code utilisant des pointeurs bruts en code utilisant `unique_ptr` :
```cpp
int* creerTableau(int taille) {
    return new int[taille];
}
// N'oubliez pas de delete[] !
```

### Exercice 2
Créez une classe `Node` pour une liste chaînée utilisant `unique_ptr` pour le pointeur `next`.

## 📚 Prochaine étape

Passez au chapitre suivant : [Lambda Expressions](02-lambdas.md)
