#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, pid;
//    pid = getpid();  // można użyć też tego pid jako ppid dla forkowanych procesów ale chciałem uzyć getppid()
    printf("%d\n", pid);
    if (argc != 2) {
        printf("Not a suitable number of program arguments");
        exit(2);
    } else {
        for (i = 0; i < atoi(argv[1]); i++) {
            if (fork() == 0) {
                printf("%d my papa is %d and is child number %d \n", getpid(), getppid(),i+1);
                exit(1);
            }
            //*********************************************************
            //Uzupelnij petle w taki sposob aby stworzyc dokladnie argv[1] procesow potomnych, bedacych dziecmi
            //   tego samego procesu macierzystego.
            // Kazdy proces potomny powinien:
            // - "powiedziec ktorym jest dzieckiem",
            //-  jaki ma pid,
            //- kto jest jego rodzicem
            //******************************************************

        }
    }
    while(wait(NULL) > 0);

    return 0;
}
