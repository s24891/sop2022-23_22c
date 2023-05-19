#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        // Błąd podczas tworzenia procesu potomnego
        perror("Błąd fork");
        return 1;
    } else if (pid == 0) {
        // Proces potomny
        printf("Proces potomny - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Proces rodzica
        printf("Proces rodzica - PID: %d, PPID: %d\n", getpid(), getppid());
        
        // Oczekiwanie na zakończenie procesu potomka
        wait(NULL);
    }
    
    return 0;
}
