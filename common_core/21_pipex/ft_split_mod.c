#include "pipex.h"

size_t	fft_count_elements(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[0] != c)
		count ++;
	while (s[i + 1] != 0)
	{
		if (s[i] == c && s[i + 1] != c)
			count ++;
		i++;
	}
	return (count);
}

char	*fft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof (char) * (n + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char **ferror_s_null(void)
{
	char	**result;

	result = (char **)malloc(sizeof (char *) * (1));
	if (result == NULL)
		return (NULL);
	*result = NULL;
	return (result);
}

char	**ft_split_mod(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	k;
	char	del = c;

	if (s == NULL)
		return (ferror_s_null());
	result = (char **)malloc(sizeof (char *) * (fft_count_elements(s, del) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	k = 0;
	while (s[++i] != 0)
	{
		if (s[i] == del)
			continue ;
		if (s[i] == '\'' || s[i] == '\"')
			del = s[i++];
		j = 0;
		while (s[i + j] != del && s[i + j] != 0)
			j++;
		result[k++] = fft_strndup(s + i, j);
		i += j - 1;
		if (del != c)
			del = c;
	}
	result[k] = NULL;
	return (result);
}
