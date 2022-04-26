#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void sig_handler(int sig, siginfo_t *siginfo, void *ucontext) {
    printf("Received signal %d from %d with additional value: %d\n",
           sig, siginfo->si_pid, siginfo->si_value.sival_int);
}

int main(int argc, char* argv[]) {

    if(argc != 3){
        printf("Not a suitable number of program parameters\n");
        return 1;
    }

    struct sigaction action;
    action.sa_sigaction = &sig_handler;

    //..........


    int child = fork();
    if(child == 0) {
        //zablokuj wszystkie sygnaly za wyjatkiem SIGUSR1
        //zdefiniuj obsluge SIGUSR1 w taki sposob zeby proces potomny wydrukowal
        //na konsole przekazana przez rodzica wraz z sygnalem SIGUSR1 wartosc
        sigset_t mask;
        sigfillset(&mask); // zapełnianie maski
        sigdelset(&mask, SIGUSR1); //wywalamy z maski blockowanych SIGUSR1

        action.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &action, NULL);
        sleep(2);
    }
    else {
        //wyslij do procesu potomnego sygnal przekazany jako argv[2]
        //wraz z wartoscia przekazana jako argv[1]

        // kolejność argumentów w make'u sugeruje odwrotną kolejnośc sygnału i jego wartości

        sleep(1);
        sigqueue(child, atoi(argv[2]), (union sigval) atoi(argv[1]));
    }

    return 0;
}
