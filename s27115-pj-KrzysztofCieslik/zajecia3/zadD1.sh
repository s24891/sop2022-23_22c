#!/bin/bash
if [ $# -ne 1 ]; then
  echo "Podaj imię jako argument skryptu."
  exit 1
fi
pattern='^[A-ZŁŚĆŻŹÓĄĘ][a-złśćżźóąę]+$'
if [[ $1 =~ $pattern ]]; then
  echo "Imię jest poprawne."
else
  echo "Niepoprawne imię."
fi
