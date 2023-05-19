#!/bin/bash

# sprawdzenie, czy podano nazwę pliku jako argument skryptu
if [ $# -lt 1 ]; then
    echo "Podaj nazwę pliku jako argument skryptu."
    exit 1
fi

# wczytanie nazwy pliku z argumentu skryptu
filename=$1

# sprawdzenie, czy plik istnieje i jest plikiem tekstowym
if [ ! -f "$filename" ] || [ ! -r "$filename" ] || ! file -b "$filename" | grep -q text; then
    echo "Nie można odczytać pliku $filename."
    exit 1
fi

# ustawienie nazwy imienia
twojeimie="Krzysztof"

# zastąpienie wszystkich wystąpień imienia na czerwono
highlighted=$(sed -e "s/$twojeimie/\o033[91m&\o033[0m/gI" "$filename")

# wypisanie podświetlonej zawartości na ekranie
echo -e "$highlighted"
