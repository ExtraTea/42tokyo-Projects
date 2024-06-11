/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:05:18 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 12:05:26 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n -1)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	find_len;
	int	str_len;

	str_len = 0;
	while (str[str_len] != 0)
		str_len++;
	find_len = 0;
	while (to_find[find_len] != 0)
		find_len++;
	if (find_len == 0)
		return (str);
	index = 0;
	while (index < (str_len - find_len + 1))
	{
		if (str[index] == to_find[0])
		{
			if (ft_strncmp (&str[index], to_find, find_len) == 0)
				return (&str[index]);
		}
		index++;
	}
	return (0);
}
