#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//function pointer syntax: return_type (*var_name)(param_list)
void do_a_thing( void (*the_thing)()  );
void a() {printf("I'm in a!\n");}
void b() {printf("I'm in b!\n");}

int main()
{
    void * ptr = malloc(4*sizeof(int));
    //((int*)ptr)[0] = 5;
    //((int*)ptr)[1] = 5;
    ((long*)ptr)[0] = (long)INT_MAX+1;
    printf("%d\n", ((int*)ptr)[0]);
    printf("%ld\n", ((long*)ptr)[0]);
    do_a_thing(a);
    do_a_thing(b);

    return 0;
}
void do_a_thing( void (*the_thing)()  )
{
    the_thing();
}
