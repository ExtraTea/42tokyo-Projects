/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:11:07 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 12:18:22 by dtakamat         ###   ########.fr       */
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
		if (base[len] == '-' || base[len] == '+')
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

void	ft_putnbr_vardig(long int nbr, long int digit, char *base)
{
	if (nbr >= digit)
	{
		ft_putnbr_vardig(nbr / digit, digit, base);
	}
	write(1, &base[nbr % digit], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	len;
	long int	ex_nbr;

	if (is_error(base))
		return ;
	len = 0;
	while (base[len] != '\0')
		len++;
	ex_nbr = (long int)nbr;
	if (ex_nbr < 0)
	{
		ex_nbr *= -1;
		write(1, "-", 1);
	}
	ft_putnbr_vardig(ex_nbr, len, base);
}
