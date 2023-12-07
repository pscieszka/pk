#include <stdio.h>
#include "operacje.h"
#include <sys/types.h>
#include <unistd.h>

int main()
{
   key_t klucz;
   int semID;
   int N=4;

   if ( (klucz = ftok(".", 'A')) == -1 )
   {
      printf("Blad ftok (A)\n");
      exit(2);
   }

   semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);  //dostep do semaforow z mainprog

   waitSemafor(semID,0,0);
   sleep(1);
   printf("A1\n");
   sleep(1);
   printf("A2\n");
   waitSemafor(semID,2,0);
   sleep(1);
   printf("A3\n");
   signalSemafor(semID,3);


}
#include <stdio.h>
#include "operacje.h"
#include <sys/types.h>
#include <unistd.h>

int main()
{
   key_t klucz;
   int semID;
   int N=4;

   if ( (klucz = ftok(".", 'B')) == -1 )
   {
      printf("Blad ftok (B)\n");
      exit(2);
   }

   semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);

sleep(1);
printf("B1\n");
sleep(1);
signalSemafor(semID, 0);
waitSemafor(semID, 1, 0);
printf("B2\n");
sleep(1);
waitSemafor(semID, 3, 0);
printf("B3\n");



}


#include <stdio.h>
#include "operacje.h"
#include <sys/types.h>
#include <unistd.h>

int main()
{
   key_t klucz;
   int semID;
   int N=4;

   if ( (klucz = ftok(".", 'C')) == -1 )
   {
      printf("Blad ftok (C)\n");
      exit(2);
   }

   semID = alokujSemafor(klucz, N, IPC_CREAT | 0666);
sleep(1);
printf("C1\n");
sleep(1);
printf("C2\n");
sleep(1);
signalSemafor(semID, 1);
printf("c3\n");

signalSemafor(semID, 2);


}
