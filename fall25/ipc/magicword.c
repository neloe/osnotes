#include <signal.h>
#include <stdio.h>

void nedry(int sig);

int main()
{
  signal(SIGINT, nedry);
  signal(SIGTERM, nedry);
  while(1);
  return 0;
}

void nedry(int sig)
{
  printf("AH AH AH, YOU DIDN'T SAY THE MAGIC WORD!\n");
}
