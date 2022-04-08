/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:20:08 by jboo              #+#    #+#             */
/*   Updated: 2022/04/01 21:20:09 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (i < ft_strlen((char *)s1))
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = s1[i];
	return (tmp);
}
