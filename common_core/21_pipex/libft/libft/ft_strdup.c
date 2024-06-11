#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
