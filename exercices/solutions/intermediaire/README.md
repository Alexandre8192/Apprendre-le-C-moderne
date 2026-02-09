# Solutions - Niveau Intermediaire

Ce corrigé propose des solutions complètes pour une sélection d'exercices intermédiaires.
Les autres exercices peuvent être ajoutés au même format.

## Exercice 1 - Gestionnaire de contacts

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string nom;
    std::string telephone;
    std::string email;
};

class GestionnaireContacts {
public:
    void ajouter(Contact c) { contacts_.push_back(std::move(c)); }

    const Contact* chercher(const std::string& nom) const {
        auto it = std::find_if(contacts_.begin(), contacts_.end(),
                               [&nom](const auto& c) { return c.nom == nom; });
        return (it == contacts_.end()) ? nullptr : &(*it);
    }

    bool supprimer(const std::string& nom) {
        auto fin = std::remove_if(contacts_.begin(), contacts_.end(),
                                  [&nom](const auto& c) { return c.nom == nom; });
        if (fin == contacts_.end()) {
            return false;
        }
        contacts_.erase(fin, contacts_.end());
        return true;
    }

    void afficherTous() const {
        for (const auto& c : contacts_) {
            std::cout << c.nom << " | " << c.telephone << " | " << c.email << "\n";
        }
    }

private:
    std::vector<Contact> contacts_;
};
```

## Exercice 2 - Tri avec lambda

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Personne {
    std::string nom;
    int age;
};

int main() {
    std::vector<Personne> personnes = {
        {"Alice", 30}, {"Bob", 22}, {"Chloe", 30}, {"David", 27}
    };

    std::sort(personnes.begin(), personnes.end(),
              [](const auto& a, const auto& b) { return a.nom < b.nom; });

    std::sort(personnes.begin(), personnes.end(),
              [](const auto& a, const auto& b) { return a.age > b.age; });
}
```

## Exercice 3 - Liste chainee avec unique_ptr

```cpp
#include <iostream>
#include <memory>

class ListeChainee {
    struct Node {
        int valeur = 0;
        std::unique_ptr<Node> suivant;
        explicit Node(int v) : valeur(v) {}
    };

public:
    void ajouter(int valeur) {
        auto nouveau = std::make_unique<Node>(valeur);
        if (!tete_) {
            tete_ = std::move(nouveau);
            return;
        }
        Node* courant = tete_.get();
        while (courant->suivant) {
            courant = courant->suivant.get();
        }
        courant->suivant = std::move(nouveau);
    }

    bool trouver(int valeur) const {
        const Node* courant = tete_.get();
        while (courant) {
            if (courant->valeur == valeur) {
                return true;
            }
            courant = courant->suivant.get();
        }
        return false;
    }

private:
    std::unique_ptr<Node> tete_;
};
```

## Exercice 5 - Template de pile

```cpp
#include <stdexcept>
#include <vector>

template<typename T>
class Pile {
public:
    void push(T value) { data_.push_back(std::move(value)); }

    void pop() {
        if (data_.empty()) {
            throw std::out_of_range("Pile vide");
        }
        data_.pop_back();
    }

    T& top() {
        if (data_.empty()) {
            throw std::out_of_range("Pile vide");
        }
        return data_.back();
    }

    const T& top() const {
        if (data_.empty()) {
            throw std::out_of_range("Pile vide");
        }
        return data_.back();
    }

    bool empty() const { return data_.empty(); }
    std::size_t size() const { return data_.size(); }

private:
    std::vector<T> data_;
};
```

## Exercice 8 - Pipeline ranges

```cpp
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> nombres = {5, 2, 9, 4, 6, 1, 8, 10, 3, 12};

    auto vue = nombres
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * 2; });

    std::vector<int> resultat;
    for (int n : vue) {
        resultat.push_back(n);
    }

    std::ranges::sort(resultat);
    for (int n : resultat | std::views::take(5)) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}
```

## Exercice 11 - Analyse CSV + algorithmes STL

```cpp
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

struct Vente {
    std::string produit;
    int quantite = 0;
    double prix = 0.0;
    double total = 0.0;
};

int main() {
    std::ifstream entree("ventes.csv");
    std::vector<Vente> ventes;
    std::string ligne;

    while (std::getline(entree, ligne)) {
        std::stringstream ss(ligne);
        Vente v;
        std::string q;
        std::string p;
        if (std::getline(ss, v.produit, ',') &&
            std::getline(ss, q, ',') &&
            std::getline(ss, p, ',')) {
            v.quantite = std::stoi(q);
            v.prix = std::stod(p);
            ventes.push_back(v);
        }
    }

    std::transform(ventes.begin(), ventes.end(), ventes.begin(),
                   [](Vente v) {
                       v.total = static_cast<double>(v.quantite) * v.prix;
                       return v;
                   });

    double ca = std::accumulate(ventes.begin(), ventes.end(), 0.0,
                                [](double s, const Vente& v) { return s + v.total; });

    std::sort(ventes.begin(), ventes.end(),
              [](const Vente& a, const Vente& b) { return a.total > b.total; });

    std::cout << "CA total: " << ca << "\n";
}
```

## Exercice 13 - Simulateur de file d'attente

```cpp
#include <chrono>
#include <iostream>
#include <queue>
#include <string>

struct Client {
    std::string nom;
    int articles = 0;
    int arrivee = 0;
};

int main() {
    std::queue<Client> file;
    file.push({"Alice", 5, 0});
    file.push({"Bob", 12, 2});
    file.push({"Chloe", 3, 3});

    int temps = 0;
    int tempsTotalAttente = 0;
    int nbServis = 0;

    while (!file.empty()) {
        Client c = file.front();
        file.pop();

        int attente = std::max(0, temps - c.arrivee);
        int dureeService = std::max(1, c.articles / 3);
        temps += dureeService;

        tempsTotalAttente += attente;
        ++nbServis;
    }

    double attenteMoyenne = (nbServis == 0) ? 0.0
                                            : static_cast<double>(tempsTotalAttente) / nbServis;
    std::cout << "Attente moyenne: " << attenteMoyenne << "\n";
}
```
