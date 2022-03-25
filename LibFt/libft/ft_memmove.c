/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:10 by jboo              #+#    #+#             */
/*   Updated: 2022/03/24 21:49:12 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ifDstIsBig(unsigned char *tmp, const void *src, size_t len)
{
	tmp += (len - 1);
	src += (len - 1);
	while (len --)
	{
		*tmp = *(unsigned char *)src;
		tmp--;
		src--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	if (dst == src)
	{
		return (dst);
	}
	tmp = (unsigned char *)dst;
	if (dst > src)
	{
		ifDstIsBig(tmp, src, len);
	}
	else
	{
		while (len--)
		{
			*tmp = *(unsigned char *)src;
			tmp++;
			src++;
		}
	}
	return (dst);
}
