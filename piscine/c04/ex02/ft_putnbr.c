/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:07:48 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 17:07:50 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_int(int n)
{
	int		count;
	int		fixcount;
	char	str[10];
	char	revstr[10];

	count = 0;
	while (n > 0)
	{
		str[count] = n % 10 + '0';
		n = n / 10;
		count++;
	}
	fixcount = count;
	while (count > 0)
	{
		revstr[fixcount - count] = str[count - 1];
		count--;
	}
	write(1, &revstr, fixcount);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb > 0)
		write_int (nb);
	else
	{
		write (1, "-", 1);
		write_int (-1 * nb);
	}
}
