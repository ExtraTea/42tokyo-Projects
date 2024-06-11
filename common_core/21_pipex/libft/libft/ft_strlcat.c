#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	if (dst == NULL)
		dstlen = 0;
	else
		dstlen = ft_strlen(dst);
	if (src == NULL)
		srclen = 0;
	else
		srclen = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (dstlen + srclen);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	i = dstlen;
	j = 0;
	while (src[j] != 0 && i < dstsize - 1)
	{
		dst[i++] = src[j++];
	}
	dst[i] = 0;
	return (dstlen + srclen);
}
