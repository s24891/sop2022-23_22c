#include <stdio.h>

int main() {
    char operator;
    double liczba1, liczba2, wynik;

    printf("Podaj operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Podaj dwie liczby: ");
    scanf("%lf %lf", &liczba1, &liczba2);

    switch (operator) {
        case '+':
            wynik = liczba1 + liczba2;
            break;
        case '-':
            wynik = liczba1 - liczba2;
            break;
        case '*':
            wynik = liczba1 * liczba2;
            break;
        case '/':
            wynik = liczba1 / liczba2;
            break;
        default:
            printf("Nieprawidłowy operator");
            return 1;
    }

    printf("%.2lf %c %.2lf = %.2lf", liczba1, operator, liczba2, wynik);
    return 0;
}
