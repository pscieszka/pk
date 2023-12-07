
#include <stdio.h>
#include "operacje.h"
#include <sys/types.h>
#include <unistd.h>

int main()
{
   key_t klucz;
   int semID;
   int N =  4;
   pid_t pid;


   if ( (klucz = ftok(".", 'A')) == -1 )
   {
      printf("Blad ftok (C)\n");
      exit(2);
   }

   semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);

   pid = getpid();


   sleep(1);
   printf("C1, PID:%d\n",pid);
   sleep(1);
   printf("C2, PID:%d\n",pid);
   signalSemafor(semID, 1);

   sleep(1);
   printf("C3, PID:%d\n",pid);
   signalSemafor(semID,2);
}
