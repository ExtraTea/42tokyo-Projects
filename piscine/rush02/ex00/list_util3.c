/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:51:04 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 22:51:06 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_error_value(char *entry)
{
	int	i;

	i = 0;
	while (entry[i] == ' ')
		i++;
	while (entry[i])
	{
		if (!(ft_is_printable(entry[i])))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
