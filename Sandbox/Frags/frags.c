#include <stdlib.h>
#define N_Frags 10

typedef struct mm
{
    int min, max;
}min_max;

typedef struct obj
{
    void* key,* content;
}object; 

typedef struct
{
    object* frags;
    min_max* mm_a;
    int pos_frags;

}frags;