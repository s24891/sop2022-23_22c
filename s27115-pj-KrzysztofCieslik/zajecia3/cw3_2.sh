#!/bin/bash
#limitem jest że return jest intermpertowany jako exit code i jest on 
#8 bitowy co powoduje ograniczenie wartości do zakresu od 0 do 255 
#wyniki wieksze od 255 są nie określone
#informacja na ten temat znajduje sie w man exit
#aby to ominąć należało by wykorzystać inny mechanizm przekazania
#zmiennej poza funkcję np.przypisane go do zmiennej dostępnej w 
#funkcji i poza nią lub np. wykorzystać strumień wyjściowy  


fibonacci() {
    if [ "$1" -le 0 ]; then
        return "$1"
    elif [ "$1" -eq 1 ]; then
        return 1
    else
        local a
        local b
        fibonacci "$(( $1 - 1 ))"
        a=$?
        fibonacci "$(( $1 - 2 ))"
        b=$?
        return "$(( $a + $b ))"
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
for i in $(seq 1 $n); do
    fibonacci "$i"
    echo "$?"
done
