#!/bin/bash
for file in *.c; do
    filename=$(basename -- "$file")
    extension="${filename##*.}"
    filename="${filename%.*}"
    cc "$file" -o "$filename"
done
