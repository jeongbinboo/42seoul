/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:47:12 by jboo              #+#    #+#             */
/*   Updated: 2022/03/18 14:57:14 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	chk_sign(char *str)
{
	int	cnt;
	int	i;
	int	flag;

	cnt = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				cnt++;
			flag = 1;
		}
		else
		{
			if (flag == 1)
				break ;
		}
		i++;
	}
	return (cnt);
}

int	check_char(char str, int *flag, long *result)
{
	if (str == 32 || (str >= 9 && str <= 13))
	{
		if (*flag > 0)
			return (0);
		*flag = 0;
	}
	else if (str == '+' || str == '-')
	{
		if (*flag > 1)
			return (0);
		*flag = 1;
	}
	else if (str >= '0' && str <= '9')
	{
		*result = *result * 10 + (str - '0');
		*flag = 2;
	}
	else
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long	result;
	int		i;
	int		flag;

	i = 0;
	result = 0;
	flag = 0;
	while (str[i])
	{
		if (!check_char(str[i], &flag, &result))
			break ;
		i++;
	}
	if (chk_sign(str) % 2 != 0)
		return (result * -1);
	return (result);
}
