/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:30:47 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 19:30:48 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	c;
	long	exnbr;

	exnbr = (long)nbr;
	if (exnbr < 0)
	{
		write(1, "-", 1);
		exnbr *= -1;
	}
	if (exnbr < 10)
	{
		c = exnbr + '0';
		write(1, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr((int)(exnbr / 10));
		c = exnbr % 10 + '0';
		write(1, &c, 1);
		return ;
	}
}
