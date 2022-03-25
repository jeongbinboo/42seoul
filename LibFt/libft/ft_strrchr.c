/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:10:15 by jboo              #+#    #+#             */
/*   Updated: 2022/03/25 21:10:19 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (*string != 0)
	{
		string++;
		i++;
	}
	while (i >= 0)
	{
		if (*string == c)
		{
			return ((char *)string);
		}
		i--;
		string--;
	}
	return (0);
}
