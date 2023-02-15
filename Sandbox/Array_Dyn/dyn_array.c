#include <stdlib.h>
#define SIZE 10

typedef struct dyn_array
{
    int pos;
    int size;
    void** a;
}array;

static array* init ()
{
    array* d= malloc (sizeof (array));
    d->pos= 0;
    d->size= SIZE;
    d->a= malloc (SIZE* sizeof (array));
    return d;
}

int push_d_array (array** a, void* elem)
{
    if (!(*a))
        *a= init ();
    (*a)->a[(*a)->pos]= elem;
    (*a)->pos+= 1;
    return 0; 
}

void* get_d_index (array* a, int n)
{
    return a->a[n];
}

void* get_d_comp (array* a, void* elem, int (*compare) (void*, void*))
{
    for (int i= 0; i< a->pos; i++)
    {
        if (!compare (a->a[i], elem))
            return a->a[i]; 
    }
    return NULL;
}

void free_d_array (array* a)
{
    for (int i= 0; i< a->pos; i++)
        free (a->a[a->pos]);
    free (a);
}