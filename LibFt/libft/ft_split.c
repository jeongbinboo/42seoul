#include "libft.h"
int checkLen(char *str, char c)
{
    int cnt;
    int flag;
    int i;

    cnt = 0;
    flag = 0;
    i = 0;
    while (str[i] == c && str[i])
        i++;
    while (str[i])
    {
        if (str[i] == c)
            flag = 1;
        else if(flag)
        {
            cnt++;
            flag = 0;
        }
        i++;
    }
    return cnt;
}
void    setArr(char *tmp, char **str, char c, int len)
{
    int i;

    i = 0;
    while (**str == c)
        (*str)++;
    while (i < len - 1)
    {
        tmp[i] = **str;
        i++;
        (*str)++;
    }
    tmp[i] = '\0';
}
int resetArr(char **tmp, int i){
    while (i >= 0)
    {
        free(tmp[i]);
        i--;
    }
    return 0;
}
int makeArr1(char **tmp, char *str, char c, int len)
{
    int i;
    int end;

    i = 0;
    while (i < len)
    {
        end = 0;
        while (*str == c)
            str++;
        while (*(str + end) != c)
            end++;
        tmp[i] = (char *)malloc(sizeof(char) * (end + 1));
        if(!tmp[i])
            return (resetArr(tmp, i));
        setArr(tmp[i], &str, c, end + 1);
        i++;
    }
    return 1;
}
char **ft_split(char const *s, char c)
{
    int     len;
    int     i;
    char    **tmp;

    if (!s || !c)
        return (0);
    i = 0;
    len = checkLen((char *)s, c);
    tmp = (char **)malloc(sizeof(char *)*(len + 1));
    if (!tmp)
        return (0);
    if (!makeArr1(tmp, (char *)s, c, (len + 1)))
    {
        free(tmp);
        return (0);
    }
    return tmp;
}