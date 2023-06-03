#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
 __pid_t pid ;
 pid = fork();  
    
    if (pid < 0) {
       printf("error while calling fork function\n");
        return 1;
    } else if (pid == 0) {
       
        printf("child process: PID=%d, PPID=%d\n", getpid(), getppid());
    } else {
        printf("Parent process: PID=%d, PPID=%d\n", getpid(), getppid());
        wait(NULL);  
    }
    
    return 0;
}
