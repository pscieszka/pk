
#include <stdio.h>
#include "operacje.h"
#include <sys/types.h>
#include <unistd.h>

int main()
{
   key_t klucz;
   int semID;
   int N = 4;
   pid_t pid;

   if ( (klucz = ftok(".", 'A')) == -1 )
   {
      printf("Blad ftok (B)\n");
      exit(2);
   }


 semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);

   pid=getpid();

   sleep(1);
   printf("B1, PID:%d\n",pid);
   signalSemafor(semID, 0);

   waitSemafor(semID, 1, 0);
   sleep(1);
   printf("B2, PID:%d\n",pid);

   waitSemafor(semID, 3, 0);
   sleep(1);
   printf("B3, PID:%d\n",pid);
   signalSemafor(semID, 2);
}
