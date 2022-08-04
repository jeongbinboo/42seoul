#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (src[cnt] != 0)
	{
		cnt++;
	}
	if (size == 0)
	{
		return (cnt);
	}
	while (i < size - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, (char *)s1, s1_len + 1);
	ft_strlcpy(tmp + s1_len, (char *)s2, s2_len + 1);
	return (tmp);
}

void	reset_buffer(char *buffer_read)
{
	int	i;

	i = 0;
	while(i <= BUFFER_SIZE)
	{
		buffer_read[i] = 0;
		i++;
	}
}