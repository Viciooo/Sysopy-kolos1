#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  if (argc!=2) {
     printf("Prawidłowe wywołanie %s liczba\n",argv[0]); 
     exit(EXIT_FAILURE);
  }
  pid_t child;
  if((child = fork()) < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if(child == 0) {
    sleep(2);
    exit(EXIT_SUCCESS);
  }
  else {
// Proces macierzysty usypia na liczbę sekund będącą argumentem programu
// Proces macierzysty pobiera status  zakończenia potomka child, nie zawieszając swojej pracy.
      sleep(atoi(argv[1]));
      if(waitpid(child, NULL, WNOHANG) != 0) // don't wait!
          printf("Proces %d zakończony przez exit\n", child);

// Jeśli proces się nie zakończył, wysyła do dziecka sygnał zakończenia. Wypisuje (Proces xx zakończony przez sygnał).

    if (kill(child, SIGKILL) == 0)
        printf("Proces %d zakończony przez sygnał\n", child);
// * Jeśli się powiodło, wypisuje komunikat sukcesu zakończenia procesu potomka
// * z numerem jego PID i sposobem zakończenia (Proces xx zakończony przez exit).

 } //else
  return 0;
}
