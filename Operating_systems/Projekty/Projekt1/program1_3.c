#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    printf("Rodzic\n");

    int pid2 = getpid(); //zapisujemy pid rodzica
    int pid;
    printf("Potomkowie:\n");
    for (int i = 0; i < 3; i++) {
        pid = fork();
        // pid == 0 -> potomek
        // pid > 0  -> rodzic
        // pid == -1 -> blad

        if (pid == 0) {
            int err = execl("./print", "printID", NULL);
            if (err == -1) {
                perror("Blad podczas operacji ececl");
            }
        } else if (pid == -1) {
            perror("Blad podczas operacji fork()\n");
        }

        //Powstana 3 procesy potomne, poniewaz
        //funkcja execl zastepuje biezacy proces
        //nowym procesem
    }
    //1+3 procesow

    if (getpid() == pid2) { //wywolujemy pstree tylko w procesie rodzica
        char cmd[32];
        sprintf(cmd, "pstree -p  %d", pid2); // -p wyswietl numery PID
        system(cmd);
    }
    for (int i = 0; i < 3; i++) {
        int status;
        int id = wait( & status);
        if (status != 0) {
            perror("Proces potomoka zakonczyl sie z bledem");
        } else {
            printf("Zakonczono proces %d ze statusem %d\n", id, status);
        }
    }

    sleep(1); // Poczekaj 1 sekunde, aby ostatnia linia kodu nie nachodzila na kolejne polecnia
}