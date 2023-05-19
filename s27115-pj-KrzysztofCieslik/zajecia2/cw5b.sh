#!/bin/bash

if [ -z "$1" ]; then
  echo "Brak argumentu."
  exit 1
fi
echo "Pierwszy znak: ${1:0:1}"
echo "Ostatni znak: ${1: -1}"
# Zamiana SOP na kolorowy tekst
echo -e "${1//SOP/\\e[32mSOP\\e[0m}"
