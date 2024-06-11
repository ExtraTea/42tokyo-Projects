#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t			*d;
	const uint8_t	*s;
	size_t			i;

	d = dest;
	s = src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dest);
}

/* #include <stdio.h>
int main(void){
	char a[] = "This is 42 Tokyo, Welcome";
	printf("%s\n", (char *)ft_memmove(a, a + 5, 7));
} */