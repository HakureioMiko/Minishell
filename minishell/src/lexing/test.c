
#include "lexer.h"

void *ft_malloc(size_t size)
{
    static int count = 0;

    count++;
    if (count == 5) // fait échouer le 5e malloc
    {
        return NULL;
    }

    return malloc(size);
}