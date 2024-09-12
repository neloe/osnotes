#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=5;
    int * arr = malloc(4*sizeof(int));
    arr[0] = 5;
    arr[1] = 10;
    //arr[258] = 15;
    int stack_arr [50];
    for (int i=0; i<100000; i++)
        stack_arr[i] = i;
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", x);
    free(arr);
    return 0;
}
