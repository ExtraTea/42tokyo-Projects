/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:07:29 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 11:07:30 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftutil.h"

int	val_row_left(int **nums, int left, int dim, int depth)
{
	int	leftcount;
	int	currentleft;
	int	index;

	leftcount = 1;
	currentleft = nums[depth][0];
	index = 1;
	while (index < dim)
	{
		if (currentleft < nums[depth][index])
		{
			currentleft = nums[depth][index];
			leftcount++;
		}
		index++;
	}
	if (left == leftcount)
		return (1);
	else
		return (0);
}

int	val_row_right(int **nums, int right, int dim, int depth)
{
	int	rightcount;
	int	currentright;
	int	index;

	rightcount = 1;
	currentright = nums[depth][dim - 1];
	index = dim - 2;
	while (index >= 0)
	{
		if (currentright < nums[depth][index])
		{
			currentright = nums[depth][index];
			rightcount++;
		}
		index--;
	}
	if (right == rightcount)
		return (1);
	else
		return (0);
}

int	validate_rows(t_RowValidationData *data)
{
	int	validleft;
	int	validright;

	validleft = val_row_left(data -> nums,
			data -> left, data -> dim, data -> depth);
	validright = val_row_right(data -> nums,
			data -> right, data -> dim, data -> depth);
	if (validleft && validleft)
		return (1);
	else
		return (0);
}

int	check_column_for_unique(int **array, int rows, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < col)
		{
			if (array[i][j] == array[i][col])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	**r_co(int **array, int size, int n, int *newColumn)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i][n] = newColumn[i];
		i++;
	}
	return (array);
}
