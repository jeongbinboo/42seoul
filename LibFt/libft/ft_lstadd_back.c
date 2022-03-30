#include "libft.h"
void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (!lst || !new)
        return ;
    new->next = 0;
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    tmp = *lst;
    while (1)
    {
        if(!tmp->next)
        {
            tmp->next = new;
            break ;
        }
        tmp = tmp->next;
    }
}