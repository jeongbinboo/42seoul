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
#include <stdio.h>
#include "ft_printf.h"

void	print_char(char target, int *result)
{
	write(1, &target, 1);
	(*result)++;
}

void	print_str(char *target, int *result)
{
	write(1, target, _strlen(target));
	(*result) += _strlen(target);
}

void	print_deci(int target, int *result)
{
	char	*target_string;

	target_string = _itoa(target);
	while (*target_string)
	{
		write(1, target_string, 1);
		(*result)++;
		target_string++;
	}
}

void	print_pointer(unsigned long long target, int *result)
{
	char	pointer[14];
	char	*base;
	int		i;

	i = 13;
	pointer[0] = '0';
	pointer[1] = 'x';
	while (target || i > 1)
	{
		pointer[i] = HEX_BASE_LOWER[target % 16];
		target /= 16;
		i--;
	}
	write(1, pointer, 14);
	(*result) += 14;
}

void	print_hex(int target, int mode, int *result)
{
	if (!target)
		return ;
	print_hex(target / 16, mode, result);
	if (mode)
		write(1, &HEX_BASE_UPPER[target % 16], 1);
	else
		write(1, &HEX_BASE_LOWER[target % 16], 1);
	(*result)++;
}

void	print_unsigned(unsigned int target, int *result)
{
	char	c;

	if (!target)
		return;
	print_unsigned(target / 10, result);
	c = target % 10 + '0';
	write(1, &c, 1);
	(*result)++;
}

int	check_format(const char format, va_list ap, int *result)
{
	if (format == 'c')
		print_char((char)va_arg(ap, int), result);
	else if (format == 's')
		print_str((char *)va_arg(ap, char *), result);
	else if (format == 'd' || format == 'i')
		print_deci((int)va_arg(ap, int), result);
	else if (format == 'p')
		print_pointer((unsigned long long)va_arg(ap, unsigned long long), result);
	else if (format == 'u')
		print_unsigned((unsigned int)va_arg(ap, unsigned int), result);
	else if (format == 'x')
		print_hex((int)va_arg(ap, int), LOWER, result);
	else if (format == 'X')
		print_hex((int)va_arg(ap, int), UPPER, result);
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
	return (0);
}

int	main(void)
{
	int a;

	a = 4;
	printf("real = %d\n",printf("hello %c %s %i %u",'e', "hello", a, 2147483648));
	printf("mine = %d\n",ft_printf("hello %c %s %i %u",'e', "hello", a, 2147483648));
	return (0);
}
