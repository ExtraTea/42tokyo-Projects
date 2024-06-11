/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:50:56 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 21:35:23 by dtakamat         ###   ########.fr       */
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
	return (0);
}
