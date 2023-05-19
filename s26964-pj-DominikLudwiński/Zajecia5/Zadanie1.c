#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Wypisanie numeru PID i PPID
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());

    // Oczekiwanie na dane od użytkownika
    printf("Czekam na dane od użytkownika...\n");
    char input[256];
    fgets(input, sizeof(input), stdin);

    // Program zakończony
    printf("Koniec programu.\n");

    return 0;
}
