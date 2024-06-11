#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	i = size - 1;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
