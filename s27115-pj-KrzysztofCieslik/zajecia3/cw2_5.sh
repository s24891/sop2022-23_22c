#!/bin/bash


files=("$@")
for (( i=0; i<${#files[@]}; i++ )); do
    echo "Plik: ${files[$i]}"
    while read -n1 char; do
        echo -n "$char"
    done < "${files[$i]}"
    echo ""
done
for (( i=${#files[@]}-1; i>=0; i-- )); do
    echo "Plik (odwrócona kolejność): ${files[$i]}"
    len=$(wc -c < "${files[$i]}")
    for (( j=len-1; j>=0; j-- )); do
        dd if="${files[$i]}" bs=1 count=1 skip=$j 2>/dev/null
    done
    echo ""
done
