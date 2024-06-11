/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:53:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:53:18 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	write_100s(int num, t_node *head, int *is_first)
{
	char	*digit;
	char	*numtemp;

	numtemp = ft_itoa(num / 100);
	digit = search(head, numtemp);
	free(numtemp);
	if (!*is_first)
		write(1, " ", 1);
	*is_first = 0;
	write(1, digit, ft_strlen(digit));
	digit = search(head, "100");
	write(1, " ", 1);
	write(1, digit, ft_strlen(digit));
}

void	write_digit(char *digit, t_node *head, int num, int *is_first)
{
	char	*numtemp;

	if (!*is_first)
		write(1, " ", 1);
	*is_first = 0;
	numtemp = ft_itoa(num);
	digit = search(head, numtemp);
	write(1, digit, ft_strlen(digit));
	free(numtemp);
}

void	write_3digits(int num, t_node *head, int is_first)
{
	char	*digit;

	digit = NULL;
	if (num == 0)
		return ;
	if (num / 100 > 0)
		write_100s(num, head, &is_first);
	num %= 100;
	if (num == 0)
		return ;
	if (num > 20)
	{
		write_digit(digit, head, num - num % 10, &is_first);
		if (num % 10 == 0)
			return ;
		write_digit(digit, head, num % 10, &is_first);
	}
	else
	{
		write_digit(digit, head, num, &is_first);
	}
}

void	write_rec(char *num, int len, t_node *head, int is_first)
{
	char	dest[4];
	char	powers[300];
	int		part_len;

	if (len % 3 == 0)
		part_len = 3;
	else
		part_len = len % 3;
	ft_strlcpy(dest, num, part_len + 1);
	write_3digits(ft_atoi(dest), head, is_first);
	len -= part_len;
	if (len > 0)
	{
		if (strncmp(num, "000", 3) != 0)
		{
			write(1, " ", 1);
			write(1, search(head, make_10_power(len, powers)),
				ft_strlen(search(head, make_10_power(len, powers))));
		}
		write_rec(num + part_len, len, head, 0);
	}
}

char	*make_10_power(int len, char *result)
{	
	int	index;

	result[0] = '1';
	index = 1;
	while (index <= len)
	{
		result[index] = '0';
		index++;
	}
	result[index] = '\0';
	return (result);
}
