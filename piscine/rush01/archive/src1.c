/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 06:13:34 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 06:13:36 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ftutil.h"

int	factorial(int n)
{
	int	result;
	int	i;

	result = 1;
	i = 2;
	while (i <= n)
		result *= i++;
	return (result);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	permute_util(t_PermuteData *data)
{
	int				i;
	t_PermuteData	ndewdata;

	if (data -> l == data -> r)
	{
		i = -1;
		while (++i <= data -> r)
			data -> result[*data -> index][i] = data -> a[i];
		(*data -> index)++;
	}
	else
	{
		i = data -> l;
		while (i <= data -> r)
		{
			swap(&data -> a[data -> l], &data -> a[i]);
			ndewdata = *data;
			ndewdata.l = data->l + 1;
			permute_util(&ndewdata);
			swap(&data->a[data->l], &data->a[i]);
			i++;
		}
	}
}

int	**permute(int n, int *return_size)
{
	int				**result;
	int				i;
	int				*a;
	t_PermuteData	data;

	*return_size = factorial(n);
	result = malloc(*return_size * sizeof(int *));
	i = 0;
	while (i < *return_size)
		result[i++] = malloc(n * sizeof(int));
	a = malloc(n * sizeof(int));
	i = 0;
	while (i < n)
	{
		a[i] = i + 1;
		i++;
	}
	i = 0;
	data = (t_PermuteData){a, result, &i, 0, n - 1};
	permute_util(&data);
	free (a);
	return (result);
}
