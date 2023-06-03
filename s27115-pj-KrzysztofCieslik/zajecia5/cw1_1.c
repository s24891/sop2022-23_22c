#include <unistd.h>
#include <stdio.h>
int main (){
    __pid_t pid;
    __pid_t ppid;
    int endChar;
    pid = getpid();
    ppid = getppid();
    printf("pid : %d\n", pid);
    printf("ppid: %d\n" ,ppid);
    endChar = getchar();
    printf ("%d\n",endChar);
    return 0;
}
