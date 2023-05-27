#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    int i;
    int exit_status ;
    int signal_number ;
    printf("Parent process: PID=%d\n", getpid());

    for (i = 0; i < 100; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Error calling fork() function\n");
            return 1;
        } else if (pid == 0) {
            printf("Child process %d: PID=%d, PPID=%d\n", i + 1, getpid(), getppid());
            return 0;
        }
    }
    /*proces oczekuje na znak aby łatwiej było użyć pstree*/
    getchar(); 

    for (i = 0; i < 100; i++) {
        __pid_t terminated_pid;
        terminated_pid = wait(&status);



        if (terminated_pid == -1) {
            printf("Error calling wait() function\n");
            return 1;
        }
        /* zdecydowalem sie na dodanie sprawdznia w jaki sposób został zakończony proces potomny
        dzięki użyciu WIFEXIED(status) wraz z WEXITSTATUS oraz WTERMSIG z połaczeniem z funkcją wait(&stats) która oczekuje na zakończenie
        procesu i zwraca jego pid możemy nie tylko zdeterminować co stało się z procesem ale również dowiedzieć się i wyspisać jaki pid miał
        zakończony proces
        
        w przypadu pierwszego if znajdujacego się pod tym komentarzem sprawdzamy czy WIFEXITED(status) jest prawdą.
        Funkcja ta może zwróćić dwa rodzaje wartości liczbę całkowitą różną od zera (prawda w przypadku if w C/C++) lub zero (fałsz)
        w zależności od jak zakończył się program w przypadku zwykłego return zwróci on liczbę całkowitą
        w przypadku gdy proces zakończył się w inny sposób np. poprzez użycie sygnału funkcja zwróci zero.

        Sprawdzamy co zwraca WIFEXITED(status) zanim wywołamy WEXITSTATUS który zwróci nam kod returna procesu.
        Robimy tak z oczywistego powodu;wywołanie go przed sprawdzeniem WIFEXITED(status) może zwrócić nieprzewidywalną bez sensowną wartość.

        jeśli wartunek ten nie jest spełniony ale spełniony jest WIFSIGNALED(status) powtarzamy całą procedurę dokładnie tak samo ale dzięki
        temu możemy uzyskać kod sygnału którym proces został unicestwiony.

        ważnym elementem do działania tej konstrukcji jest   terminated_pid = wait(&status); który oczekuje na zakończenie procesu potomnego
        i zwraca jego pid jednocześnie zapisuje poprzez użycie adresu zmiennej status do niej informacje o statusie zakończenia programu dzięki 
        czemu możemy je później użyć przy pomocy wyżej wymienionych funkcji.

        terminated_pid jest też używany do stwierdznia czy udało się poprawnie wywołać funkcję wait
        */
        if (WIFEXITED(status)) {
            
            exit_status = WEXITSTATUS(status);
            printf("Child process with PID=%d exited with exit code %d\n", terminated_pid, exit_status);
        } else if (WIFSIGNALED(status)) {
            
            signal_number= WTERMSIG(status);
            printf("Child process with PID=%d terminated by signal %d\n", terminated_pid, signal_number);
        }
    }

    return 0;
}