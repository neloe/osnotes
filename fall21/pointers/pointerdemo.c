#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b);

int main()
{
    int x = 5;
    int y = -1;
    int * ptr = &x;
    int arr [5] = {3,1,4,15};
    int huh;
    //printf("%d, %x, %d, %x\n", x, &x, *ptr, ptr);
    x = 6;
    //printf("%d, %x, %d, %x\n", x, &x, *ptr, ptr);
    *ptr = 10;
    //printf("%d, %x, %d, %x\n", x, &x, *ptr, ptr);
    printf("%d, %d\n", x, y);
    swap (&x, &y);
    printf("%d, %d\n", x, y);
    for (int i=0; i<5; i++)
	printf("%d ", arr[i]);
    printf("\n");
    printf("%d\n", huh);
    for (int i=0; i<=5; i++)
	arr[i]=i;
    for (int i=0; i<5; i++)
	printf("%d ", arr[i]);
    printf("\n");
    printf("%d\n", huh);
    printf("%x, %x\n", arr, &huh);

    // -- "dynamic" arrays
    
    int * int_dynarray = NULL;
    int_dynarray = (int *) malloc (10 * sizeof(int));
    int_dynarray[0] = 5;
    int * itr = int_dynarray;
    for (int i=0; i<10; i++)
    {
	*itr = 2 * i;
	itr ++;
    }
    for (int i=0; i<10; i++)
	printf("%d ", int_dynarray[i]);
    printf("\n");

    free(int_dynarray);
    int_dynarray = NULL;
    free(int_dynarray);
    return 0;
}

void swap (int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
