#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void createChildProcess(int level) {
    pid_t pid = fork();

    if (pid < 0) {
        // Błąd podczas tworzenia procesu potomnego
        perror("Błąd fork");
        exit(1);
    } else if (pid == 0) {
        // Proces potomny
        printf("Potomek %d (PID: %d, PPID: %d)\n", level, getpid(), getppid());
        createChildProcess(level + 1);
        exit(0);
    } else {
        // Proces rodzica
        wait(NULL);
    }
}

int main() {
    printf("Główny proces (PID: %d, PPID: %d)\n", getpid(), getppid());
    createChildProcess(1);

    return 0;
}
