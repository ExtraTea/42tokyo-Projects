#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < 0 || 255 < c)
		return (0);
	if ('0' <= (unsigned char)c && (unsigned char)c <= '9')
		return (1);
	else
		return (0);
}
