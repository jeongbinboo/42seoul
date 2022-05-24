#include "ft_printf.h"

int	chklen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	fillarr(char **tmp, int n, int flag, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		if (i == 0 && flag)
		{
			(*tmp)[i] = '-';
			break ;
		}
		if (i == (len - 1))
		{
			(*tmp)[i] = '\0';
			i--;
			continue ;
		}
		(*tmp)[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
}

char	*minvalue(void)
{
	char	*tmp;
	int		i;
	int		min;

	i = 9;
	min = 214748364;
	tmp = (char *)malloc(sizeof(char) * 12);
	if (!tmp)
		return (0);
	tmp[0] = '-';
	tmp[11] = '\0';
	tmp[10] = '8';
	while (i)
	{
		tmp[i] = min % 10 + '0';
		i--;
		min /= 10;
	}
	return (tmp);
}

char	*_itoa(int n)
{
	int		len;
	int		flag;
	char	*tmp;

	flag = 0;
	if (n == -2147483648)
		return (minvalue());
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	len = chklen(n);
	tmp = (char *)malloc(sizeof(char) * (len + 1 + flag));
	if (!tmp)
		return (0);
	fillarr(&tmp, n, flag, len + 1 + flag);
	return (tmp);
}
