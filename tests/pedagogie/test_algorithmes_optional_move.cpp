#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

std::optional<int> parseEntier(const std::string& texte) {
    if (texte.empty()) {
        return std::nullopt;
    }
    int signe = 1;
    std::size_t i = 0;
    if (texte[0] == '-') {
        signe = -1;
        i = 1;
    }
    if (i >= texte.size()) {
        return std::nullopt;
    }

    int valeur = 0;
    for (; i < texte.size(); ++i) {
        if (texte[i] < '0' || texte[i] > '9') {
            return std::nullopt;
        }
        valeur = valeur * 10 + (texte[i] - '0');
    }
    return signe * valeur;
}

int main() {
    const std::vector<int> valeurs = {1, 2, 3, 4, 5, 6};

    const auto nbPairs = std::count_if(valeurs.begin(), valeurs.end(),
                                       [](int v) { return v % 2 == 0; });
    assert(nbPairs == 3);

    std::vector<int> doubles;
    doubles.reserve(valeurs.size());
    std::transform(valeurs.begin(), valeurs.end(), std::back_inserter(doubles),
                   [](int v) { return v * 2; });
    assert((doubles == std::vector<int>{2, 4, 6, 8, 10, 12}));

    const int somme = std::accumulate(valeurs.begin(), valeurs.end(), 0);
    assert(somme == 21);

    assert(parseEntier("42").has_value());
    assert(parseEntier("42").value() == 42);
    assert(parseEntier("-7").value() == -7);
    assert(!parseEntier("4x").has_value());

    std::vector<int> source = {10, 20, 30};
    std::vector<int> cible = std::move(source);
    assert((cible == std::vector<int>{10, 20, 30}));

    // Un objet déplacé doit rester valide : on peut le réutiliser.
    source.push_back(99);
    assert(source.size() == 1);
    assert(source[0] == 99);

    return 0;
}
