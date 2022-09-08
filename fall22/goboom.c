#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i = 0;
    int arr[5];
    while (1)
    {
        arr[i] = i;
        printf("%d,%d\n", arr[i],i);
        i++;
    }
    return 0;
}
