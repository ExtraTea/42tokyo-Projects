#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	if (s == NULL)
		return (0);
	while (index < n)
		*((unsigned char *)s + index++) = (unsigned char)c;
	return (s);
}
