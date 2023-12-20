#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sem.h>

int waitSemafor(int semID, int number, int flags)
{
    struct sembuf operacje[1];
    operacje[0].sem_num = number;
    operacje[0].sem_op = -1;
    operacje[0].sem_flg = 0 | flags;

    if (semop(semID, operacje, 1) == -1)
    {
        perror("Blad semop (waitSemafor)");
        return -1;
    }

    return 1;
}

void signalSemafor(int semID, int number)
{
    struct sembuf operacje[1];
    operacje[0].sem_num = number;
    operacje[0].sem_op = 1;

    if (semop(semID, operacje, 1) == -1)
        perror("Blad semop (postSemafor): ");

    return;
}

struct bufor
{
    int mtype;
    int mvalue;
};

int *pam;

#define MAX 30
#define MAX2 32
#define PELNY 2
#define PUSTY 1
#define odczyt pam[MAX]
#define zapis pam[MAX + 1]

int main()
{
    key_t klucz, kluczm, kluczs;
    int msgID, shmID, semID;
    int i;
    struct bufor komunikat;
    sleep(1);
    printf("producent--------------------------------\n");
    if ((klucz = ftok(".", 'A')) == -1)
    {
        printf("Blad ftok (A)\n");
        exit(2);
    };
    msgID = msgget(klucz, IPC_CREAT | 0666);
    if (msgID == -1)
    {
        printf("blad klejki komunikatow\n");
        exit(1);
    }
    kluczm = ftok(".", 'B');
    kluczs = ftok(".", 'C');
    shmID = shmget(kluczm, MAX2 * sizeof(int), IPC_CREAT | 0666);
    pam = (int *)shmat(shmID, NULL, 0);

    semID = semget(kluczs, 1, IPC_CREAT | 0666);
    if (semID == -1)
    {
        perror("Blad semget");
        exit(1);
    }

    semctl(semID, 0, SETVAL, 1);


    if (msgrcv(msgID, &komunikat, sizeof(komunikat.mvalue), PUSTY, 0) == -1)
    {
    }
    //odbior  komunikatu pustego
    sleep(getpid() % 10);

    waitSemafor(semID, 0, 0);
    //blokuje dostep innym procesom do zasbow

    int prodPid = getpid();

     pam[zapis] = prodPid;
    //zapisuje pid do pamieci wspoldzielonej
    printf("Producent o PID %d wyslal wartosc %d\n", getpid(), prodPid);

    //aktualizacja indeksu zapisu
    zapis = (zapis+1) % MAX;
    //wysylanie komunikatu pelnego
    komunikat.mtype = PELNY;
    komunikat.mvalue = 0;

   if (msgsnd(msgID, &komunikat, sizeof(komunikat.mvalue), 0) == -1)
    {
        perror("Blad wyslania komunikatu PELNY");
        exit(1);
    }
    //odblokowanie dostepu do zasobow
    signalSemafor(semID, 0);

    return 0;
}
