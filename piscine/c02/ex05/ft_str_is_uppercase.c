/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:08:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/09 23:08:53 by dtakamat         ###   ########.fr       */
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

int	ft_str_is_uppercase(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len == 0)
		return (1);
	i = 0;
	while (i < len)
	{
		if (str[i] < 'A' || 'Z' < str[i])
			return (0);
		i++;
	}
	return (1);
}
