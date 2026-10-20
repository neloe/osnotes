#include <stdio.h>
#include <signal.h>

void signal_handler(int signum);

int main()
{
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);
  while(1);
}

void signal_handler(int signum)
{
  printf("AH AH AH, YOU DIDN'T SAY THE MAGIC WORD\n");
}
