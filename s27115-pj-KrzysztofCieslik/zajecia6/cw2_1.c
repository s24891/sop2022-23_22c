#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

extern int kill(int pid, int sig);

void signal_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Wykryto próbę uruchomienia drugiej istaancji programu!\n");
        signal(SIGUSR1,signal_handler);
    }

    if(signum == 2){
              printf("Przechwycono sygnał SIGINT. Usuwanie pliku i zakończenie działania programu.\n");
        if (remove("/tmp/lock") == 0)
        {
            printf("Plik /tmp/lock został usunięty.\n");
        }
        else
        {
            printf("Nie można usunąć pliku /tmp/lock.\n");
        }
        exit(0);
    }
}

int tmpFileCreate() {
    FILE *fp;
    printf("Tworzę plik /tmp/lock\n");
    fp = fopen("/tmp/lock", "w");
    if (fp == NULL) {
        printf("Nie można utworzyć pliku /tmp/lock\n");
        return 0;
    }
    fclose(fp);
    return 1;
}

int tmpFileExist() {
    FILE *fp;
    fp = fopen("/tmp/lock", "r");
    if (fp == NULL) {
        printf("Plik /tmp/lock nie istnieje\n");
        return 1;
    } else {
        printf("Plik /tmp/lock istnieje\n");
        fclose(fp);
        return 0;
    }
    
}
int readPidFromTmpFile()
{
    char str[10];
    int pid = -1;
    FILE *fp = fopen("/tmp/lock", "r");
    if (fp != NULL)
    {
        if (fgets(str, sizeof(str), fp) != NULL)
        {
            pid = atoi(str);
        }
        fclose(fp);
    }
    return pid;
}


void writePidToTmpFile() {
      FILE *fp;
    
  
    printf("Zapisuję PID do pliku\n");
    fp = fopen("/tmp/lock", "w");
    if (fp == NULL) {
        printf("Nie można otworzyć pliku /tmp/lock\n");
        return;
    }
    fprintf(fp, "%d", getpid());
    fclose(fp);
}

int main() {
    signal(SIGUSR1,signal_handler);
   
    if (tmpFileExist() == 1) {
        if (tmpFileCreate() == 1) {
            writePidToTmpFile();
            while (1)
            {    signal(2,signal_handler);
                sleep(1);
            }
            
        }
    }
    else{ 
            kill(readPidFromTmpFile(),10);
    }
    return 0;
}
