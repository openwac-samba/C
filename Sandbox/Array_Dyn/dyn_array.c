#include "dyn_array.h"
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
    d->a= malloc (SIZE* sizeof (void*));
    return d;
}

/**
 * @brief push an element 'elem' by adress to the d_array
 * 
 * @param a 
 * @param elem 
 * @return 0 for success
 */
int push_d_array (array** a, void* elem)
{
    array* d_arr= *a;
    if (!d_arr)
        d_arr= init ();
    d_arr->a[d_arr->pos]= elem;
    d_arr->pos++;
    *a= d_arr;
    return 0; 
}

/**
 * @brief Get element of index n
 * 
 * @param a 
 * @param n 
 * @return return NULL for failure and adress of element in success
 */
void* get_d_index (array* a, int n)
{
    if (n>= a->pos)
        return NULL;
    return a->a[n];
}

/**
 * @brief Get #1 element that matches
 * 
 * @param a array
 * @param elem elem to compare with
 * @param compare returns 0 for a match
 * @return return NULL for no matches and adress of object for match
 */
void* get_d_comp (array* a, void* elem, int (*compare) (void*, void*))
{
    for (int i= 0; i< a->pos; i++)
    {
        if (!compare (a->a[i], elem))
            return a->a[i]; 
    }
    return NULL;
}

/**
 * @brief Frees the d_array struct including the adresses passed by arg in 'push' calls
 * 
 * @param a 
 */
void free_d_array (array* a)
{
    for (int i= 0; i< a->pos; i++)
        free (a->a[i]);
    free (a->a);
    free (a);
}