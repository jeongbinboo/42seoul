#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *tmp;
    size_t  i;

    i = 0;
    tmp = (char *)malloc(sizeof(char) * (len + 1));
    if(!tmp || !s)
        return (0);
    if(start >= (unsigned int)ft_strlen((char *)s))
        return (ft_strdup(""));
    while (s[start] && len)
    {
        tmp[i] = s[start];
        i++;
        start++;
        len--;
    }
    tmp[i] = '\0';
    return (tmp);
}