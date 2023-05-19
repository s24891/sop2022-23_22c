1.
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* plik = fopen("nazwa_pliku.txt", "r");
    if (plik == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    int liczba_elementow;
    fscanf(plik, "%d", &liczba_elementow);

    int* ciag = (int*)malloc(liczba_elementow * sizeof(int));

    for (int i = 0; i < liczba_elementow; i++) {
        fscanf(plik, "%d", &ciag[i]);
    }

    fclose(plik);

    printf("Liczby: ");
    for (int i = 0; i < liczba_elementow; i++) {
        printf("%d ", ciag[i]);
    }
    printf("\n");

    free(ciag);

    return 0;
}

2.
#include <stdio.h>
#include <stdlib.h>

void wypisz_w_odwrotnej_kolejnosci(int* ciag, int liczba_elementow) {
    for (int i = liczba_elementow - 1; i >= 0; i--) {
        printf("%d\n", ciag[i]);
    }
}

int main(int argc, char* argv[]) {
    FILE* plik = argc == 2 ? fopen(argv[1], "r") : stdin;
    if (plik == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    int liczba_elementow;
    fscanf(plik, "%d", &liczba_elementow);

    int* ciag = (int*)malloc(liczba_elementow * sizeof(int));
    if (ciag == NULL) {
        printf("Błąd alokacji pamięci.\n");
        if (plik != stdin) {
            fclose(plik);
        }
        return 1;
    }

    for (int i = 0; i < liczba_elementow; i++) {
        fscanf(plik, "%d", &ciag[i]);
    }

    if (plik != stdin) {
        fclose(plik);
    }

    wypisz_w_odwrotnej_kolejnosci(ciag, liczba_elementow);

    free(ciag);

    return 0;
}
