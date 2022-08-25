/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboo <jboo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:10:26 by jboo              #+#    #+#             */
/*   Updated: 2022/05/24 20:00:21 by jboo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_format(const char format, va_list ap, int *result)
{
	if (format == 'c')
		print_char((char)va_arg(ap, int), result);
	else if (format == 's')
		print_str((char *)va_arg(ap, char *), result);
	else if (format == 'd' || format == 'i')
		print_deci((int)va_arg(ap, int), result);
	else if (format == 'p')
		p_ptr((unsigned long long)va_arg(ap, unsigned long long), result, 0);
	else if (format == 'u')
		print_unsigned((unsigned int)va_arg(ap, unsigned int), result, 0);
	else if (format == 'x')
		print_hex((unsigned int)va_arg(ap, unsigned int), LOWER, result, 0);
	else if (format == 'X')
		print_hex((unsigned int)va_arg(ap, unsigned int), UPPER, result, 0);
	else if (format == '%')
	{
		write(1, "%", 1);
		(*result)++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			check_format(*(++str), ap, &result);
		else
		{
			write(1, str, 1);
			result++;
		}
		str++;
	}
	return (result);
}
