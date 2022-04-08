/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:15:18 by jboo              #+#    #+#             */
/*   Updated: 2022/04/01 21:15:20 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checklen(char const *str, char c)
{
	int	cnt;
	int	flag;
	int	i;

	cnt = 0;
	flag = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		else if (flag)
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

void	setarr(char *tmp, char const **str, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		tmp[i] = **str;
		i++;
		(*str)++;
	}
	tmp[i] = '\0';
}

int	resetarr(char **tmp, int i)
{
	while (i >= 0)
	{
		free(tmp[i]);
		i--;
	}
	free(tmp);
	return (0);
}

int	makearr1(char **tmp, char const *str, char c, int len)
{
	int		i;
	int		end;

	i = 0;
	while (i < len)
	{
		end = 0;
		while (*str == c && *str)
			str++;
		while (*(str + end) != c && *(str + end))
			end++;
		if (!end)
		{
			tmp[i] = 0;
			return (1);
		}
		tmp[i] = (char *)malloc(sizeof(char) * (end + 1));
		if (!tmp[i])
			return (resetarr(tmp, i - 1));
		setarr(tmp[i], &str, end + 1);
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		i;
	char	**tmp;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	len = checklen(s, c);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (0);
	if (!makearr1(tmp, s, c, (len + 1)))
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}
