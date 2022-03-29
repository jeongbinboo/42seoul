#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
    if (!tmp)
        return (0);
    while(i < ft_strlen((char *)s1))
    {
        tmp[i] = s1[i];
        i++;
    }
    tmp[i] = s1[i];
    return (tmp);
}