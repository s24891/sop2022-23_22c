#!/bin/bash
#dla esperymentu postawnowilem użyć polecenia tree
#!/bin/bash

num_files=$(tree -L 1 | tail -n 1 | grep -o '[0-9]* file[s]*' | grep -o '[0-9]*')

if [ "$num_files" -gt 5 ]; then
   echo "W bieżącym katalogu jest więcej niż 5 plików."
else
    echo "W bieżącym katalogu jest maksymalnie 5 plików."
fi

