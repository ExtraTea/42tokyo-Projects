/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcapitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:05:31 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/10 16:29:13 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_special(char c)
{
	if ('a' <= c && c <= 'z')
		return (0);
	else if ('0' <= c && c <= '9')
		return (0);
	else if ('A' <= c && c <= 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] += 'A' - 'a';
	while (str[i] != '\0')
	{
		if (is_special(str[i]))
		{
			if ('a' <= str[i + 1] && str[i + 1] <= 'z')
				str[i + 1] += 'A' - 'a';
		}
		else
		{
			if ('A' <= str[i + 1] && str[i + 1] <= 'Z')
				str[i + 1] += 'a' - 'A';
		}
		i++;
	}
	return (str);
}
