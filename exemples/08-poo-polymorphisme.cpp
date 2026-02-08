#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Classe de base simple
class Animal {
protected:
    std::string nom_;
    int age_;

public:
    Animal(std::string nom, int age) : nom_(nom), age_(age) {
        std::cout << "🐾 Animal créé: " << nom_ << "\n";
    }
    
    virtual ~Animal() {
        std::cout << "👋 Animal détruit: " << nom_ << "\n";
    }
    
    // Méthode virtuelle pour polymorphisme
    virtual void faireDuBruit() const {
        std::cout << nom_ << " fait du bruit\n";
    }
    
    virtual void afficher() const {
        std::cout << "Animal: " << nom_ << ", " << age_ << " ans\n";
    }
    
    std::string getNom() const { return nom_; }
    int getAge() const { return age_; }
};

// Classe dérivée : Chien
class Chien : public Animal {
private:
    std::string race_;

public:
    Chien(std::string nom, int age, std::string race)
        : Animal(nom, age), race_(race) {
        std::cout << "  🐕 Chien de race " << race_ << "\n";
    }
    
    void faireDuBruit() const override {
        std::cout << nom_ << " aboie: Woof woof! 🐕\n";
    }
    
    void afficher() const override {
        std::cout << "Chien: " << nom_ << " (" << race_ << "), " 
                  << age_ << " ans\n";
    }
    
    void apporter() const {
        std::cout << nom_ << " apporte la balle!\n";
    }
};

// Classe dérivée : Chat
class Chat : public Animal {
private:
    bool interieur_;

public:
    Chat(std::string nom, int age, bool interieur)
        : Animal(nom, age), interieur_(interieur) {
        std::cout << "  🐈 Chat " << (interieur_ ? "d'intérieur" : "d'extérieur") << "\n";
    }
    
    void faireDuBruit() const override {
        std::cout << nom_ << " miaule: Miaou! 🐈\n";
    }
    
    void afficher() const override {
        std::cout << "Chat: " << nom_ << ", " << age_ << " ans, "
                  << (interieur_ ? "intérieur" : "extérieur") << "\n";
    }
    
    void ronronner() const {
        std::cout << nom_ << " ronronne... 😺\n";
    }
};

// Classe dérivée : Oiseau
class Oiseau : public Animal {
private:
    double envergure_;

public:
    Oiseau(std::string nom, int age, double envergure)
        : Animal(nom, age), envergure_(envergure) {
        std::cout << "  🐦 Oiseau avec envergure de " << envergure_ << "m\n";
    }
    
    void faireDuBruit() const override {
        std::cout << nom_ << " chante: Cui cui! 🐦\n";
    }
    
    void afficher() const override {
        std::cout << "Oiseau: " << nom_ << ", " << age_ << " ans, "
                  << "envergure " << envergure_ << "m\n";
    }
    
    void voler() const {
        std::cout << nom_ << " vole dans le ciel!\n";
    }
};

// Fonction qui prend un Animal (polymorphisme)
void presenteAnimal(const Animal& animal) {
    std::cout << "\n=== Présentation ===\n";
    animal.afficher();
    animal.faireDuBruit();
}

int main() {
    std::cout << "=== Démonstration POO et Polymorphisme ===\n\n";
    
    // Création d'animaux
    std::cout << "--- Création des animaux ---\n";
    Chien rex("Rex", 5, "Berger Allemand");
    Chat minou("Minou", 3, true);
    Oiseau tweety("Tweety", 1, 0.15);
    
    // Polymorphisme avec références
    std::cout << "\n--- Polymorphisme (références) ---\n";
    presenteAnimal(rex);
    presenteAnimal(minou);
    presenteAnimal(tweety);
    
    // Méthodes spécifiques
    std::cout << "\n--- Méthodes spécifiques ---\n";
    rex.apporter();
    minou.ronronner();
    tweety.voler();
    
    // Polymorphisme avec smart pointers (recommandé)
    std::cout << "\n--- Collection polymorphe avec smart pointers ---\n";
    std::vector<std::unique_ptr<Animal>> zoo;
    
    zoo.push_back(std::make_unique<Chien>("Bella", 2, "Labrador"));
    zoo.push_back(std::make_unique<Chat>("Felix", 4, false));
    zoo.push_back(std::make_unique<Oiseau>("Piou", 1, 0.20));
    
    std::cout << "\n=== Tous les animaux du zoo ===\n";
    for (const auto& animal : zoo) {
        animal->afficher();
        animal->faireDuBruit();
        std::cout << "\n";
    }
    
    std::cout << "\n--- Fin du programme (destructeurs automatiques) ---\n";
    return 0;
}

/*
 * Ce programme démontre :
 * - Classes et héritage
 * - Constructeurs et destructeurs
 * - Encapsulation (private/protected/public)
 * - Polymorphisme avec virtual
 * - override keyword (C++11)
 * - Smart pointers avec polymorphisme
 * - Collection d'objets polymorphes
 * 
 * Compilation:
 * g++ -std=c++20 -Wall -Wextra 08-poo-polymorphisme.cpp -o poo
 * ./poo
 */
