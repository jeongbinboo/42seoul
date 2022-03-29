#include "libft.h"
void    *ft_calloc(size_t count, size_t size)
{
    void    *tmp;
    
    tmp = malloc(count * size);
    if (!tmp)
        return (0);
    ft_bzero(tmp, count * size);
    return (tmp);
}
