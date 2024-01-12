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

int* widelce;
int semID;

#define P 5 
#define N 6

void signalSemafor(int semID, int number);
int waitSemafor(int semID, int number, int flags);

int main(int argc, char* argv[]){

    key_t kluczPamiec, kluczSemafor;
    int name = atoi(argv[1]);

    kluczPamiec = ftok(".", 'A');
    int shmID = shmget(kluczPamiec, N * sizeof(int), IPC_CREAT | 0666);
    if (shmID == -1) {
        perror("Blad pamieci dzielonej...");
        exit(1);
    }

    widelce = (int *)shmat(shmID, NULL, 0);

    kluczSemafor = ftok(".", 'B');
    semID = semget(kluczSemafor, P, IPC_CREAT | 0666);
    if (semID == -1) {
        perror("Blad semafora");
        exit(1);
    }
    srand(time(NULL));
    if(name==4){
        while (1) {
        // Filozof myśli

        //printf("Filozof %d myśli\n", name);

        // Filozof chce podnieść widelec po swojej stronie

        waitSemafor(semID, 0, 0);
        waitSemafor(semID, 4, 0);

        // Filozof je
        widelce[0] = 5;
        widelce[4] = 5;

       
        //printf("Filozof %d je\n", name);
        sleep(1);

        widelce[0] = 0;
        widelce[4] = 0;

        // Filozof odkłada widelec
        signalSemafor(semID, 4);
        signalSemafor(semID, 0);

        // Filozof zaczyna myśleć ponownie
        sleep(rand() % 5);
    }
    }
    else{
        while (1) {
        // Filozof myśli

        //printf("Filozof %d myśli\n", name);

        // Filozof chce podnieść widelec po swojej stronie


        waitSemafor(semID, name, 0);
        waitSemafor(semID, (name+1)%P, 0);

        // Filozof je
        widelce[name] = name+1;
        widelce[(name+1)%P] = name+1;

       
        //printf("Filozof %d je\n", name);
        sleep(1);

        widelce[name] = 0;
        widelce[(name+1)%P] = 0;

        // Filozof odkłada widelec
        signalSemafor(semID, name);
        signalSemafor(semID, (name+1)%P);

        // Filozof zaczyna myśleć ponownie
        sleep(rand() % 5);
    }
    }

     

    shmdt(widelce);
    printf("Filozof: Koniec\n");
    return 0;
}


int waitSemafor(int semID, int number, int flags)
{
   int result;
   struct sembuf operacje[1];
   operacje[0].sem_num = number;
   operacje[0].sem_op = -1;
   operacje[0].sem_flg = 0 | flags;//SEM_UNDO;

   if ( semop(semID, operacje, 1) == -1 )
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
   //operacje[0].sem_flg = SEM_UNDO;

   if (semop(semID, operacje, 1) == -1 )
      perror("Blad semop (postSemafor): ");

   return;
}
