/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:49 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:50 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str[0] != '\0')
	{
		count = ft_strlen(&str[1]) + 1;
	}
	return (count);
}

void	hex_counter(long int count)
{
	const char	lib[] = "0123456789abcdef";
	char		digits[9];
	int			index;

	digits[8] = '\0';
	index = 7;
	while (index >= 0)
	{
		digits[index--] = lib[count & 0xf];
		count = count >> 4;
	}
	write (1, digits, 8);
}

void	put_hex(char c)
{
	const char	lib[] = "0123456789abcdef";

	c = (unsigned char)c;
	write(1, &lib[(c >> 4) & 0xf], 1);
	write(1, &lib[c & 0xf], 1);
}

void	put_16_hexes(int count, char *buf)
{
	int	index;

	index = 0;
	while (index < count)
	{
		put_hex(buf[index]);
		if (index != count - 1)
			write(1, " ", 1);
		if (index == 7)
			write(1, " ", 1);
		index++;
	}
	while (index < 16)
	{
		write(1, "  ", 2);
		if (index != count - 1)
			write(1, " ", 1);
		if (index == 7)
			write(1, " ", 1);
		index++;
	}
}

void	write_raw_ascii(int count, char *buf)
{
	int	index;

	write(1, "  |", 3);
	index = 0;
	while (index < count)
	{
		if (buf[index] < 32 || 126 < buf[index])
			write(1, ".", 1);
		else
			write(1, &buf[index], 1);
		index++;
	}
	write(1, "|", 1);
}
