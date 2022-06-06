/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:18:20 by jboo              #+#    #+#             */
/*   Updated: 2022/06/06 12:18:26 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_unsigned(unsigned int target, int *result, int flag)
{
	char	c;

	if (!target)
	{
		if (!flag)
		{
			write(1, "0", 1);
			(*result)++;
		}
		return ;
	}
	print_unsigned(target / 10, result, 1);
	c = target % 10 + '0';
	write(1, &c, 1);
	(*result)++;
}
