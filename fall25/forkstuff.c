#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int cpid = fork();
  srand(time(NULL)+cpid);
  if (cpid == 0)
  {
/*    for (int i=0; i<50; i++)
    {
      printf("--%d\n", rand()%100);
    }*/
    char * args[] = {"ls", "-alh", NULL};
    execvp("ls", args);
/*    printf("%d nap time!\n", cpid);
    sleep(10);
    printf("I'm awake\n");*/
  }
  else
  {
    for (int i=0; i<50; i++)
      printf("++%d\n", rand()%100);
    /*printf("%d yaaawwwwn\n", cpid);
    sleep(12);
    printf("Stupid alarm\n");*/
  }
  return 0;
}
