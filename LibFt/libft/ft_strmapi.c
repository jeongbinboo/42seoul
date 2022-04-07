/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:23:05 by jboo              #+#    #+#             */
/*   Updated: 2022/04/01 21:23:06 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	tmp[len] = '\0';
	--len;
	while (len >= 0)
	{
		tmp[len] = f((unsigned int)len, s[len]);
		len--;
	}
	return (tmp);
}
