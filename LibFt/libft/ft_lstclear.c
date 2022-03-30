#include "libft.h"
void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *next;

    if (!lst || !(*lst))
	    return ;
    while (*lst)
    {
        next = (*lst)->next;
        (*del)((*lst)->content);
        free(*lst);
        *lst = 0;
        if (next)
            *lst = next;
    }
}
