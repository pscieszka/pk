#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>


int *widelce;

#define P 5 // liczba procesow filozofow
#define N 6 // rozmiar tablicy pamieci dzielonej

int shmID, semID; // id pamieci dzielonej i semafora
void clean() {
    // Czyszczenie pamięci dzielonej i semaforów
    shmctl(shmID, IPC_RMID, NULL);
    semctl(semID, 0, IPC_RMID, NULL);
    printf("MAIN: Koniec (czyszczenie).\n");
    exit(0);
}
int main(){
    key_t kluczPamiec, kluczSemafor;
    printf("Kliknij ctrl+c aby zakonczyc.\n");
    signal(SIGINT, clean);
    kluczPamiec=ftok(".",'A');
    shmID=shmget(kluczPamiec, N*sizeof(int), IPC_CREAT|IPC_EXCL|0666);
    if (shmID==-1){
        printf("Blad pamięci dzielonej.\n"); exit(1);
    }
    widelce = (int *)shmat(shmID, NULL, 0);

    kluczSemafor = ftok(".", 'B');
    semID = semget(kluczSemafor, 5, IPC_CREAT | IPC_EXCL | 0666);
    if (semID == -1) {
        printf("Blad tworzenia tablicy semaforow.\n");
        exit(1);
    }

    for (int i = 0; i < P; ++i) {
        widelce[i] = 0;
    }

    for (int i = 0; i < P; ++i) {
        if (semctl(semID, i, SETVAL, 1) == -1) {
            printf("Bład inicjacji semafora %d\n", i);
            exit(1);
        }
    }
    char name[2];

    for (int i = 0; i < P; i++){
        switch (fork()){
            case 1:
                perror("Blad fork (main)");
                exit(1);
            case 0:
                
                sprintf(name, "%d", i);
                execl("./filozof","filozof",name, NULL);
        }
    }
    while(1){
    printf("Stan widelcow: [");
    for (int i = 0; i < P; ++i) {
        printf("%d,", widelce[i]);
    }
    printf("]\n");
        sleep(1);
    }
    for(int i=0;i<2*P;i++){
        wait(NULL);
    }

}

