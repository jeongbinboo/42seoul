/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_deci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:16:19 by jboo              #+#    #+#             */
/*   Updated: 2022/06/06 12:16:20 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_deci(int target, int *result)
{
	char	*target_string;

	target_string = _itoa(target);
	write(1, target_string, _strlen(target_string));
	(*result) += _strlen(target_string);
	free(target_string);
	target_string = NULL;
}
