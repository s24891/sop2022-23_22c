#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createProcess(char name, int depth) {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Błąd w funkcji fork()\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Proces potomny
        printf("Proces %c (PID: %d, PPID: %d)\n", name, getpid(), getppid());

        if (depth > 0) {
            // Tworzenie kolejnych procesów potomnych
            createProcess(name + 1, depth - 1);
        }

        exit(EXIT_SUCCESS);
    } else {
        // Proces rodzica
        wait(NULL);
    }
}

int main() {
    printf("Proces A (PID: %d, PPID: %d)\n", getpid(), getppid());

    createProcess('B', 1);
    createProcess('C', 1);

    return 0;
}
