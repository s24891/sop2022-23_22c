#!/bin/bash

# sprawdzamy, czy podano więcej niż jeden parametr
if [ $# -gt 1 ]; then
  # jeśli tak, to wyświetlamy pierwszy parametr
  echo "Pierwszy parametr: $1"
else
  # jeśli nie, to wyświetlamy komunikat o braku parametrów
  echo "Nie podano parametrów"
fi
