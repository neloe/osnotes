#include <stdlib.h>
#include <stdio.h>

//function pointer syntax
// return_type (*ptr_name)(param_list)
void do_a_thing(void (*the_thing)());
void a();
void b() {printf("I'm in b!\n");}
int main()
{
    void* huh = malloc(4*sizeof(int*));
    ((int*)huh)[1] = 5;
    printf("%d\n", ((int*)huh)[1]);
    ((int*)huh)[0] = 5;
    printf("%ld\n", ((long*)huh)[0]);
    do_a_thing(a);
    do_a_thing(b);
    return 0;
}

void a()
{
    printf("I'm in a!\n");
}

void do_a_thing(void (*the_thing)())
{
    the_thing();
}
