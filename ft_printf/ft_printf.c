#include "ft_libft.h"

void	print_char(va_list ap)
{
	char	target;

	target = va_arg(ap, int);
	write(1, &target, 1);
}

void	print_str(va_list ap)
{
	char	*target;
	target = va_arg(ap, char *);
	write(1, target, _strlen(target));
}

void	print_pointer(va_list ap)
{
	
}
int	check_format(const char format, va_list ap)
{
	if (format == 'c')
		print_char(ap);
	else if (format == 's')
		print_str(ap);
	/*else if (format == 'p')
		print_pointer(ap);
	else if (format == 'd')
		print_deci(ap);
	else if (format == 'i')
		print_int(ap);
	else if (format == 'u')
		print_unsigned(ap);
	else if (format == 'x')
		print_hex_lower(ap);
	else if (format == 'X')
		print_hex_upper(ap);*/
	else if (format == '%')
		write(1, "%", 1);
	else return 0;
	return 1;
}
int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			check_format(*(++str), ap);
		else
			write(1, str, 1);	
		str++;
	}
	return 0;
}

int main()
{
	ft_printf("hello %c %s",'e', "hello");
	return 0;
}
