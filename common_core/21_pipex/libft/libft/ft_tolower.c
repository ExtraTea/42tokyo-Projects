#include "libft.h"

int	ft_tolower(int c)
{
	if (c < 0 || 255 < c)
		return (c);
	else if (('A' <= (unsigned char)c && (unsigned char)c <= 'Z'))
		return (c - 'A' + 'a');
	else
		return (c);
}
