#include <stdio.h>
#include <unistd.h>

int main() {

  printf("PID - Identyfikator procesu: %d\n", getpid());
  printf("PPID - Identyfikator procesu przodka: %d\n", getppid());
  printf("UID - Identyfikator uzytkownika: %d\n", getuid());
  printf("GID - Identyfikator grupy: %d\n", getgid());

  return 0;
}