#include <stdlib.h>
#define Max_Size 8

typedef struct interval
{
    void* min, * max;
}interval;

typedef struct obj
{
    void* key, * content;
}object; 

/**
 * @param array objects
 * @param i interval of keys kept in the array
 * @param pos number of objects kept in the array
 */
typedef struct frag
{
    object array [Max_Size];
    interval i;                                                                 
    int pos;                                                                    
}frag;

typedef struct frag_s
{
    frag* f;
    int pos;
    int size;
}frag_s;

/**
 * @brief Creates the frag_s
 * 
 * @return frag_s* 
 */
frag_s* init_frag_s ()
{
    frag_s* f= malloc (sizeof (frag_s));
    f->f= calloc (1, sizeof (frag));
    f->size= 1;
    f->pos= 0;
    return f;
}

int in_interval (interval i, void* key, int (*compare) (void*, void*))
{
    if (compare (i.min, key)< 0)                                                //Key lower than min
        return -1;
    if (compare (i.max, key)> 0)                                                //Key higher than max
        return 1;
    return 0;
}

void insert_frag ()
{
    return;
}

//API

/**
 * @brief Pushes the object into the returnde frag_s
 * 
 * @param f frag_s
 * @param key used by compare
 * @param content used by push
 * @param push user defined
 * @param compare user defined
 * @return frag_s* 
 */
frag_s* push_frag_s (frag_s* f, void* key, void* content, void (*push) (void*, void*), int (*compare) (void*, void*))
{
    int cmp;                                                                    //Compare function return
    if (!f)
        f= init_frag_s ();
    for (int i= 1; i> 0;)                                                       //FIXME
    {
        if (!(cmp= in_interval (f->f[i].i, key, compare)))                      //Found the frag in wich to insert
            insert_frag (f, i, key, content, push, compare);
        else
            if (cmp> 0)
                //Go Right
                return f;
            else
                //Go Left
                return NULL;
    }
    return f;
}