#!/bin/bash

fibonacci() {
    if [ "$1" -le 1 ]; then
        echo "$1"
    else
        local a=$(fibonacci "$(( $1 - 1 ))")
        local b=$(fibonacci "$(( $1 - 2 ))")
        echo "$(( $a + $b ))"
    fi
}

if [ "$#" -ne 1 ]; then
    echo "Podaj jeden argument - wartość n."
    exit 1
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Wartość n musi być nieujemna."
    exit 1
fi

n=$1
for i in $(seq 0 $(( n - 1 ))); do
    echo $(fibonacci "$i")
done
