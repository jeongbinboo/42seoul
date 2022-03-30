#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int cnt;

    cnt = 0;
    if (!lst)
        return (0);
    while (lst->next)
    {
        cnt++;
        lst = lst->next;
    }
    return cnt + 1;
}