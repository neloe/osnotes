#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  char * cmd [] = {"ls", "-alh", NULL};
  puts(argv[0]);
  execvp("ls", cmd);
  puts("Hello world");
  return 0;
}
