#!/bin/bash
if [ -z "$1" ]; then
  echo "Brak argumentu."
  exit 1
fi
if [[ "$1" =~ a$ ]]; then
  imie="${1::-1}ę"
else
  imie="$1a"
fi
echo "$1 ma kota, a kot ma $imie"
