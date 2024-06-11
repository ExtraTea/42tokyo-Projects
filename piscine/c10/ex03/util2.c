/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:59:00 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:59:01 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

void	hex_counter_noc(long int count)
{
	const char	lib[] = "0123456789abcdef";
	char		digits[8];
	int			index;

	digits[7] = '\0';
	index = 6;
	while (index >= 0)
	{
		digits[index--] = lib[count & 0xf];
		count = count >> 4;
	}
	write (1, digits, 7);
}

void	put_16_hexes_noc(int count, char *buf)
{
	int	index;

	index = 0;
	while (index < count)
	{
		put_hex(buf[index]);
		if (index != count - 1)
			write(1, " ", 1);
		index++;
	}
	while (index < 16)
	{
		write(1, "  ", 2);
		if (index != count - 1)
			write(1, " ", 1);
		index++;
	}
}
