#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
  int myvar;
  int * ptr = &myvar;
  printf("Before fork, myvar = %d, ptr = %x\n", myvar, ptr);
  int cpid = fork();
  printf("After fork %d, myvar = %d, ptr = %x\n", cpid, myvar, ptr);
  srand(getpid());
  myvar = rand() % 100;
  printf("Random value: %d, cpid: %d\n", myvar, cpid);

  if (cpid == 0) // child
  {
    * ptr = rand() % 1000;
    printf("Child new random value: %d\n", myvar);
  }
  else
  {
    sleep(1);
    printf("Parent random value: %d\n", myvar);
  }

  //puts("Hello world!");
 /* printf("Hello world, my cpid is:%d, "
         "my pid is: %d, my parent is:%d\n", 
	 cpid, getpid(), getppid());*/
  //printf("Rando number: %d\n", rand()%100);
}
