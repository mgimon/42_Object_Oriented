#!/bin/bash

# Array con expresiones válidas para stress test
valid_tests=(
  "3 -2 5 + * 4 /"
  "0 1 2 3 4 5 6 7 8 + + + + + + + +"
  "10 -10 5 - * 2 /"
  "4 0 -3 * 2 + 5 /"
  "-1 -2 -3 -4 -5 + + + +"
  "1 2 3 4 5 6 7 8 9 + - * / + - - -"
  "1 2 3 4 5 6 7 8 9 + - * / +"
  "1 2 3 4 5 6 7 8 9 + - * / + - - -"
)

# Array con expresiones inválidas para stress test (parseo / errores)
invalid_tests=(
  "3 4 5 & +"
  "     "
  "5 +"
  "1 2 + + +"
  "++3 4 -2 *"
  "5 1 + +"
  "1 2 + + +"
  "8 2 / 2 / 0 /"
  "+ - * / 1 2 3 4"
)

echo "### TESTS VÁLIDOS ###"
for test in "${valid_tests[@]}"; do
  echo -e "\nTest: '$test'"
  ./RPN "$test"
done

echo -e "\n### TESTS INVÁLIDOS / ERRORES ###"
for test in "${invalid_tests[@]}"; do
  echo -e "\nTest: '$test'"
  ./RPN "$test"
done
