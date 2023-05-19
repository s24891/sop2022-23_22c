#!/bin/bash
if [[ "${0: -3}" != ".sh" ]]; then
  echo "zmiana nazwy na  $0.sh"
  mv "$0" "$0.sh"
fi
