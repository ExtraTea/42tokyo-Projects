#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < 0 || 255 < c)
		return (0);
	if (('a' <= (unsigned char)c && (unsigned char)c <= 'z')
		|| ('A' <= (unsigned char)c && (unsigned char)c <= 'Z')
		|| ('0' <= (unsigned char)c && (unsigned char)c <= '9'))
		return (1);
	else
		return (0);
}
