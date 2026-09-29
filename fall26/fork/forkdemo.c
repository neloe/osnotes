#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
  int cpid = fork();
  srand(getpid());
  //puts("Hello world!");
 /* printf("Hello world, my cpid is:%d, "
         "my pid is: %d, my parent is:%d\n", 
	 cpid, getpid(), getppid());*/
  printf("Rando number: %d\n", rand()%100);
}
