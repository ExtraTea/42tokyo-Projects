/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:54:51 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 19:54:52 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *c)
{
	int	index;

	index = 0;
	while (c[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		index;

	len = 0;
	while (src[len] != 0)
		len++;
	dest = (char *) malloc((len + 1) * sizeof (char));
	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*result;

	result = (t_stock_str *)malloc((ac + 1) * sizeof (t_stock_str));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		result[index].size = ft_strlen(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		index++;
	}
	result[index].str = 0;
	return (result);
}
