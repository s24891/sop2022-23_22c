#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void childProcess(int value) {
    printf("Proces potomny: Liczby nieparzyste od 1 do %d\n", value);
    for (int i = 1; i <= value; i += 2) {
        printf("%d ", i);
        fflush(stdout);
    }
    printf("\n");
}

void parentProcess(int value) {
    int sum = 0;
    for (int i = 0; i <= value; i++) {
        sum += i;
    }
    printf("Proces rodzica: Suma liczb od 0 do %d = %d\n", value, sum);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Podaj wartość jako argument wykonania programu.\n");
        return 1;
    }

    int value = atoi(argv[1]);
    pid_t pid = fork();

    if (pid < 0) {
        // Błąd podczas tworzenia procesu potomnego
        perror("Błąd fork");
        return 1;
    } else if (pid == 0) {
        // Proces potomny
        childProcess(value);
    } else {
        // Proces rodzica
        parentProcess(value);
        wait(NULL);
    }

    return 0;
}
