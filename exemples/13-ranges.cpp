#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::cout << "=== Ranges C++20 ===\n";

    std::vector<int> notes = {11, 18, 7, 15, 20, 9, 14, 16};

    auto pipeline = notes
        | std::views::filter([](int n) { return n >= 10; })
        | std::views::transform([](int n) { return n * 2; })
        | std::views::take(5);

    std::vector<int> resultat;
    for (int n : pipeline) {
        resultat.push_back(n);
    }

    std::ranges::sort(resultat, std::greater<>{});

    std::cout << "Notes valides x2 (top 5, tri desc): ";
    for (int n : resultat) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
 * Ce programme démontre :
 * - std::views::filter
 * - std::views::transform
 * - std::views::take
 * - Materialisation d'une vue en std::vector
 * - std::ranges::sort avec comparateur
 */

/*
 * Compilation et exécution :
 * g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 13-ranges.cpp -o ranges
 * ./ranges
 */
