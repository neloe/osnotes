#include <stdlib.h>

void a();
void b();
void c();
void d();

int main()
{
    a();
}

void a()
{
    b();
}
void b()
{
    c();
}
void c()
{
    int i1=5, i2=6;
    d();
}
void d()
{
    int * arr = malloc(5* sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    int * x = NULL;
    //*x = 5;
    free(arr);
    free(arr);
}
