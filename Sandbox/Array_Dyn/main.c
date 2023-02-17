#include "dyn_array.h" 
#include <stdio.h>
#include <stdlib.h>

int compare_int (void* p1, void* p2)
{
    return (*(int*)p1- *(int*)p2);
}

int main ()
{
    int* n= malloc (sizeof (int));
    *n= 10;
    int* k= malloc (sizeof (int));
    *k= 23;
    D_Array a= NULL;
    push_d_array (&a, n);
    push_d_array (&a, k);
    printf ("%i\n", *(int*) get_d_comp (a, n, compare_int));
    free_d_array (a);
    return 0;
}