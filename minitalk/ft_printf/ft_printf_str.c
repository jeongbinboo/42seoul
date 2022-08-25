/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:15:45 by jboo              #+#    #+#             */
/*   Updated: 2022/06/06 12:15:46 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_str(char *target, int *result)
{
	if (!target)
	{
		write(1, "(null)", 6);
		(*result) += 6;
		return ;
	}
	write(1, target, _strlen(target));
	(*result) += _strlen(target);
}
