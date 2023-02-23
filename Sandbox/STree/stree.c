#include <stdlib.h>
#define SIZE 3

typedef struct elem
{
    void* key;
    void* content;
}elem;

typedef struct tree
{
    int elem;
    int size;
    elem* array;
}tree;

//Functions

static tree* init ()
{
    tree* t= malloc (sizeof (tree));
    t->elem= 0;
    t->size= SIZE;
    t->array= calloc (SIZE, sizeof (elem));
    return t;
}

//API

/**
 * @brief Push an element into a tree
 * 
 * @param t adress to a pointer of tree
 * @param key key for comparisons
 * @param content adress to be refered byt the tree
 * @param compare function to compare elements using the key parameter
 */
void push (tree** t, void* key, void* content, int (*compare) (void*, void*))
{
    if (!*t)
        *t= init ();
    //insert and compare
}