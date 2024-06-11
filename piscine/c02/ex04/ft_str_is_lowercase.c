/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:11:26 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/10 12:11:33 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_is_lowercase(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len == 0)
		return (1);
	i = 0;
	while (i < len)
	{
		if (str[i] < 'a' || 'z' < str[i])
			return (0);
		i++;
	}
	return (1);
}
