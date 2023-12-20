#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
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
#define MAX2 32
#define MAX 30
#define PELNY 2
#define PUSTY 1
#define zapis pam[MAX + 1]
#define odczyt pam[MAX]

int main()
{
    key_t klucz, kluczm, kluczs;
    int msgID, shmID, semID;
    int i;
    struct bufor komunikat;
    sleep(1);
    printf("konsument--------------------------------\n");
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
    };

    kluczm = ftok(".", 'B');
    kluczs = ftok(".", 'C');
    semID = semget(kluczs, 1, IPC_CREAT | 0666);
    if (semID == -1)
    {
        perror("Blad semget");
        exit(1);
    }

    shmID = shmget(kluczm, MAX2 * sizeof(int), IPC_CREAT | 0666);
    pam = (int *)shmat(shmID, NULL, 0);


    if (msgrcv(msgID, &komunikat, sizeof(komunikat.mvalue), PELNY, 0) == -1) {
        perror("Blad odbioru komunikatu PUSTY");
        exit(1);
        }
    //odbior komunikatu pelnego
    sleep(getpid() % 10);

    //blokowanie dostepu do zasobow
    waitSemafor(semID, 0, 0);

    //odczytanie wartosci z pamieci wspoldzielonej
    int od = pam[odczyt];
    //aktualizacja indeksu odczytu
    odczyt = (odczyt+1) % MAX;


    // Wypisanie informacji na ekranie
    printf("Konsument o PID %d odebral wartosc %d od producenta\n", getpid(), od);

    //wysylanie komunikatu pustego
    komunikat.mtype = PUSTY;
    komunikat.mvalue = MAX;

   if (msgsnd(msgID, &komunikat, sizeof(komunikat.mvalue), 0) == -1)
    {
        perror("Blad wyslania komunikatu PELNY");
        exit(1);
    }
    //odblokowanie dostepu do zasobow
    signalSemafor(semID, 0);
    return 0;
}
