#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void printID{
    printf("PID %d  ", getpid());
    printf("PPID %d  ", getppid());
    printf("UID %d  " , getuid());
    printf("GID %d\n" , getgid());
}

int main(){
printf("Rodzic\n");
printID();
int pid2=getpid(); //zapisujemy pid rodzica
int pid;
printf("Potomkowie:\n");
for(int i=0; i<3;i++){
        pid=fork();
        // pid == 0 -> potomek
        // pid > 0  -> rodzic
        // pid == -1 -> blad

        if(pid==0){
                printID();
                    
        }
        else if(pid==-1){
                printf("Blad podczas operacji fork()\n");
        }


        //i = 0 -> 2 procesy
        //i = 1 -> 4 procesy
        //i = 2 -> 8 procesow
}
//8 procesow

if(getpid()==pid2){//wywolujemy pstree tylko w procesie rodzica
char cmd[32];
sprintf(cmd,"pstree -p  %d",pid2);// -p wyswietl numery PID
system(cmd);
}


sleep(1); // Poczekaj 1 sekunde, aby ostatnia linia kodu nie nachodzila na kolejne polecnia
}
