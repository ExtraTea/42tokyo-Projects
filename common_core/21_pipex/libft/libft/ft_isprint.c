#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 0 || 255 < c)
		return (0);
	if ((32 <= (unsigned char)c && (unsigned char)c <= 126))
		return (1);
	else
		return (0);
}
