/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:10:19 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 21:03:56 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi_bonus.h"

int	is_valid_arg(int ac, char **av)
{
	return (is_all_num(ac, av) * is_all_plus_int(ac, av));
}

int	is_all_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] < '0' || '9' < av[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_all_plus_int(int ac, char **av)
{
	long	num;
	int		i;

	i = 1;
	while (i < ac)
	{
		num = ft_atol(av[i]);
		if (num <= 0)
			return (0);
		if (num < (long)INT_MIN || (long)INT_MAX < num)
			return (0);
		i++;
	}
	return (1);
}