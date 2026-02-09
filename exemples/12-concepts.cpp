#include <concepts>
#include <iostream>
#include <string>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T addition(T a, T b) {
    return a + b;
}

template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Comparable T>
const T& minimum(const T& a, const T& b) {
    return (b < a) ? b : a;
}

int main() {
    std::cout << "=== Concepts C++20 ===\n";
    std::cout << "addition(10, 5) = " << addition(10, 5) << "\n";
    std::cout << "addition(2.5, 1.5) = " << addition(2.5, 1.5) << "\n";

    std::string a = "alpha";
    std::string b = "beta";
    std::cout << "minimum(\"" << a << "\", \"" << b << "\") = "
              << minimum(a, b) << "\n";

    // Décommentez pour voir une erreur de contrainte:
    // struct NonNumerique {};
    // auto x = addition(NonNumerique{}, NonNumerique{});

    return 0;
}

/*
 * Ce programme démontre :
 * - Concepts standards (std::integral, std::floating_point)
 * - Concept personnalisé Numeric
 * - Clauses requires pour contraindre les templates
 * - Messages d'erreur plus clairs en cas de type invalide
 */

/*
 * Compilation et exécution :
 * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 12-concepts.cpp -o concepts
 * ./concepts
 */
