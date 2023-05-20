#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid;
    int status;

    printf("Proces główny (PID: %d)\n", getpid());

    // Tworzenie 100 procesów potomnych
    for (int i = 1; i <= 100; i++) {
        childPid = fork();

        if (childPid < 0) {
            // Błąd podczas tworzenia procesu potomnego
            perror("Błąd fork");
            exit(1);
        } else if (childPid == 0) {
            // Proces potomny
            printf("Proces potomny %d (PID: %d, PPID: %d)\n", i, getpid(), getppid());
            exit(0);
        }
    }

    // Proces główny czeka na zakończenie wszystkich procesów potomnych
    while ((childPid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Proces potomny o PID %d zakończony (status: %d)\n", childPid, WEXITSTATUS(status));
        } else {
            printf("Proces potomny o PID %d zakończony\n", childPid);
        }
    }

    return 0;
}
