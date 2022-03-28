/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:29:38 by jboo              #+#    #+#             */
/*   Updated: 2022/03/28 17:29:40 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!len || !n[0])
		return ((char *)h);
	while (h[i] && i < len)
	{
		if (h[i] == n[0])
		{
			j = 0;
			while (h[i + j] == n[j] && (i + j) < len)
			{
				j++;
				if (n[j] == '\0')
					return ((char *)&(h[i]));
			}
		}
		i++;
	}
	return (0);
}
