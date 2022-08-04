#include "get_next_line.h"

char    *make_return(char **back_up)
{
    char    *ret;

    ret = (char *)malloc(sizeof(char) * (chk_nl(*back_up) + 2));
    if(!ret)
        return NULL;
    ft_strlcpy(ret, *back_up, chk_nl(*back_up) + 2);
    clean_back_up(back_up, chk_nl(*back_up));
    return ret;
}

void    clean_back_up(char **back_up, int nl_index)
{
    size_t  new_string_length;
    char    *new_string;

    new_string_length = ft_strlen(*back_up) - nl_index - 1;
    if(new_string_length == 0)
    {
        free(*back_up);
        *back_up = NULL;
        return ;
    }
    new_string = (char *)malloc(sizeof(char) * new_string_length + 1);
    if(!new_string)
        return ;
    ft_strlcpy(new_string, (*back_up) + nl_index + 1, new_string_length + 1);
    free(*back_up);
    *back_up = new_string;
}

int     chk_nl(char *back_up)
{
    int i;

    i = 0;
    while (*(back_up + i))
    {
        if (*(back_up + i) == '\n')
            return i;
        i++;
    }
    return -1;
}

char    *join_and_check(char **back_up, char *buffer_read)
{
    char    *tmp;

    if (!*back_up)
        *back_up = ft_strjoin("", buffer_read);
    else
    {
        tmp = ft_strjoin(*back_up, buffer_read);
        free(*back_up);
        *back_up = tmp;
    }
    if(chk_nl(*back_up) != -1)
    {
        return (make_return(back_up));
    }
    else
        return NULL;
}

char	*get_next_line(int fd)
{
    static char *back_up;
    char        buffer_read[BUFFER_SIZE + 1];
    char        *ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    while(1)
    {
        reset_buffer(buffer_read);
        if(read(fd, buffer_read, BUFFER_SIZE) <= 0){
            if(back_up){
                if(chk_nl(back_up) != -1)
                    return (make_return(&back_up));
                else
                    ret = back_up;
                    back_up = NULL;
                    return ret;
            }
            else
                return (NULL);
        }
        ret = join_and_check(&back_up, buffer_read);
        if(ret)
            return ret;
    }
}