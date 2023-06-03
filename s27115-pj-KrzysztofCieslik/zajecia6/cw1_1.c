
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum)
{
    printf("%d\n",signum);
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
        _exit(0);
    }
}
int main (){
 __pid_t pid;
 pid = getpid();
signal(SIGUSR1,signal_handler);
 printf("%d\n",pid);
    while (1)
    {
        pause();
            }
    return 0;
}