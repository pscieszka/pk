#include "operacje.h"

int alokujSemafor(key_t klucz, int number, int flagi)
{
   int semID;
   if ( (semID = semget(klucz, number, flagi)) == -1)
   {
      perror("Blad semget (alokujSemafor): ");
      exit(1);
   }
   return semID;
}

int zwolnijSemafor(int semID, int number)
{
   return semctl(semID, number, IPC_RMID, NULL);
}

void inicjalizujSemafor(int semID, int number, int val)
{
   
   if ( semctl(semID, number, SETVAL, val) == -1 )
   {
      perror("Blad semctl (inicjalizujSemafor): ");
      exit(1);
   }
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
      //perror("Blad semop (waitSemafor)");
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

int valueSemafor(int semID, int number)
{
   return semctl(semID, number, GETVAL, NULL);
}

/*
double getRand(int *nseed)
{
   double number;

   srand( *nseed );
   number = (double)rand();
   *nseed = (int)number;
   number /= (RAND_MAX+1.0);

   return number;
}

*/
