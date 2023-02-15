#include <stdbool.h>

bool is_prime(int num)
{
    for (int i= num, i> 0, i--)
    {
        if (num% i== 0)
            return false;
    }
    return true;
}