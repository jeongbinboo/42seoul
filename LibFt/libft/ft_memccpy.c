
#include "libft.h"

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    if (!dst && !n)
        return ((void *)0);
    while (!*(unsigned char *)src || n)
    {
        *(unsigned *)dst = *(unsigned *)src;
        if (*(unsigned char *)src == (unsigned char)c)
            return (++dst);
        ++dst;
        ++src;
        --n;
    }
    return (0);
}
