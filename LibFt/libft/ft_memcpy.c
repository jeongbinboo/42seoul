/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:25:33 by jboo              #+#    #+#             */
/*   Updated: 2022/03/24 21:47:13 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!src && !dst)
	{
		return (0);
	}
	tmp = (unsigned char *)dst;
	while (n--)
	{
		*tmp = *(unsigned char *)src;
		tmp++;
		src++;
	}
	return (dst);
}
