/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:32:14 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 13:32:16 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_error(char *base)
{
	int	len;
	int	used[256];

	len = 0;
	while (len < 256)
		used[len++] = 0;
	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '-' || base[len] == '+'
			|| (9 <= base[len] && base[len] <= 13))
			return (1);
		if (used[(int)base[len]] >= 1)
			return (1);
		used[(int)base[len]]++;
		len++;
	}
	if (len <= 1)
		return (1);
	else
		return (0);
}

int	char2int_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-999);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	info[4];

	info[0] = 0;
	while (base[info[0]])
		info[0]++;
	index = 0;
	info[2] = 1;
	info[3] = 0;
	if (is_error(base) == 1)
		return (0);
	while (str[index] == ' ' || (9 <= str[index] && str[index] <= 13))
		index++;
	while (str[index] == '+' || str[index] == '-')
		if (str[index++] == '-')
			info[2] *= -1;
	while (1)
	{
		info[1] = char2int_base(str[index++], base);
		if (info[1] == -999)
			return (info[3]);
		info[3] *= info[0];
		info[3] += info[2] * info[1];
	}
	return (info[3]);
}
