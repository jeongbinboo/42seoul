/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:17:44 by jboo              #+#    #+#             */
/*   Updated: 2022/06/06 12:17:45 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_hex(unsigned int target, int mode, int *result, int flag)
{
	if (!target)
	{
		if (!flag)
		{
			write(1, "0", 1);
			(*result)++;
		}
		return ;
	}
	print_hex(target / 16, mode, result, 1);
	if (mode)
		write(1, &HEX_BASE_UPPER[target % 16], 1);
	else
		write(1, &HEX_BASE_LOWER[target % 16], 1);
	(*result)++;
}
