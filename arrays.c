#include <stdio.h>
#include <stdlib.h>

int main()
{
	int my_array[4];
	my_array[0] = 5;
	my_array[1] = -1;

	//printf("%d %d\n", my_array[0], my_array[2]);
	
	int * dyn_arr;
	dyn_arr = (int *)malloc(5 * sizeof(int));
	/*for (int i=0; i<5; i++)
		printf("%d\n", dyn_arr[i]);*/
	free(dyn_arr);
	dyn_arr = NULL; // safety sanity check
	dyn_arr = (int *)calloc(10, sizeof(int));

	int ** pptr = &dyn_arr;

	printf("dyn: %p, pptr: %p, *pptr: %p, &dyn: %p)\n", dyn_arr, pptr, *pptr, &dyn_arr);
	dyn_arr = realloc(dyn_arr, 20 * sizeof(int));
	printf("dyn: %p, pptr: %p, *pptr: %p, &dyn: %p)\n", dyn_arr, pptr, *pptr, &dyn_arr);

	free(dyn_arr);
	
	return 0;
}
