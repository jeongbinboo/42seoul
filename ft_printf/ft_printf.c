#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *, ...);

int	ft_printf(const char *str, ...)
{
	printf("%p\n",str);
	va_list ap;
	printf("%p",ap);
	va_start(ap,str);
	printf("%d",va_arg(ap,int));

	return 0;
}

int main()
{
	ft_printf("hello",1,2,3);
	return 0;
}
