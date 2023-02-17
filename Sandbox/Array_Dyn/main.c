#include "dyn_array.h" 
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* n= malloc (sizeof (int));
    *n= 10;
    int* k= malloc (sizeof (int));
    *k= 23;
    D_Array a= NULL;
    push_d_array (&a, n);
    push_d_array (&a, k);
    printf ("%i, %i\n", *(int*) get_d_index (a, 0), *(int*) get_d_index (a, 1));
    free_d_array (a);
    return 0;
}