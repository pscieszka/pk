#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "operacje.h"
#include <sys/wait.h>

#define P 3    								// ilosc procesow

int main()
{
   key_t klucz;
   int semID;
   int N = 4;  								// ilosc semaforow potrzebnych do wykonania
   char *procesy[P] = {"A", "B", "C"}; 					// definicja procesow
   char sciezka[5];
   int i;

   if ( (klucz = ftok(".", 'A')) == -1 )				// funkcja do generowania kluczy do semaforow, 'A' jest to znak ktory jednoznacznie identyfikuje projekt
   {
      printf("Blad ftok (main)\n");
      exit(1);
   }


   semID = alokujSemafor(klucz, N, IPC_CREAT | IPC_EXCL | 0666);	// tworzymy 4 semafory poprzez semget zdefiniowane w operacje.c
   for (i = 0; i < N; i++)
      inicjalizujSemafor(semID, i, 0); 					// poprzez semctl z operacje.c uzupelniamy semafory zerami

   printf("Semafory gotowe!\n");
   fflush(stdout);

   for (i = 0; i < P; i++)
      switch (fork())							// robi sie fork
      {
         case -1:
            perror("Blad fork (mainprog)");				// blad jesli nie zrobi forka
            zwolnijSemafor(semID, N);
            exit(2);
         case 0:
            sciezka[0] = '\0';
            strcat(sciezka, "./");					// laczenie ./ do wyslania z zawartoscia sciezki
            strcat(sciezka, procesy[i]);
            execl(sciezka, procesy[i], NULL);				// wywolanie procesow
      }

   for (i = 0; i < P; i++)
      wait( (int *)NULL );

   zwolnijSemafor(semID, N);
   printf("MAIN: Koniec.\n");
}
