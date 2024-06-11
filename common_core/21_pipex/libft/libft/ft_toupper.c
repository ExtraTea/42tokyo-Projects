#include "libft.h"

int	ft_toupper(int c)
{
	if (c < 0 || 255 < c)
		return (c);
	if (('a' <= (unsigned char)c && (unsigned char)c <= 'z'))
		return (c - 'a' + 'A');
	else
		return (c);
}
