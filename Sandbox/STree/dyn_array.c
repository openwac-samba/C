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

int push_array (array** a, void* elem, int (*insert) (void**, void*))
{
    if (!(*a))
        *a= init ();
    return insert ((*a)->a[(*a)->pos], elem);
}