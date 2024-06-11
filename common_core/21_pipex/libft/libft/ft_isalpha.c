#include "libft.h"

int	ft_isalpha(int c)
{
	if (c < 0 || 255 < c)
		return (0);
	if (('a' <= (unsigned char)c && (unsigned char)c <= 'z')
		|| ('A' <= (unsigned char)c && (unsigned char)c <= 'Z'))
		return (1);
	else
		return (0);
}
