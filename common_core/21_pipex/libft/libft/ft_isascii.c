#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || 255 < c)
		return (0);
	if (((unsigned char)c <= 127))
		return (1);
	else
		return (0);
}
