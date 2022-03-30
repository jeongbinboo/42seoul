#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *tmp;

    tmp = (t_list *)malloc(sizeof(t_list));
    if(!tmp)
        return (0);
    tmp->content = content;
    tmp->next = 0;
    return tmp;
}