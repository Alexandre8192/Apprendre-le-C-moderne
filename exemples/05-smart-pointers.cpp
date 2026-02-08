#include <iostream>
#include <memory>
#include <string>

class Personne {
public:
    Personne(std::string nom) : nom_(nom) {
        std::cout << "✓ Création de " << nom_ << "\n";
    }
    
    ~Personne() {
        std::cout << "✗ Destruction de " << nom_ << "\n";
    }
    
    void saluer() const {
        std::cout << "Bonjour, je suis " << nom_ << "!\n";
    }

private:
    std::string nom_;
};

void exempleUniquePtr() {
    std::cout << "\n=== Exemple unique_ptr ===\n";
    
    // Création d'un unique_ptr
    auto personne1 = std::make_unique<Personne>("Alice");
    personne1->saluer();
    
    // Transfert de propriété avec move
    auto personne2 = std::move(personne1);
    // personne1 est maintenant nullptr
    
    if (!personne1) {
        std::cout << "personne1 est null après move\n";
    }
    
    personne2->saluer();
    // Destruction automatique à la fin du scope
}

void exempleSharedPtr() {
    std::cout << "\n=== Exemple shared_ptr ===\n";
    
    auto personne1 = std::make_shared<Personne>("Bob");
    std::cout << "Compteur de références: " << personne1.use_count() << "\n";
    
    {
        // Partage de la propriété
        auto personne2 = personne1;
        std::cout << "Compteur de références: " << personne1.use_count() << "\n";
        personne2->saluer();
    }
    
    std::cout << "Compteur de références après scope: " << personne1.use_count() << "\n";
    // Destruction automatique quand compteur = 0
}

int main() {
    exempleUniquePtr();
    exempleSharedPtr();
    
    std::cout << "\nFin du programme\n";
    return 0;
}

/*
   * Compilation et exécution :
   * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 05-smart-pointers.cpp -o smart_pointers
   * ./smart_pointers
*/
