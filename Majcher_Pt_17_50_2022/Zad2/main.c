#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Prawidłowe wywołanie %s liczba\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t child;
    int status;
    if ((child = fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child == 0) {
        sleep(2);
        exit(EXIT_SUCCESS);
    } else {
        sleep((atoi(argv[1])));
        if (waitpid(child, &status, WNOHANG) == 0) {
            printf("Proces %d zakończony przez sygnał", child);
            kill(child, SIGKILL);
        } else {
            printf("Proces %d zakończony przez exit", child);
        }

/* Proces macierzysty usypia na liczbę sekund będącą argumentem programu
 * Proces macierzysty pobiera status  zakończenia potomka child, nie zawieszając swojej pracy. 
 	* Jeśli proces się nie zakończył, wysyła do dziecka sygnał zakończenia. Wypisuje (Proces xx zakończony przez sygnał).
 * Jeśli się powiodło, wypisuje komunikat sukcesu zakończenia procesu potomka 
 * z numerem jego PID i sposobem zakończenia (Proces xx zakończony przez exit). */










    } //else
    return 0;
}
