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
	char	*tmp;
	int		len;
	
	len = ft_strlen((char *)string);
	tmp = (char *)string + len;
	while (tmp >= string)
	{
		if (*tmp == c)
			return (tmp);
		tmp--;
	}
	return (0);
}
