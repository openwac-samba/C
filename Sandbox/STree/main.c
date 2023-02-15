#include "dyn_array.c" 
#include <stdio.h>

int main ()
{
    int* n= malloc (sizeof (int));
    *n= 10;
    array* a= NULL;
    push_d_array (&a, &n);
    printf ("%i", *(int*) get_d_index (a, 0));
    free_d_array (a);
    return 0;
}