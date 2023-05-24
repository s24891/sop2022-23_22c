#include <stdio.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int sum(int a, int b) {
    return a + b;
}

/*przyjmuje 
1.wskaźnik na tablicę liczb całkowitych 
2.liczbę elementów w tablicy 
3.wskaźnik do funkcji, która przyjmuje dwie liczby całkowite i zwraca liczbę całkowitą. 
Funkcja iteruje po tablicy, wywołując przekazaną funkcję na kolejnych elementach .*/

int forAll(int* array, int elementCount, int (*f)(int, int)) {
    int v = array[0];
    for (int i = 1; i < elementCount; i++) {
        v = f(v, array[i]);
    }
    return v;
}

int main() {
    int (*functions[3])(int, int) = {maximum, minimum, sum};
    /* Deklaracja i inicjalizacja tablicy functions. 
    Tablica ma rozmiar 3 i przechowuje wskaźniki do funkcji "maximum", "minimum" i "sum".*/

    int functionId;
    int elementCount;
    scanf("%d", &functionId);
    scanf("%d", &elementCount);

    int array[elementCount];
    for (int i = 0; i < elementCount; i++) {
        scanf("%d", &array[i]);
    }

    int result = forAll(array, elementCount, functions[functionId]);
    printf("Result: %d\n", result);

    return 0;
}