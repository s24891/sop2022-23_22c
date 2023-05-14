#!/bin/bash
if [[ "$0" != *.sh ]]; then
  echo "Zmiana nazwy na $0.sh"
  mv "$0" "$0.sh"
fi
