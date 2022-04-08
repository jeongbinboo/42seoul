/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:24:08 by jboo              #+#    #+#             */
/*   Updated: 2022/04/01 21:24:10 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*tmp;

	if (!s1 || !set)
		return (0);
	left = 0;
	right = ft_strlen((char *)s1) - 1;
	while (s1[left] && ft_strchr(set, s1[left]))
		++left;
	while (s1[right] && ft_strchr(set, s1[right]) && right > left)
		--right;
	tmp = (char *)malloc(sizeof(char) * (right - left + 2));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, &((char *)s1)[left], right - left + 2);
	return (tmp);
}
