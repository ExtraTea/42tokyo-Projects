#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	result = (unsigned char *)malloc(nmemb * size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_bzero((void *)result, nmemb * size);
	return ((void *)result);
}
