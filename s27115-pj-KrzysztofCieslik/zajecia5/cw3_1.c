#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void sumNumbersFromZeroToN(int n) {
    int i;
    int sum;
    sum = 0;
    for(i = 0; i < n+1; i++) {
       sum = sum + i;
    }
    printf("%d\n", sum);
}

void printOddNumbersInTheRangeFrom1toN(int n) {
    int i;
    for(i = 1; i < n; i = i + 2) {
         printf("%d\n", i);
    }
}

int main() {
    __pid_t pid;
    int arg;
    scanf("%d", &arg);
    pid = fork();
    
    if (pid < 0) {
        printf("Error while calling fork function\n");
        return 1;
    } else if (pid == 0) {
        printOddNumbersInTheRangeFrom1toN(arg);
    } else {
        wait(NULL);
        sumNumbersFromZeroToN(arg);
    }
    
    return 0;
}
