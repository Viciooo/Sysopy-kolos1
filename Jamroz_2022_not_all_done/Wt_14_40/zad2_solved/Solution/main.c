#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


void licz(int x){
  printf("dla x=%d wynik x2 to %d\n",x , x*x); fflush(stdout);
  return;
}

int main (int lpar, char *tab[]){
/* 1) wywolaj funkcje 'licz' dla parametrow od 1 do 20. Kazde wywolanie tej
   funkcji ma byc w innym procesie potomnym
   2) proces macierzysty ma wyswietlic pid wszystkich procesow potomnych i
   czekac na zakonczenie ich wszystkich*/

    for (int i = 1; i <= 20; ++i) {
        if (fork() == 0){
            printf("\nMy pid %d my papa pid %d\n",getpid(),getppid());
            licz(i);
            exit(1);
        }
    }

    while(wait(NULL) > 0);

  return 0;
}
