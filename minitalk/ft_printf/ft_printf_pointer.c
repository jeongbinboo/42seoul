/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:17:13 by jboo              #+#    #+#             */
/*   Updated: 2022/06/06 12:17:13 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	p_ptr(unsigned long long target, int *result, int flag)
{
	if (!target)
	{
		write(1, "0x", 2);
		if (!flag)
		{
			write(1, "0", 1);
			(*result)++;
		}
		(*result) += 2;
		return ;
	}
	p_ptr(target / 16, result, 1);
	write(1, &HEX_BASE_LOWER[target % 16], 1);
	(*result)++;
}
