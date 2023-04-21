#!/bin/bash

# Sprawdzenie, czy nazwa pliku kończy się na .sh
if [[ "${0##*.}" != "sh" ]]; then
  # Dodanie rozszerzenia .sh do nazwy pliku
  mv "$0" "${0}.sh"
  echo "Zmieniono nazwę pliku na ${0}.sh"
fi
