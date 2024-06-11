#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	i = 0;
	while (i < size)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
