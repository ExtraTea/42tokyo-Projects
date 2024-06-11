/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:42:01 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 21:46:42 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int				start;
	int				end;
	int				mid;
	long long int	square;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	start = 0;
	end = nb;
	while (end - start >= 0)
	{
		mid = (start + end) / 2;
		square = (long long)mid * (long long)mid;
		if (square == nb)
			return (mid);
		else if (square > nb)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (end);
}

int	ft_is_prime(int nb)
{
	int	index;
	int	sqrtnum;

	if (nb < 2)
		return (0);
	index = 2;
	sqrtnum = ft_sqrt(nb);
	while (index <= sqrtnum)
	{
		if ((nb % index++) == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
