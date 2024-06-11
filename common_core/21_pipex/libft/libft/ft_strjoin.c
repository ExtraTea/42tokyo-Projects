#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;

	size = 0;
	if (s1 != NULL)
		size += ft_strlen(s1);
	else
		size += 0;
	if (s2 != NULL)
		size += ft_strlen(s2);
	else
		size += 0;
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(result, s1, size + 1);
	else
		result[0] = 0;
	ft_strlcat(result, s2, size + 1);
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = NULL;
// 	char s2[] = "42 Tokyo";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }