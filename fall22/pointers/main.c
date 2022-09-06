#include <stdio.h>
#include <stdlib.h>
void swap(int * a, int * b);

int main()
{
    int num;
    int *addr;
    num = 5;
    printf("%lu\n", sizeof(num));
    printf("%lu\n", sizeof(addr));
    addr = &num;
    printf("Addr of num: %p, addr: %p\n", &num, addr);
    printf("Address of addr: %p\n", &addr);
    printf("Value at address %p: %d\n", addr, *addr);
    *addr = 10;
    printf("Values; num = %d, *addr = %d\n", num, *addr);
    int num2 = 42;
    printf("%d, %d\n", num, num2);
    swap(&num, &num2);
    printf("%d, %d\n", num, num2);
    // C style arrays
    int nums[5];
    int *dyn_arr=NULL;
    printf("%p\n", dyn_arr);
    //printf("%d\n", *dyn_arr);
    dyn_arr=malloc(20 * sizeof(int));
    dyn_arr[0] = 10;
    printf("%d\n", dyn_arr[0]);
    free(dyn_arr);
    // &dyn_arr[0] == dyn_arr
    return 0;
}

void swap (int * a, int * b)
{
    /* temp = a
    a = b;
    b = temp
    */
    int temp = *a;
    *a = *b;
    *b = temp;
}
