/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:36:13 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 14:02:21 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}

void	hex_print(char c)
{
	const char	h[17] = "0123456789abcdef\0";
	char		str[4];

	str[0] = '\\';
	str[1] = h[(c >> 4) & 0xf];
	str[2] = h[c & 0xf];
	str[3] = '\0';
	write(1, str, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int			index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_printable(str[index]))
			write(1, &str[index], 1);
		else
		{
			hex_print(str[index]);
		}
		index++;
	}
}
