#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define LOWER 0
# define UPPER 1

int		ft_printf(const char *str, ...);
int		check_format(const char format, va_list ap, int *result);
int		_strlen(char *str);
char	*_itoa(int n);
void	print_char(char target, int *result);
void	print_str(char *target, int *result);
void	print_deci(int target, int *result);
void	p_ptr(unsigned long long target, int *result, int flag);
void	print_hex(unsigned int target, int mode, int *result, int flag);
void	print_unsigned(unsigned int target, int *result, int flag);
#endif
