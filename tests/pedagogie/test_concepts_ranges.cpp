#include <algorithm>
#include <cassert>
#include <concepts>
#include <ranges>
#include <vector>

template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T add(T a, T b) {
    return a + b;
}

int main() {
    static_assert(Numeric<int>);
    static_assert(Numeric<double>);
    static_assert(!Numeric<const char*>);

    assert(add(2, 3) == 5);
    assert(add(2.5, 0.5) == 3.0);

    std::vector<int> v = {5, 2, 9, 4, 6, 1, 8};

    auto vue = v
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) { return x * x; })
        | std::views::take(3);

    std::vector<int> resultat;
    for (int x : vue) {
        resultat.push_back(x);
    }

    assert((resultat == std::vector<int>{4, 16, 36}));

    std::ranges::sort(resultat, std::greater<>{});
    assert((resultat == std::vector<int>{36, 16, 4}));

    return 0;
}
