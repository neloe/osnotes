#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char mesg [12] = "Hello world!";
    char c = 'a';
    char * mesg2 = malloc(12);
    char mesg3[3] = "cat";
    strcpy(mesg3, mesg);
    /*
    char * c = mesg3;
    int i = 0;
    while (!c)
    {
        mesg[i] = *c;
        c+=1;
        i+=1;
    }
    */
    //strcpy(mesg2, mesg);
    printf("%s, %ld, %ld\n", mesg, strlen(mesg),sizeof(mesg));
    return 0;
}
