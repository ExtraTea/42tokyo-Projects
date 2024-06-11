/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:26 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:59 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_llabs(long long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putllnbr(long long n, char first, char plmi, int suf_zero)
{
	char	c;

	if (n < 0)
		write(1, "-", 1);
	else if (first)
	{
		if (plmi == 1)
			write(1, " ", 1);
		else if (plmi >= 2)
			write(1, "+", 1);
	}
	while (suf_zero-- > 0)
		ft_putchar_fd('0', 1);
	if (-9 <= n && n <= 9)
		write(1, " ", 0);
	else
		ft_putllnbr(ft_llabs(n / 10), 0, 0, 0);
	c = '0' + ft_llabs(n % 10);
	write(1, &c, 1);
	return ;
}

void	ft_putllunbr(unsigned long long n, char first, char plmi, int suf_zero)
{
	char	c;

	if (first)
	{
		if (plmi == 1)
			write(1, " ", 1);
		else if (plmi >= 2)
			write(1, "+", 1);
	}
	while (suf_zero-- > 0)
		ft_putchar_fd('0', 1);
	if (n > 9)
		ft_putllunbr(n / 10, 0, 0, 0);
	c = '0' + n % 10;
	write(1, &c, 1);
	return ;
}
