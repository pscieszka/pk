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
      printf("Blad ftok (A)\n");
      exit(2);
   }

   semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);

   pid=getpid();

   waitSemafor(semID,0,0);
   sleep(2);
   printf("A1, PID:%d\n",pid);
   sleep(2);
   printf("A2, PID:%d\n",pid);
   waitSemafor(semID,2,0);
   sleep(2);
   printf("A3, PID:%d\n",pid);
   signalSemafor(semID,3);

}


