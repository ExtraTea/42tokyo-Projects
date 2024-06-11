/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 06:17:40 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 06:17:43 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftutil.h"

int		factorial(int n);
void	swap(int *x, int *y);
void	permute_util(t_PermuteData *data);
int		**permute(int n, int *return_size);
int		val_col(int *nums, int top, int bottom, int dim);

void	swap2(int **a, int **b)
{
	int	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int **array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high][0];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array[j][0] > pivot)
		{
			i++;
			swap2(&array[i], &array[j]);
		}
		j++;
	}
	swap2(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int **array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

int	***make_permutation(int dim, int *top, int *bottom)
{
	int	return_size;
	int	***result;
	int	**first_permutation_set;
	int	i[3];

	i[0] = 0;
	result = (int ***)malloc(dim * sizeof (int **));
	first_permutation_set = permute(dim, &return_size);
	while (i[0] < dim)
	{
		result[i[0]] = (int **)malloc(return_size * sizeof (int *));
		i[1] = 0;
		while (i[1] < return_size)
		{
			result[i[0]][i[1]] = (int *)malloc(dim * sizeof (int));
			i[2] = -1;
			while (++i[2] < dim)
				result[i[0]][i[1]][i[2]] = first_permutation_set[i[1]][i[2]];
			if (!val_col(result[i[0]][i[1]++], top[i[0]], bottom[i[0]], dim))
				result[i[0]][i[1] - 1][0] = -1;
		}
		quick_sort(result[i[0]++], 0, return_size - 1);
	}
	return (result);
}

void	print_2darray(int **array, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = array[i][j] + '0';
			write(1, &c, 1);
			if(j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
