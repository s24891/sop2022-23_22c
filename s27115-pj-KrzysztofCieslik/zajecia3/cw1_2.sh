#!/bin/bash
if [ -f "config.cfg" ]; then
  echo "Wykonywanie pliku config.cfg"
  sh config.cfg
elif [ $# -eq 1 ]; then
  if [ -f "$1" ]; then
    echo "Wykonywanie pliku $1"
    sh "$1"
  else
    echo "Błąd: Plik $1 nie istnieje"
  fi
else
  echo "Błąd: Brak pliku config.cfg i brak argumentu"
fi
