# Tests pedagogiques

Ce dossier contient des tests automatisés qui valident des notions clés du cours.

## Objectif

- Vérifier des comportements concrets (algorithmes, optional, move semantics)
- Vérifier des notions modernes (concepts, ranges)
- Compléter la simple compilation des exemples par une exécution avec assertions

## Fichiers actuels

- `pedagogie/test_algorithmes_optional_move.cpp`
- `pedagogie/test_concepts_ranges.cpp`

## Exécution locale (GCC/Clang)

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror tests/pedagogie/test_algorithmes_optional_move.cpp -o test1
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror tests/pedagogie/test_concepts_ranges.cpp -o test2
./test1 && ./test2
```

## CI

Ces tests sont exécutés automatiquement via:

- `.github/workflows/tests-pedagogie.yml`
