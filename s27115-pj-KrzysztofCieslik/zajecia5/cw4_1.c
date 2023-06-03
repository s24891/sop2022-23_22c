#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void createProcesses(int count) {
    if (count > 0) {
        __pid_t pid = fork();
        
        if (pid < 0) {
            printf("Błąd podczas wywołania funkcji fork()\n");
            return;
        } else if (pid == 0) {
            
            printf("Proces potomny: PID=%d, PPID=%d  %d\n" , getpid(), getppid(),count);
            createProcesses(count - 1);
        } else {
        
            wait(NULL);
        }
    }
}

int main() {
    printf("Proces rodzica: PID=%d, PPID=%d\n", getpid(), getppid());
    createProcesses(99);
    

    return 0;
}