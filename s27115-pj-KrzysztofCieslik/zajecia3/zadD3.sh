#!/bin/bash
email="$1"
if [[ ! "$email" =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
    echo "Niepoprawny adres email"
    exit 1
fi
domain=${email##*@}
if [[ ! $domain =~ ^[a-zA-Z]{2,}$|^[a-zA-Z]{2,}\.[a-zA-Z]{2,}$ ]]; then
    echo "Niepoprawna końcówka domeny"
    exit 1
fi
echo "Adres email poprawny"
